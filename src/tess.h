#pragma once

#include "fuptcha.h"
#include "util.h"
#include <tesseract/capi.h>

void
tess_list_langs(struct Fuptcha* w);
int
tess_chk_len(struct Fuptcha* w);
void
tess_free(TessBaseAPI* handle);
