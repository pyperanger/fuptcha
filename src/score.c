#include "score.h"
#include "fuptcha.h"
#include "util.h"
#include <string.h>

int
score_point(char* text, struct Fuptcha* f)
{
  size_t len = strnlen(f->text, TEXT_LIMIT); // remove for performance
  int score = 0;
  if (strncmp(text, f->text, len) == 0)
    return 100;
  // working

  for(size_t i = 0 ; i < len; i++){
    if(text[i] == f->text[i]) score = score + f->fpoint;
    else score = score + f->mpoint;
  }

  return score;
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

  // if (score_rankbuild(f) != 0)
  //  die("ranklloc");

  return 0;
}
