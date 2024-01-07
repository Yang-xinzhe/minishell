#include "printinfo.h"
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void PrintInfo()
{
    struct passwd *pwd = NULL;
    char cwd[1024];
    getcwd(cwd, 1024);
    pwd = getpwuid(1000);
    printf("%s@ubuntu:%s $ ", pwd->pw_name, cwd);
    fflush(stdout);
}