#include "rm.h"
#include <stdio.h>
int rm(const char *dirname)
{
    int ret = remove(dirname);
    if (ret < 0)
    {
        perror("remove file fail");
        return -1;
    }
}
