#include "fuptcha.h"
#include "img.h"
#include "pargs.h"
#include "tess.h"
#include "util.h"
#include "score.h"
#include <stdio.h>
#include <string.h>

int
main(int argc, char* argv[])
{
  struct Fuptcha fuptcha;

  pargs(argc, argv, &fuptcha);

  gmsg("FUPTCHA - github.com/pyperanger/fuptcha - Authors: @pyperanger @growlnx");
  gmsg("Initalizing");

  /* init checks */
  if (img_init(&fuptcha) != 0)
    die("Error loading image"); 

  gmsg("Image loaded - OK");

  if (tess_chk_len(&fuptcha) != 0)
    die("Error Tesseract init");

  score_pt_make(&fuptcha);  

  /* deallocate fuptcha vars */
  pixDestroy(&fuptcha.img);

  return 0;
}
