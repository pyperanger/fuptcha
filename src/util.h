#pragma once

#include <stdio.h>

#define true 0
#define false 1

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define VERB "\x1b[35m"
#define RESET "\x1b[0m"

#define gmsg(STR)                                                              \
  {                                                                            \
    printf("%s->%s %s\n", GREEN, RESET, STR);                                  \
  }
#define rmsg(STR)                                                              \
  {                                                                            \
    printf("%s->%s %s\n", RED, RESET, STR);                                    \
  }
#define vmsg(STR)                                                              \
  {                                                                            \
    printf("%s[VERBOSE] %s%s\n", VERB, STR, RESET);                            \
  }

#define die(STR)                                                               \
  {                                                                            \
    fprintf(stderr, "%s[ FATAL ERROR ] %s %s\n", RED, STR, RESET);             \
    exit(1);                                                                   \
  }
