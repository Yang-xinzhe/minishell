#include "mkdir.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int mkDir(const char *dirname)
{
    int ret = mkdir(dirname, 0777);
    if(ret < 0)
	{
		printf("mkdir fail\n");
		return -1;
	}
}