#include "fuptcha.h"
#include "img.h"
#include "pargs.h"
#include "tess.h"
#include "util.h"
#include <stdio.h>

int
main(int argc, char* argv[])
{
  struct Fuptcha fuptcha;

  pargs(argc, argv, &fuptcha);

  gmsg("FUPTCHA - github.com/pyperanger/fuptcha");
  gmsg("Initalizing");

  if (fuptcha.verbose)
    vmsg("Args OK");

  if (imginit(&fuptcha) != 0)
    die("Error loading image"); // pix already print debug/verbose errors

  gmsg("Image loaded - OK");

  if (tesschklen(&fuptcha) != 0)
    die("Error Tesseract init");

  pixDestroy(&fuptcha.img);

  return 0;
}
