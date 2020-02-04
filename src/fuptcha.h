#pragma once

#include <leptonica/allheaders.h>
#include <stdlib.h>

struct WORD
{
  char* text;
  char* filename;
  PIX* img;
  char** langs;
  char** words; // died soon
  unsigned int lentext;
  unsigned int fpoint;
  unsigned int mpoint;
  unsigned int ipoint;
  unsigned int level;
  unsigned int verbose;
  unsigned int nrank;
  unsigned int nthread;
};
