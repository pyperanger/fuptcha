#include "pargs.h"
#include "fuptcha.h"
#include "score.h"
#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
help()
{
  printf("Auxiliary CAPTCHA fuzzer recon tool v1.0"
         "\n\nUsage: fuptcha -f image.png -s \"FPGA2\"\n\n"
         "-f FILE  \t- File path\n"
         "-s TEXT  \t- Text string to find in image\n"
         "-l LEVEL \t- Set the search level:\n"
           "\t\t\t1 - Normal (default)\n"
           "\t\t\t2 - High\n"
           "\t\t\t3 - Insane\n"
         "-r N     \t - Set the number output of languages score.\n"
         "-t N     \t - Set the number of threads (default N = 1).\n"
         "-v       \t - Enable verbose mode\n"
         "-h       \t - Display this information.\n"
       "\nHave found a Bug? Nice! Report here: https://github.com/pyperanger/fuptcha/issues\n");
  exit(1);
}

int
atolol(char* w)
{
  int r;
  if((r = strtol(w, NULL, 10)) == 0L)
    return 1;

  return r;
}

void
pargs(int argc, char* argv[], struct Fuptcha* fuptcha)
{
  if (argc < 4) // minium file and textstring
    help();

  int opts = 0;
  fuptcha->verbose = 0;
  fuptcha->level = 1;
  fuptcha->nrank = 1;
  fuptcha->nthread = 1;

  while ((opts = getopt(argc, argv, "hvf:s:l:r:t:")) != -1) {
    switch (opts) {
      case 'h':
        help();
        break;
      case 'v': /* Verbose */
        fuptcha->verbose = 1;
        break;
      case 'f': /* Filename */
        if (access(optarg, F_OK) == -1) {
          printf("File not found\n");
          help();
        } else
          fuptcha->filename = optarg;
        break;
      case 's':                 /*  Text Search  */
        fuptcha->text = optarg; /* some BoF but fuck */
        break;
      case 'l': /*  Level  */
        fuptcha->level = atolol(optarg);
        break;
      case 't': /* Thread */
        fuptcha->nthread = atolol(optarg);
        break;
      case 'r': /* Rank */
        fuptcha->nrank = atolol(optarg);
        break;
      case '?':
        if (optopt == 's') {
          printf("-s need a argument\n");
        } else if (optopt == 'f') {
          printf("-f need a argument");
        }
        help();
    }
  }
}
