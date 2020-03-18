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
int
tess_baseinit(TessBaseAPI* handle, struct Fuptcha* f);
void*
tess_nthread(void* agentarg);
int
tess_make_keyvalue(struct Fuptcha* f);

struct tess_agenthread
/* Struct responsible for organize the offset of each thread */
{
  struct Fuptcha* f;
  unsigned int start;
  unsigned int end;
};
