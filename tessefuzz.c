// author: pype / tt:@pyper3ng3r // github:pyperanger
#include "tessefuzz.h"

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <leptonica/allheaders.h>
#include <tesseract/capi.h>

#define die(STR) {printf(STR);exit(-1);}


char **_alphaword(char *T)
{
    char **ret;
    int len = strlen(T);
    ret = malloc(len * sizeof(char *));

    for (size_t i = 0; i < len; i++)
        ret[i] = malloc(2 * sizeof(char));

    int c = 0;
    while (T[c] != '\0')
    {
        ret[c][0] = T[c];
        if ((((int)ret[c][0] >= 65) && ((int)ret[c][0] <= 90)) || (((int)ret[c][0] >= 97) && ((int)ret[c][0] <= 122)))
            ret[c][1] = (int)ret[c][0] < 91 ? (int)ret[c][0] + 32 : (int)ret[c][0] - 32;
        else
            ret[c][1] = ret[c][0];
        ++c;
    }
    return ret;
}

int _listlang(char **L)
{
    int i;
    printf("\x1B[36m[Info]\x1B[37m Listing available languages\n\t");
    for (i = 0; L[i] != NULL; i++)
        printf("%d)%s\t", i + 1, L[i]);
    printf("\n\r\n-------------------\n");
    return i;
}

int scorepoint(char *text, WORD capinfo, int lang)
{    
    if (strncmp(text, capinfo.text, capinfo.lentext) == 0)
        return 100;

    int score = 0;
    char rtext[capinfo.lentext];

    strncpy(rtext, text, capinfo.lentext);

    for(int i = 0 ; i < capinfo.lentext; i++){
        if (text[i] == capinfo.words[i][0]) 
            score = score + capinfo.fpoint;
        else if (text[i] == capinfo.words[i][1])
            score = score + capinfo.mpoint;     
    }

    if(capinfo.level > 1){
        for(int m = 0 ; m < capinfo.lentext; m++){
            for(int j = 0; j < strlen(text); j++){
                if(text[j] == capinfo.words[m][0])
                    score = score +  capinfo.ipoint;
            }
        }
    }

    if(capinfo.level > 2){
        for(int n = 0 ; n < capinfo.lentext; n++){
            for(int x = 0; x < strlen(text); x++){
                if(text[x] == capinfo.words[n][1])
                    score = score +  capinfo.ipoint;
            }
        }
    }

    return score;
}

int shoothesheriff(WORD capinfo)
{
    TessBaseAPI *handle = NULL;
    PIX *img;
    char **langs = NULL;
    int c = 0, tmp[2];
    char *textrecon;

    handle = TessBaseAPICreate();
    TessBaseAPISetVariable(handle, "debug_file", "/dev/null"); // Avoid DPI Errors

    if (TessBaseAPIInit3(handle, NULL, "eng") != 0)
        die("[Error] Initializing Tesseract\n");

    langs = TessBaseAPIGetAvailableLanguagesAsVector(handle);
    int langlen = _listlang(langs);
    int rank[langlen][2];

    if ((img = pixRead(capinfo.filename)) == NULL)
        die("Error reading image\n");
    
    printf("Find for: %s\nLevel: %d\n", capinfo.text, capinfo.level);
    

    while (langs[c] != NULL)
    {
        if (TessBaseAPIInit3(handle, NULL, langs[c]) != 0)
            die("[Error] Initializing Tesseract\n");

        TessBaseAPISetImage2(handle, img);

        if (TessBaseAPIRecognize(handle, NULL) != 0)
            die("Error in Tesseract recognition\n");

        if ((textrecon = TessBaseAPIGetUTF8Text(handle)) == NULL)
            die("Error getting text\n");

        
        rank[c][0] = c;
        rank[c][1] = scorepoint(textrecon, capinfo, c);

        printf("\r\x1B[33m~ [  %d/%d  ] \t%s\t\t\t%d points\t-> %s", c ,langlen-1, langs[c],rank[c][1], textrecon);    
        fflush(stdout);

        ++c;
    }

    puts("~ sorting rank");

    // dumb sorting
    for(size_t s = 0; s < langlen; s++)
    {
        for(size_t z = 0; z < langlen; z++)
        {
            if(rank[z][1]  >  rank[s][1]){
                tmp[0] = rank[s][0];
                tmp[1] = rank[s][1];
                rank[s][0] = rank[z][0];
                rank[s][1] = rank[z][1];
                rank[z][0] = tmp[0];
                rank[z][1] = tmp[1];
            }
        }
    }
    
    for(size_t l = 0; l < langlen; l++)
    {
        printf("\x1b[32m\t ~ %s\t%d Points\n", langs[l], rank[l][1]);
    }

    printf("\nUse [-l [language]] in tesseract to check result.\n");

    // free
    pixDestroy(&img);
    free(langs);
    TessBaseAPIEnd(handle);
    TessBaseAPIDelete(handle);
    free(textrecon);

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
        die("TessFuZz-> FiND THe BEsT lANg to your captcha challage\nSearch level: 1 LOW , 2 MEDIUN, 3 INSANE\nUsage: ./tessefuzz foto.jpg \"AvZd\" 1\n\n");

    if (access(argv[1], F_OK) == -1)
        die("\nImage not found\n\n");

    puts("\x1B[36m[Info]\x1B[37m Welcome Tesseract Fuzz, lets try find the best language configuration to bypass and fuck some systemadmin life");

    WORD CAPTCHA = {.text = argv[2], .filename = argv[1], .words = _alphaword(argv[2]),\
                     .lentext = strlen(argv[2]), .fpoint = 100 / CAPTCHA.lentext, \
                     .mpoint = CAPTCHA.fpoint / CAPTCHA.lentext, .level = 1};

    if(argc > 3){
        CAPTCHA.level = strtol(argv[3], NULL, 10);
        CAPTCHA.ipoint = CAPTCHA.mpoint / 2;
    }

    if(CAPTCHA.level > 3)
        CAPTCHA.level = 3;

    if (shoothesheriff(CAPTCHA) != 0)
        die("Something fuckup");

    return 0;
}