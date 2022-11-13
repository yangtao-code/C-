#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//中断程序1
void fun1(int signum);

//中断程序2
void fun2(int signo);

int main()
{
    int ret = -1;
    sigset_t set, oldset;
    printf("wait for SIGINT OR SIGQUIT\n");

    /* SIGINT: Ctrl+c ; SIGQUIT: Ctrl+\ */
    // 信号注册函数
    signal(SIGINT, fun1);
    signal(SIGQUIT, fun2);

    printf("按下任意键堵塞信号值为2的信号\n");
    getchar();
    //清空堵塞信号集
    sigemptyset(&oldset);
    sigemptyset(&set);

    sigaddset(&set,SIGINT);
    ret = sigprocmask(SIG_BLOCK, &set, &oldset);
    if (-1 == ret)
    {
        perror("sigprocmask");
        return 1;
    }

    printf("按下任意键解除编号为2的信号的堵塞！\n");
    getchar();

    sigprocmask(SIG_SETMASK,&oldset,NULL);

    printf("按下任意键继续...\n");
    getchar();

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