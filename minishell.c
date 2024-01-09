#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main(int argc, const char *argv[])
{
    char buf[1024] = {0};
    char *arg1;
    char *arg2;
    char *arg3;
    char *cmd;

    while (1)
    {
        struct passwd *pwd = NULL;
        char cwd[1024];
        getcwd(cwd, 1024);
        printf("yangxinzhe@ubuntu:%s $ ", cwd);
        fgets(buf, 1024, stdin);
        cmd = strtok(buf, " \n");
        if (strcmp(cmd, "exit") == 0)
        {
            break;
        }
        if (strcmp(cmd, "cd") == 0)
        {
            arg1 = strtok(NULL, " \n");
            if (arg1 == NULL || chdir(arg1) != 0)
            {
                perror("cd failed");
            }
            continue;
        }
        pid_t pid = fork();
        if (pid > 0)
        {
            wait(NULL);
        }
        else if (pid == 0)
        {

            if (strcmp(cmd, "ls") == 0)
            {
                arg1 = strtok(NULL, " \n");
                arg2 = strtok(NULL, " \n");
                if (arg1 != NULL && strcmp(arg1, "-l") == 0)
                {
                    execlp(cmd, "ls", "-l","--color=auto", NULL);
                    exit(0);
                }
                else if (arg1 != NULL && strcmp(arg1, "-a") == 0)
                {
                    execlp(cmd, "ls", "-a","--color=auto", NULL);
                    exit(0);
                }
                else
                {
                    execlp(cmd, "ls", "--color=auto",NULL);
                    exit(0);
                }
            }
            else if (strcmp(cmd, "cat") == 0)
            {
                arg1 = strtok(NULL, " \n");
                execlp(cmd, "cat", arg1, NULL);
                exit(0);
            }
            else if(strcmp(cmd, "mkdir") == 0)
            {
                arg1 = strtok(NULL, " \n");
                arg2 = strtok(NULL, " \n");
                execlp(cmd, "mkdir", arg1,NULL);
                exit(0);
            }
            else if(strcmp(cmd, "cp") == 0)
            {
                arg1 = strtok(NULL, " \n");
                arg2 = strtok(NULL, " \n");
                execlp(cmd,"cp",arg1,arg2,NULL);
                exit(0);
            }
            else if (strcmp(cmd, "pwd") == 0)
            {
                arg1 = strtok(NULL, " \n");
                execlp(cmd, "pwd", NULL);
            }
         
        }
    }
    return 0;
}