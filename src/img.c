/*
 *  +Img effect features
 *  +Img resize
 *  +Img [..]
 */
#include "img.h"
#include "fuptcha.h"
#include "util.h"

int
imginit(struct WORD* w)
{
  if ((w->img = pixRead(w->filename)) == NULL) {
    vmsg("pixRead Error");
    return false;
  }

  return true;
}
