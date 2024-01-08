#include "ls.h"
#include <stdio.h>
#include <sys/types.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>

int lsFile(const char *filename)
{
    struct stat st;
    if (stat(filename, &st) < 0)
    {
        perror("ls stat fail");
        return -1;
    }
    printf("%10s\t", filename);
}

int lsDir(const char *dirname)
{
    DIR *dir = opendir(dirname);
    struct dirent *pdir = NULL;
    while ((pdir = readdir(dir)) != NULL)
    {
        char path[1024] = {0};
        if (pdir->d_name[0] != '.')
        {
            lsFile(pdir->d_name);
        }
    }
    closedir(dir);
    printf("\n");
}

int lsDirA(const char *dirname)
{
    DIR *dir = opendir(dirname);
    struct dirent *pdir = NULL;
    while ((pdir = readdir(dir)) != NULL)
    {
        char path[1024] = {0};

        lsFile(pdir->d_name);
    }
    closedir(dir);
    printf("\n");
}

int lsFileL(const char *filename)
{
    struct stat st;
    if (stat(filename, &st) < 0)
    {
        perror("ls stat fail");
        return -1;
    }
    switch (st.st_mode & S_IFMT)
    {
    case S_IFSOCK:
        putchar('s');
        break;
    case S_IFLNK:
        putchar('l');
        break;
    case S_IFREG:
        putchar('r');
        break;
    case S_IFBLK:
        putchar('b');
        break;
    case S_IFDIR:
        putchar('d');
        break;
    case S_IFCHR:
        putchar('c');
        break;
    case S_IFIFO:
        putchar('p');
        break;
    }

    (st.st_mode & S_IRUSR) ? putchar('r') : putchar('-');
    (st.st_mode & S_IWUSR) ? putchar('w') : putchar('-');
    (st.st_mode & S_IXUSR) ? putchar('x') : putchar('-');
    (st.st_mode & S_IRGRP) ? putchar('r') : putchar('-');
    (st.st_mode & S_IWGRP) ? putchar('w') : putchar('-');
    (st.st_mode & S_IXGRP) ? putchar('x') : putchar('-');
    (st.st_mode & S_IROTH) ? putchar('r') : putchar('-');
    (st.st_mode & S_IWOTH) ? putchar('w') : putchar('-');
    (st.st_mode & S_IXOTH) ? putchar('x') : putchar('-');

    struct group *gp = getgrgid(1000);

    printf(" %3ld ", st.st_nlink);
    printf("%s  ", getpwuid(st.st_uid)->pw_name);
    printf("%s ", gp->gr_name);
    printf(" %6ld ", st.st_size);
    struct tm *ptm = localtime(&st.st_mtime);
    printf(" %2d月%2d日 %02d:%02d:%02d ", ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
    printf("%s\n", filename);
}

int lsDirL(const char *dirname)
{
    DIR *dir = opendir(dirname);
    struct dirent *pdir = NULL;
    while ((pdir = readdir(dir)) != NULL)
    {
        char path[1024] = {0};
        dirname[strlen(dirname) - 1] == '/' ? sprintf(path, "%s%s", dirname, pdir->d_name) : sprintf(path, "%s/%s", dirname, pdir->d_name);
        lsFileL(path);
    }
    closedir(dir);
    printf("\n");
}

int ls(const char *path)
{
    struct stat st;
    if (path == NULL)
    {
        lsDirL(".");
    }
    else
    {
        if (stat(path, &st) < 0)
        {
            perror("Error stat");
            return -1;
        }

        if (S_ISDIR(st.st_mode))
        {
            lsDir(path);
        }
        else
        {
            lsFileL(path);
        }
    } 
    return 0;
}