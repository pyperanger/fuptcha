/* Variadic Macros soon */
#pragma once

#include <stdio.h>


#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define VERB "\x1b[35m"
#define YELL "\x1b[33m"
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
#define lmsg(INT, STR)                                                         \
  {                                                                            \
    printf("%s%i)%s %s  ", YELL, INT, RESET, STR);                             \
  }
#define gmsg_tll(INT, STR) { printf("%s->%s %i %s\n", GREEN, RESET, INT, STR);}

#define die(STR)                                                               \
  {                                                                            \
    fprintf(stderr, "%s[ FATAL ERROR ] %s %s\n", RED, STR, RESET);             \
    exit(1);                                                                   \
  }
