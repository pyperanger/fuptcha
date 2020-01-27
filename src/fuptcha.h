#pragma once

#include <stdlib.h>

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
