#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//中断程序1
void fun1(int signum);

//中断程序2
void fun2(int signo);

int main()
{
    printf("wait for SIGINT OR SIGQUIT\n");

    /* SIGINT: Ctrl+c ; SIGQUIT: Ctrl+\ */
    // 信号注册函数
    signal(SIGINT, fun1);
    signal(SIGQUIT, fun2);

    while (1)
        ; //不让程序结束

    return 0;
}

void fun1(int signum)
{
    printf("接受到ctrl + c 信号\n");
}

void fun2(int signum)
{
    printf("接受到CTRL + \\ 信号\n");
}