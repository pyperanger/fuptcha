#include "fuptcha.h"
#include "pargs.h"
#include "img.h"
#include "util.h"
#include <stdio.h>

int
main(int argc, char* argv[])
{
    struct WORD woptcha;
    
    /* Parse Arguments  */
    pargs(argc, argv, &woptcha);
    
    gmsg("FUPTCHA - github.com/pyperanger/fuptcha");

    if(woptcha.verbose)
        vmsg("Args OK - Now Check img");

    if (imginit(&woptcha))
        die("Error loading image");


    return 0;
}

