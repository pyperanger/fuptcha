#include <stdlib.h>

typedef struct _WORD
{
    char    *text;
    char    *filename;
    char    **words;
    unsigned int     lentext;
    unsigned int     fpoint;
    unsigned int     mpoint;
    unsigned int     ipoint;
    unsigned int     level;
} WORD;