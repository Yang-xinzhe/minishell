#include "cp.h"
#include <stdio.h>

int cpfile(const char *srcFile, char *destFile)
{
    FILE *src = fopen(srcFile, "r");
    FILE *dest = fopen(destFile, "w");

    if (NULL == src || NULL == dest)
    {
        perror("copy file open fail");
        return -1;
    }

    char buf[1024] = {0};
    int ret = 0;
    while ((ret = fread(buf, 1, sizeof(buf), src)) > 0)
    {
        fwrite(buf, 1, ret, dest);
    }
    fflush(dest);
    fclose(src);
    fclose(dest);
}