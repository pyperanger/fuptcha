#include "fuptcha.h"
#include "pargs.h"
#include <stdio.h>



int 
main(int argc, char* argv[])
{
    struct WORD woptcha;

  pargs(argc, argv, &woptcha);
   
   printf("%s\t%s\t%d\t%d\t%d\t%d", woptcha.text,woptcha.filename, woptcha.level, woptcha.verbose, woptcha.nrank, woptcha.nthread);   


    return 0;
}

