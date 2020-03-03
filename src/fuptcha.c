#include "fuptcha.h"
#include "img.h"
#include "pargs.h"
#include "score.h"
#include "tess.h"
#include "util.h"
#include <stdio.h>
#include <string.h>

int
fuptcha_free(struct Fuptcha* f){
    free(f->rank);
    free(f->langs);
    pixDestroy(&f->img);     
    return 0;
}

int
main(int argc, char* argv[])
{
  struct Fuptcha fuptcha;
  signal(SIGINT, handle_sigint);

  pargs(argc, argv, &fuptcha);

  gmsg(
    "FUPTCHA - github.com/pyperanger/fuptcha - Authors: @pyperanger @growlnx");
  gmsg("Initalizing");

  /* init checks */
  if (img_init(&fuptcha) != 0)
    die("Error loading image");

  gmsg("Image loaded - OK");

  if (tess_chk_len(&fuptcha) != 0)
    die("Error Tesseract init");

  if (score_pt_make(&fuptcha) != 0)
    die("Score point problem");

  if(score_rankbuild(&fuptcha) != 0)
      die("ranklloc");

  /* running */
  tess_run(&fuptcha);

  fuptcha_free(&fuptcha);

  return 0;
}
