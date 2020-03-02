#include "score.h"
#include "fuptcha.h"
#include "util.h"
#include <string.h>

int
/* define score points values ; int because future features*/
score_pt_make(struct Fuptcha* f)
{
  f->lentext = strlen(f->text); //   CWE-126
  f->fpoint = 100 / f->lentext;
  f->mpoint = f->fpoint / f->lentext;
  f->ipoint = f->mpoint / 2;

  if (f->verbose) {
    vmsg("Full point: %d", f->fpoint);
    vmsg("Medium point: %d", f->mpoint);
    vmsg("Lower point: %d", f->ipoint);
  }

  return 0;
}
