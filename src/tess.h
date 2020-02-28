#pragma once

#include "fuptcha.h"
#include "util.h"
#include <tesseract/capi.h>

void
tess_list_langs(struct Fuptcha* f);
int
tess_chk_len(struct Fuptcha* f);
void
tess_free(TessBaseAPI* handle);
int
tess_run(struct Fuptcha* f);
