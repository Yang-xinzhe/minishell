#include "mv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int mvFile(const char *srcFile,const char *pathname)
{
    FILE *srcfp = fopen(srcFile,"r");
    if(NULL == srcfp)
    {
        perror("mv srcFile open fail");
        return -1;
    }
    if (pathname[strlen(pathname) - 1] != '/')
    {
        printf("a directory name is specified (end with '/)");
        return -1;
    }

    char path[1024];
    sprintf(path, "%s%s", pathname, srcFile);

    FILE *destfp = fopen(path, "w");
    if (NULL == destfp)
    {
        perror("mv destFile open fail");
        return -1;
    }

    char buf[1024];
    int ret = 0;
    while ((ret = fread(buf, 1, sizeof(buf), srcfp)) > 0)
    {
        fwrite(buf, 1, ret, destfp);
    }
    fclose(srcfp);
    fclose(destfp);

    remove(srcFile);
}