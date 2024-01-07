#include "cp.h"
#include <stdio.h>

int cpfile(const char * srcFile,char * destFile)
{
    FILE *src = fopen(srcFile,"r");
    FILE *dest = fopen(destFile,"w");

    if( NULL == src || NULL == dest)
    {
        perror("copy file open fail");
        return -1;
    }
    
    char buf[1024] = {0};
    while(fread(buf,sizeof(char),1,src))
    {
        fwrite(buf,sizeof(char),1,dest);
    }
}