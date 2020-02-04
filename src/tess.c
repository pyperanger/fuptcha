#include "tess.h"
#include "fuptcha.h"
#include "util.h"
#include <tesseract/capi.h>

void
tesslistlangs(struct WORD *w)
{
    int i;
    for(i = 0; w->langs[i] != NULL ; i++)
        printf("%s\n", w->langs[i]);
}

int
tesschklen(struct WORD *w)
{
    TessBaseAPI* handle = NULL;
    handle = TessBaseAPICreate();
    if (TessBaseAPIInit3(handle, NULL, NULL) != true)
        return false;

    w->langs = TessBaseAPIGetAvailableLanguagesAsVector(handle);
    tesslistlangs(w);

    TessBaseAPIEnd(handle);
    TessBaseAPIDelete(handle);

    return true;
}
