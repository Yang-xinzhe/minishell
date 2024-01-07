#include "rmdir.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int rmDir(const char *dirname)
{
    DIR *dir = opendir(dirname);
    if (NULL == dir)
    {
        perror("opendir fail");
        return -1;
    }

    struct dirent *pdir = NULL;
    while ((pdir = readdir(dir)) != NULL)
    {
        char path[1024] = {0};
        if (pdir->d_name[0] != '.')
        {
            strcpy(path, dirname);
            strcat(path, "/");
            strcat(path, pdir->d_name);
            if (pdir->d_type == DT_DIR)
            {
                rmDir(path);
            }
            else
            {
                remove(path);
            }
        }
    }
    closedir(dir);
    rmdir(dirname);
}

// int main(int argc ,const char * argv[])
// {
//     rmDir(argv[1]);
//     return 0;
// }