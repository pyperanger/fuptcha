#include "tess.h"
#include "fuptcha.h"
#include "util.h"
#include <stdio.h>
#include <tesseract/capi.h>

void
tessfree(TessBaseAPI* handle)
{
  TessBaseAPIEnd(handle);
  TessBaseAPIDelete(handle);
}

void
tesslistlangs(struct Fuptcha* w)
{
  gmsg("Listing avaiables languages in tessdata directory");
  int i;
  for (i = 0; w->langs[i] != NULL; i++) {
    lmsg(i, w->langs[i]);
  }
  puts(""); // format text
}

int
tesschklen(struct Fuptcha* w)
{
  TessBaseAPI* handle = NULL;
  handle = TessBaseAPICreate();
  if (TessBaseAPIInit3(handle, NULL, NULL) == 0) {
    w->langs = TessBaseAPIGetAvailableLanguagesAsVector(handle);
    tesslistlangs(w);
    tessfree(handle);
    gmsg("Tesseract init - OK");
    return 0;
  }

  vmsg("TessBaseAPIInit3 Error");
  tessfree(handle);

  return 1;
}
