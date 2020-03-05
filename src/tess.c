#include "tess.h"
#include "fuptcha.h"
#include "util.h"
#include <stdio.h>
#include <pthread.h>
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

/*
void*
tess_nthread(void* agent )
{
  TessBaseAPI* handle = NULL;
  int c = 0;
  char* textrecon;
  handle = TessBaseAPICreate();

  if (!fuptcha->verbose)
    TessBaseAPISetVariable(handle, "debug_file", "/dev/null"); // Avoid DPI Errors
 
  while(fuptcha->langs[c] != NULL){
    if (TessBaseAPIInit3(handle, NULL, fuptcha->langs[c]) != 0)
      vmsg("Error TessBaseAPIInit3: %s", fuptcha->langs[c]);
  
    TessBaseAPISetImage2(handle, fuptcha->img);

    if (TessBaseAPIRecognize(handle, NULL) != 0)
      vmsg("Error TessBaseAPIRecongnize: %s", fuptcha->langs[c]);
   
    if ((textrecon = TessBaseAPIGetUTF8Text(handle)) == NULL) 
      vmsg("Error TessBaseAPIGetUTF8Text: %s", fuptcha->langs[c]);

    printf("recon text: %s", textrecon);

    c++;
  }

  tess_free(handle);

  return 0;
}
 */

void*
tess_nthread(void* agent)
{
  
  return NULL;
}

int
/* split langs values for threads and execute each one*/
tess_run(struct Fuptcha* fuptcha)
{
   struct tess_agenthread agents[fuptcha->nthread];
  int i = 0, c = 0;
  int split_value = fuptcha->lenlangs / fuptcha->nthread;
  int split_rest = fuptcha->lenlangs % fuptcha->nthread;

  for(;i < fuptcha->nthread ; i++){
    agents[i].f = fuptcha;
    for(;;){
      agents[i].start = 1;
      agents[i].end = 1;
    }
  }

  i = 0;
  for(;i < fuptcha->lenlangs; i++){
      
  }

  return 0;
}
