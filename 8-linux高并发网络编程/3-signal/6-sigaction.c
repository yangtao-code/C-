#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void func(int sig)
{
    printf("hello signal: %d\n", sig);
    sleep(2);
    printf("wake up .....\n");
}

void func1(int signo, siginfo_t *info, void *context)
{
    printf("捕捉到信号 %d \n", signo);
}

int main()
{
#if 0
    //注册一个信号
    struct sigaction act;
    act.sa_handler = func;

    act.sa_flags = 0;
#else
    struct sigaction act;
    act.sa_sigaction = func1;
    act.sa_flags = SA_SIGINFO;

#endif
    int ret = sigaction(SIGINT, &act, NULL);
    if (-1 == ret)
    {
        perror("sigaction");
        return 1;
    }

    // while (1)
    // {
    //     getchar();
    // }
    getchar();

    return 0;
}