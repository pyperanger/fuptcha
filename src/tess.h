#pragma once

#include "fuptcha.h"
#include "util.h"
#include <tesseract/capi.h> 

void tesslistlangs(struct WORD *w);
int tesschklen(struct WORD *w);
void tessfree(TessBaseAPI* handle);
