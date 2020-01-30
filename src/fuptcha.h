#pragma once

#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

struct WORD
{
    char    *text;
    char    *filename;
    char    **words;
    unsigned int    lentext;
    unsigned int    fpoint;
    unsigned int    mpoint;
    unsigned int    ipoint;
    unsigned int    level;
    unsigned int    verbose;
    unsigned int    nrank;
    unsigned int    nthread;
};
