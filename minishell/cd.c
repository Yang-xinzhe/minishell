#include "cd.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
void changeDir(const char *path)
{
    if (path == NULL)
    {
        struct passwd *pwd = NULL;
        pwd = getpwuid(1000);
        path = pwd->pw_dir;
    }
    int ret = chdir(path);
    if(ret == -1)
    {
        perror("change directory fail");
    }
}