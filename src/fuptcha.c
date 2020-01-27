#include "fuptcha.h"
#include "pargs.h"
#include <stdio.h>



int 
main(int argc, char* argv[])
{
    struct WORD woptcha;

   if(pargs(argc, argv, &woptcha) != 0)
       puts("vai da merda viado");
   
        printf("%s\t%s\t%d\t%d\t%d\t%d", woptcha.text,woptcha.filename, woptcha.level, woptcha.verbose, woptcha.nrank, woptcha.nthread);   


    return 0;
}

