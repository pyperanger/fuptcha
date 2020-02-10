#include "tess.h"
#include "fuptcha.h"
#include "util.h"
#include <stdio.h>
#include <tesseract/capi.h>

void
tess_free(TessBaseAPI* handle)
{
  TessBaseAPIEnd(handle);
  TessBaseAPIDelete(handle);
}

void
tess_list_langs(struct Fuptcha* w)
{
  gmsg("Listing avaiables languages in tessdata directory");
  int i;
  for (i = 0; w->langs[i] != NULL; i++) {
    lmsg(i+1, w->langs[i]);
  }
  puts(""); // format text
}

int
/* Verify avaiable languages in the tessdata directory*/
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
