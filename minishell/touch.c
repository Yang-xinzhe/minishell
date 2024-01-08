#include "touch.h"
#include <stdio.h>

int touch(const char * filename)
{
    FILE *fp = fopen(filename,"w");

    if(NULL == fp)
    {
        perror("touch file open fail");
        return -1;
    }
    fclose(fp);
}