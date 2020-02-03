//
#include "img.h"
#include "util.h" 

PIX*
imginit(char* filename)
{
    PIX* img = NULL;
    
    if((img = pixRead(filename)) == NULL)
        return NULL;

    return img;
}
