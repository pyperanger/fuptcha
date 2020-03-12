#include "tess.h"
#include "fuptcha.h"
#include "score.h"
#include "util.h"
#include <pthread.h>
#include <stdio.h>
#include <tesseract/capi.h>

void
/* deallocate tessract vars */
tess_free(TessBaseAPI* handle)
{
  TessBaseAPIEnd(handle);
  TessBaseAPIDelete(handle);
}

void
/* listing languages in /usr/include/tessbase  */
tess_list_langs(struct Fuptcha* f)
{
  if (f->verbose)
    vmsg("Listing avaiable languages in tessdata directory");

  int i;
  for (i = 0; f->langs[i] != NULL; i++) {
    if (f->verbose)
      lmsg(i + 1, f->langs[i]);
  }
  f->lenlangs = i;
  gmsg("%d Avaiable languages in default path", i);
}

int
/* Verifiy avaiable languages in the tessdata directory */
tess_chk_len(struct Fuptcha* w)
{
  TessBaseAPI* handle = NULL;
  handle = TessBaseAPICreate();
  if (TessBaseAPIInit3(handle, NULL, NULL) == 0) {
    w->langs = TessBaseAPIGetAvailableLanguagesAsVector(handle);
    tess_list_langs(w);
    tess_free(handle);
    gmsg("Tesseract init - OK");
    return 0;
  }

  vmsg("TessBaseAPIInit3 Error");
  tess_free(handle);

  return 1;
}

void*
tess_nthread(void* agent)
{
  struct tess_agenthread* tess_agent = (struct tess_agenthread*)agent;
  TessBaseAPI* handle = NULL;
  // size_t i = 0;
  char* textrecon;
  handle = TessBaseAPICreate();

  if (!tess_agent->f->verbose)
    TessBaseAPISetVariable(
      handle, "debug_file", "/dev/null"); // Avoid DPI Errors

  while (tess_agent->start < tess_agent->end) {
    if (TessBaseAPIInit3(
          handle, NULL, tess_agent->f->langs[tess_agent->start]) != 0)
      vmsg("Error TessBaseAPIInit3: %s",
           tess_agent->f->langs[tess_agent->start]);

    TessBaseAPISetImage2(handle, tess_agent->f->img);
    if (TessBaseAPIRecognize(handle, NULL) != 0)
      vmsg("Error TessBaseAPIRecongnize: %s",
           tess_agent->f->langs[tess_agent->start]);

    if ((textrecon = TessBaseAPIGetUTF8Text(handle)) == NULL)
      vmsg("Error TessBaseAPIGetUTF8Text: %s",
           tess_agent->f->langs[tess_agent->start]);

    tess_agent->f->key_value[tess_agent->start].key = tess_agent->start;

    if ((tess_agent->f->key_value[tess_agent->start].value =
           score_point(textrecon, tess_agent->f)) == 100)
      printf("%s~ %s found the text -> %s%s",
             GREEN,
             tess_agent->f->langs[tess_agent->start],
             textrecon,
             RESET);

    tess_agent->f->barload++;
    tess_agent->start++;
  }

  tess_free(handle);
  return NULL;
}

int
tess_make_keyvalue(struct Fuptcha* f)
{
  if (f == NULL)
    return -1;

  f->key_value =
    (struct Key_value*)malloc(sizeof(struct Key_value) * f->lenlangs);

  return 0;
}
int
/* split langs values for threads and execute each one*/
tess_run(struct Fuptcha* fuptcha)
{
  if (fuptcha == NULL)
    return 1;

  if (fuptcha->nthread > fuptcha->lenlangs)
    fuptcha->nthread = fuptcha->lenlangs;

  if (tess_make_keyvalue(fuptcha) == -1)
    return 1;

  struct tess_agenthread agents[fuptcha->nthread];

  int i = 0, c = 0;
  int split_value = fuptcha->lenlangs / fuptcha->nthread;
  int split_rest = fuptcha->lenlangs % fuptcha->nthread;

  for (; i < fuptcha->nthread; i++) {
    agents[i].f = fuptcha;
    agents[i].start = c;
    if (split_rest > 0) {
      c++;
      split_rest--;
    }
    agents[i].end = c + split_value - 1;

    c = c + split_value;
  }
  pthread_t thread_agent[fuptcha->nthread];

  gmsg("Threads: %d", fuptcha->nthread);
  gmsg("Initializing\n");

  for (i = 0; i < fuptcha->nthread; i++)
    pthread_create(&thread_agent[i], NULL, tess_nthread, &agents[i]);

  fuptcha->barload = 1;
  while (fuptcha->barload < fuptcha->lenlangs) {
    printf(
      "%s~ (   %d/%d)%s\r", YELL, fuptcha->barload, fuptcha->lenlangs, RESET);
    fflush(stdout);
  }

  for (i = 0; i < fuptcha->nthread; i++)
    pthread_join(thread_agent[i], NULL);

  return 0;
}
