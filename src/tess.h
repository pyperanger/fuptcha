#pragma once

#include "fuptcha.h"
#include "util.h"
#include <tesseract/capi.h>

void
tesslistlangs(struct Fuptcha* w);
int
tesschklen(struct Fuptcha* w);
void
tessfree(TessBaseAPI* handle);
