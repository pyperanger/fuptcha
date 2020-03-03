/* Variadic Macros soon */
#pragma once

#include <signal.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define VERB "\x1b[35m"
#define YELL "\x1b[33m"
#define RESET "\x1b[0m"

#define gmsg(fmt, ...)                                                         \
  {                                                                            \
    gmsgc;                                                                     \
    fprintf(stdout, fmt, ##__VA_ARGS__);                                       \
    puts("");                                                                  \
  }

#define vmsg(fmt, ...)                                                         \
  {                                                                            \
    vmsgc;                                                                     \
    fprintf(stdout, fmt, ##__VA_ARGS__);                                       \
    puts("");                                                                  \
  }

#define gmsgc                                                                  \
  {                                                                            \
    printf("%s->%s ", GREEN, RESET);                                           \
  }

#define rmsg(STR)                                                              \
  {                                                                            \
    printf("%s->%s %s\n", RED, RESET, STR);                                    \
  }
#define vmsgc                                                                  \
  {                                                                            \
    printf("%s[VERBOSE]%s ", VERB, RESET);                                     \
  }
#define lmsg(INT, STR)                                                         \
  {                                                                            \
    printf("%s%i)%s %s  ", YELL, INT, RESET, STR);                             \
  }
#define die(STR)                                                               \
  {                                                                            \
    fprintf(stderr, "%s[ FATAL ERROR ] %s %s\n", RED, STR, RESET);             \
    exit(1);                                                                   \
  }

void handle_sigint();
size_t strnlen(const char * s, size_t len);
