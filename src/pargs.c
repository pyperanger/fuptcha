#include "pargs.h"
#include "fuptcha.h"
#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>


void
help()
{   
    printf("\n"
"  __             _       _           \n"
" / _|           | |     | |          \n"
"| |_ _   _ _ __ | |_ ___| |__   __ _ \n"
"|  _| | | | '_ \\| __/ __| '_ \\ / _` |\n"
"| | | |_| | |_) | || (__| | | | (_| |\n"
"|_|  \\__,_| .__/ \\__\\___|_| |_|\\__,_|\n"
"           | |                        \n"
"           |_| \n");
    printf("Auxiliary Captcha Recon Tool v0.1\n\n"
           "-f\t- Filename path\n"
           "-s\t- Text string to find in image\n"
           "-l\t- Search level:\n\t1 - Normal\n\t2 - High\n\t3 - Insane\n"
           "-r\t- Number output of languages score\n"
           "-t\t- Number of threads\n"
           "-v\t- Verbose\n"
           "-h\t- Help Box(This Message)\n");

    exit(EXIT_FAILURE);
}

void
pargs(int argc, char *argv[], struct WORD *woptcha)
{
    if(argc < 4) // minium file and textstring
        help();

    int opts = 0;
    woptcha->verbose = 1;
    woptcha->level = 1;
    woptcha->nrank = 1;
    woptcha->nthread = 1;

    while((opts = getopt(argc, argv, "hvf:s:l:r:t:")) != -1) {
        switch(opts) {
            case 'h':
                help();
            break;
            case 'v': /* Verbose */
                woptcha->verbose = 0;
            break;
            case 'f': /* Filename */
                if(access(optarg, F_OK) == -1)
                    help();
                else
                    woptcha->filename = optarg;    
            break;
            case 's': /*  Text Search  */
                woptcha->text = optarg; /* some BoF but fuck */
            break;
            case 'l': /*  Level  */
                woptcha->level = atoi(optarg);
            break;
            case 't': /* Thread */
                woptcha->nthread = atoi(optarg);
            break;
            case 'r': /* Rank */
                woptcha->nrank = atoi(optarg);
            break;
            case '?':
                if (optopt == 'f')
                    help();
                else if (optopt == 's')
                    help();
            default: /* '?' */
                help();
        }
    }
}
