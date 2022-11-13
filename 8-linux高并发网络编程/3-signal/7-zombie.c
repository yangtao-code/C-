#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void func(int signo)
{
    printf("捕捉到信号：%d \n", signo);
    printf("子进程已退出...\n");
    if (waitpid(-1, NULL, WNOHANG) > 0)
        kill(getpid(), SIGKILL);
}

int main(int argc, char const *argv[])
{
    struct sigaction act;
    act.sa_handler = func;
    act.sa_flags = 0;

    sigaction(SIGCHLD, &act, NULL);
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        printf("子进程正在工作....\n");
        sleep(2);
        printf("子进程累了，要休息了\n");
        exit(0);
    }
    else
    {
        while (1)
        {
            printf("父进程正在工作....\n");
            sleep(1);
        }
    }

    return 0;
}
