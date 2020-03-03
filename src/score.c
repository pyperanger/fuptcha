#include "score.h"
#include "fuptcha.h"
#include "util.h"

int
/* define score points values ; int because future features*/
score_pt_make(struct Fuptcha* f)
{
  size_t lentext = strnlen(f->text, sizeof(f->text));
  f->fpoint = 100 / lentext;
  f->mpoint = f->fpoint / lentext;
  f->ipoint = f->mpoint / 2;

  if (f->verbose) {
    vmsg("Full point: %d", f->fpoint);
    vmsg("Medium point: %d", f->mpoint);
    vmsg("Lower point: %d", f->ipoint);
  }

  if(!score_rankbuild(f))
      return 1;

  return 0;
}

int
/* freeded by futpcha_free */
score_rankbuild(struct Fuptcha* f)
{
    if(f->lenlangs == 0)
        // if something wrong in the middle way
        return 1;

    f->rank = (int**)malloc(f->lenlangs*sizeof(int*));

    for(register int i = 0; i < f->lenlangs; i++){
        f->rank[i] = malloc(2*sizeof(int));
        f->rank[i][1] = 0;
    }

    return 0;
}
