#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    struct itimerval delay;
    //第一次触发时间
    delay.it_interval.tv_sec = 3;
    delay.it_interval.tv_usec = 0;

    //触发周期
    delay.it_value.tv_sec = 2;
    delay.it_value.tv_usec = 0;

    int ret = -1;
    ret = setitimer(ITIMER_REAL, &delay, NULL);
    if(ret<0)
    {
        perror("setitimer");
        return 1;
    }
    printf("按任意键继续...\n");
    getchar();

    return 0;
}
