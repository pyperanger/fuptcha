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

  /* Parse Arguments  */
  pargs(argc, argv, &woptcha);

  gmsg("FUPTCHA - github.com/pyperanger/fuptcha");
  gmsg("Initalizing");

  if (woptcha.verbose)
    vmsg("Args OK");

  if (imginit(&woptcha))
    die("Error loading image");
  
  gmsg("Image loaded");

  //int lenlangs;

  if (tesschklen(&woptcha))
      die("Error Tesseract init");

  pixDestroy(&woptcha.img);

  return 0;
}
