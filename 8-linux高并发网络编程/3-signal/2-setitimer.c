#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <signal.h>

void fun(int signum)
{
    printf("捕捉到时钟信号: %d\n", signum);
}

int main(int argc, char const *argv[])
{
    struct itimerval delay;
    //第一次触发时间
    delay.it_interval.tv_sec = 1;
    delay.it_interval.tv_usec = 0;

    //触发周期
    delay.it_value.tv_sec = 2;
    delay.it_value.tv_usec = 0;

    //设置SIGALRM信号
    signal(SIGALRM, fun);
    int ret = -1;
    ret = setitimer(ITIMER_REAL, &delay, NULL);
    if (ret < 0)
    {
        perror("setitimer");
        return 1;
    }
    printf("按任意键继续...\n");
    getchar();

    return 0;
}
