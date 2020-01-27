/*
 * >>  no getopt_long in this release <<  
 *  -f = imagephoto - must have
 *  -s = text string - must have
 *  -l = level search - 1 deafult
 *  -v = verbose 
 *  -r [2-N] - show 1-N rank place ; default only 100% match 
 *  -t = thread(in implementation fase) -   1 default 
 *  -h = help // banner message
 */

#include "pargs.h"
#include "fuptcha.h"
#include <getopt.h>
#include <unistd.h>

int
pargs(int argc, char *argv[], struct WORD *woptcha)
{
    if(argc < 3) // minium file and textstring
        return 1;

    int opts = 0, ret = 0;
    woptcha->verbose = 1;

    while((opts = getopt(argc, argv, "hvf:s:l:r:t:")) != -1) {
        switch(opts) {
            case 'h':
                ret = 1;
            break;
            case 'v':
                woptcha->verbose = 0;
            break;
            case 'f':
                if(access(optarg, F_OK) == -1)
                    ret = 1;
                else
                    woptcha->filename = optarg;    
            break;
            case 's':
                woptcha->text = optarg; // some BoF but fuck
            break;
            case 'l':
                if (atoi(optarg) > 0)
                    woptcha->level = atoi(optarg);
                else
                    ret = 1;
            break;
            case 't':
                if (atoi(optarg) > 0)
                    woptcha->nthread = atoi(optarg);
                else
                    ret = 1;
            break;
            case 'r':
                if (atoi(optarg) > 0)
                    woptcha->nrank = atoi(optarg);
                else
                    ret = 1;
            break;
            case '?':
                if(optopt == 'l')
                    woptcha->level = 1;
                else if(optopt == 't')
                    woptcha->nthread = 1;
                else if(optopt == 'r')
                    woptcha->nrank = 1;
        }
    }
   
    return ret;
}
