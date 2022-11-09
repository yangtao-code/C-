#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//中断程序1
void fun1(int signum);

//中断程序2
void fun2(int signo);

void signal_handler(int signo)
{
    if (signo == SIGINT)
    {
        printf("recv SIGINT\n");
    }
    else if (signo == SIGQUIT)
    {
        printf("recv SIGQUIT\n");
    }
}
int main()
{
    printf("wait for SIGINT OR SIGQUIT\n");

    /* SIGINT: Ctrl+c ; SIGQUIT: Ctrl+\ */
    // 信号注册函数
    signal(SIGINT, fun1);
    signal(SIGSTOP, fun2);
    while (1); //不让程序结束

    return 0;
}


void fun1(int signum)
{
    printf("接受到ctrl + c 信号\n");
}

void fun2(int signum)
{
    printf("接受到CTRL + z信号\n");
}