#include "score.h"
#include "fuptcha.h"
#include "util.h"
#include <string.h>

int
score_point(char* text, struct Fuptcha* f)
{
  size_t len = strnlen(f->text, TEXT_LIMIT); // remove for performance
  printf("recon: %s - parsing:%s\n", text, f->text);
  if (strncmp(text, f->text, len) == 0)
    return 100;



  // working

  return 0;
}
int
/* define score points values */
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

  if (score_rankbuild(f) != 0)
    die("ranklloc");

  return 0;
}

int
/* freeded by futpcha_free */
score_rankbuild(struct Fuptcha* f)
{
  if (f->lenlangs != 0) {
    f->rank = (int**)malloc(f->lenlangs * sizeof(int*));

    for (register int i = 0; i < f->lenlangs; i++) {
      f->rank[i] = malloc(2 * sizeof(int));
      f->rank[i][1] = 0;
    }
    return 0;
  }
  return 1;
}
