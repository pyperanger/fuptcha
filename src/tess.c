#include "tess.h"
#include "fuptcha.h"
#include "util.h"
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
  if(f->verbose)
      vmsg("Listing avaiable languages in tessdata directory");

  int i;
  for (i = 0; f->langs[i] != NULL; i++) {
    if(f->verbose)
      lmsg(i+1, f->langs[i]);
  }

  gmsg_tll(i,"Avaiable languages in default path"); 
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
