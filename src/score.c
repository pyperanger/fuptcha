#include "score.h"
#include "fuptcha.h"
#include "util.h"
#include <ctype.h>
#include <string.h>

int
score_point(char* text, struct Fuptcha* f)
{
  size_t len = strnlen(f->text, TEXT_LIMIT); // remove for performance
  size_t relen = strnlen(text, TEXT_LIMIT);
  int score = 0;
  size_t i, j;
  if (strncmp(text, f->text, len) == 0)
    return 100;

  /* Default Level [1] */
  for (i = 0; i < len; i++) {
    if (text[i] == toupper(f->text[i]))
      score = score + f->fpoint;
    else if (text[i] == tolower(f->text[i]))
      score = score + f->mpoint;
  }

  /* Level 2 */
  if (f->level > 1) {
    for (i = 0; i < relen; i++) {
      for (j = 0; j < len; j++) {
        if (text[i] == f->text[j])
          score = score + f->ipoint;
      }
    }
  }

  // working in anothers levels

  // if any kind of bug ou racecondition happen
  if (score > 100)
    score = 99;

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
