#pragma once
/* 
 *  img.* - responsable to create and manager all img features
 *  - in future we'll create features in code to resize and apply eeffects in photo
 *  to help in image recon.
 */

#include "fuptcha.h"
#include "util.h"
#include <leptonica/allheaders.h>


PIX* imginit(char* filename);
