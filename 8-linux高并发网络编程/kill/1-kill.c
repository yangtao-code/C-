#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    pid_t pid = -1;
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
    }
    else if (pid == 0)
    {
        while (1)
        {
            printf("child press do work...\n");
            sleep(1);
        }
        exit(0);
    }
    else
    {
        sleep(3);
        printf("父进程杀掉子进程！\n");
        kill(pid, 15);
        printf("父进程完成工作！\n");
    }
    return 0;
}
