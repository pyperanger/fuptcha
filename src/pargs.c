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
#include <ctype.h>

int
pargs(int argc, char *argv[], struct WORD *woptcha)
{
    if(argc < 3) // minium file and textstring
        return 1;

    int opts = 0, ret = 0;
    woptcha->verbose = 1;
    woptcha->level = 1;
    woptcha->nrank = 1;
    woptcha->nthread = 1;

    while((opts = getopt(argc, argv, "hvf:s:l:r:t:")) != -1) {
        switch(opts) {
            case 'h':
                ret = 1;
            break;
            case 'v': /* Verbose */
                woptcha->verbose = 0;
            break;
            case 'f': /* Filename */
                if(access(optarg, F_OK) == -1)
                    ret = 1;
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
            default: /* '?' */
                ret = 1;
        }
    }
   
    return ret;
}
