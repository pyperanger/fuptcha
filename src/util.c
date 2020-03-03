/* future usage */
#include "util.h"


void
handle_sigint()
{
    die("SIGINT - Quiting program");
}

size_t
strnlen(const char * s, size_t len)
{
    size_t i = 0;
    for ( ; i < len && s[i] != '\0'; ++i);
    return i;
}
