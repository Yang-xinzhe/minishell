#include "shell.h"
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "ls.h"
#include "cat.h"
#include "printinfo.h"
#include "touch.h"
#include "mkdir.h"
#include "cp.h"
#include "rm.h"
#include "rmdir.h"
#include "cd.h"
#include "mv.h"
void workShell(void)
{
    char buf[1024] = {0};
    char *cmd;
    char *arg1;
    char *arg2;
    char *arg3;
    while (1)
    {
        struct passwd *pwd = NULL;
        char cwd[1024];
        getcwd(cwd, 1024);
        PrintInfo();
        fgets(buf, 1024, stdin);
        cmd = strtok(buf, " \n");
        if (cmd == NULL)
            continue; 

        if (strcmp(cmd, "ls") == 0)
        {
            arg1 = strtok(NULL, " \n"); 
            arg2 = strtok(NULL, " \n"); 

            if (arg1 != NULL && strcmp(arg1, "-l") == 0)
            {
                if (arg2 != NULL)
                {
                    lsFileL(arg2); 
                }
                else
                {
                    lsDirL("."); 
                }
            }
            else
            {
                lsDir("."); 
            }
        }
        else if (strcmp(cmd, "cat") == 0)
        {
            arg1 = strtok(NULL, " \n");
            catFile(arg1);
        }
        else if (strcmp(cmd, "touch") == 0)
        {
            arg1 = strtok(NULL, " \n");
            touch(arg1);
        }
        else if (strcmp(cmd, "mkdir") == 0)
        {
            arg1 = strtok(NULL, " \n");
            mkDir(arg1);
        }
        else if (strcmp(cmd, "cp") == 0)
        {
            arg1 = strtok(NULL, " \n");
            arg2 = strtok(NULL, " \n");
            cpfile(arg1, arg2);
        }
        else if (strcmp(cmd, "rm") == 0)
        {
            arg1 = strtok(NULL, " \n");
            arg2 = strtok(NULL, " \n");
            arg3 = strtok(NULL, " \n");
            if (arg1 != NULL && strcmp(arg1, "-rf") == 0 && arg2 != NULL)
            {
                rmDir(arg2);
            }
            else if (arg1 != NULL)
            {
                struct stat st;
                if (stat(arg1, &st) < 0)
                {
                    perror("Error stat");
                    continue;
                }

                if (S_ISDIR(st.st_mode))
                {

                    printf("not a empty directory\n");
                }
                else
                {

                    rm(arg1);
                }
            }
        }
        else if (strcmp(cmd, "pwd") == 0)
        {
            printf("%s\n", cwd);
        }
        else if (strcmp(cmd, "cd") == 0)
        {
            arg1 = strtok(NULL, " \n");
            changeDir(arg1);
        }
        else if (strcmp(cmd, "mv") == 0)
        {
            arg1 = strtok(NULL, " \n");
            arg2 = strtok(NULL, " \n");
            if (arg1 != NULL && arg2 != NULL)
            {
                if (arg2[strlen(arg2) - 1] != '/')
                {
                    printf("The destination directory should end with '/'.\n");
                }
                else
                {
                    mvFile(arg1, arg2);
                }
            }
            else
            {
                printf("mv <file name> <directory name>\n");
            }
        }
        else if (strcmp(cmd, "quit") == 0)
        {
            break;
        }
    }
}