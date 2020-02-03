#include "fuptcha.h"
#include "pargs.h"
#include "img.h"
#include <stdio.h>

int 
main(int argc, char* argv[])
{
    struct WORD woptcha;
    
    /* Parse Arguments  */
    pargs(argc, argv, &woptcha);
   
    if(woptcha.verbose)
        puts("[ VERBOSE ]  ARGUMENTS OK");
    
    PIX* img = NULL;
    if (imginit(&img))
        die();


    return 0;
}

