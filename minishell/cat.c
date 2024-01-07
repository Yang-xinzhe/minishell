#include "cat.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int catFile(const char *catFile)
{
    int fd = open(catFile, O_RDONLY);
    if (fd < 0)
    {
        perror("cat File open fail");
        return -1;
    }

    char buf[1024] = {0};
    int ret;
    while((ret = read(fd,buf,sizeof(buf)-1)) != 0)
    {
        write(1,buf,ret);
    }
    printf("\n");
}