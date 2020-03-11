#pragma once

#include <leptonica/allheaders.h>
#include <stdlib.h>

#define TEXT_LIMIT 255

struct Key_value {
  unsigned int key;
  int value;
};

struct Fuptcha
{
  char* text;
  char* filename;
  PIX* img;
  char** langs;
  int** rank;
  int lenlangs;
  struct Key_value* key_value;
  unsigned int fpoint;
  unsigned int mpoint;
  unsigned int ipoint;
  unsigned int level;
  unsigned int verbose;
  unsigned int nrank;
  unsigned int nthread;
};

int
fuptcha_free(struct Fuptcha* f);
