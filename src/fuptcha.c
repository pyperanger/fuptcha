#include "fuptcha.h"
#include "img.h"
#include "pargs.h"
#include "util.h"
#include "tess.h"
#include <stdio.h>

int
main(int argc, char* argv[])
{
  struct WORD woptcha;

  pargs(argc, argv, &woptcha);

  gmsg("FUPTCHA - github.com/pyperanger/fuptcha");
  gmsg("Initalizing");

  if (woptcha.verbose)
    vmsg("Args OK");

  if (imginit(&woptcha) != 0)
    die("Error loading image"); // pix already print debug/verbose errors
  
  gmsg("Image loaded - OK");

  if (tesschklen(&woptcha) != 0)
      die("Error Tesseract init");
 


  pixDestroy(&woptcha.img);

  return 0;
}
