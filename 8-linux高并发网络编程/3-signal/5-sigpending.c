#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//中断程序1
void fun1(int signum);

//中断程序2
void fun2(int signo);

void fun1(int signum)
{
    printf("接受到ctrl + c 信号\n");
}

void fun2(int signum)
{
    printf("接受到CTRL + \\ 信号\n");
}

int main()
{
    int ret = -1;
    sigset_t set, oldset;
    printf("wait for SIGINT OR SIGQUIT\n");

    /* SIGINT: Ctrl+c ; SIGQUIT: Ctrl+\ */
    // 信号注册函数
    signal(SIGINT, fun1);
    signal(SIGQUIT, fun2);

    printf("按下换行键堵塞信号值为2的信号\n");
    getchar();
    //清空堵塞信号集
    sigemptyset(&oldset);
    sigemptyset(&set);

    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);
    ret = sigprocmask(SIG_BLOCK, &set, &oldset);
    if (-1 == ret)
    {
        perror("sigprocmask");
        return 1;
    }
    printf("设置屏蔽信号2,3信号成功\n");

    printf("按下换行键获取未决信号集\n");
    getchar();
    //获取未决信号
    sigemptyset(&set);
    ret = sigpending(&set);
    if (-1 == ret)
    {
        perror("sigpending");
        return -1;
    }
    //输出未决信号
    for (int i = 1; i < 32; i++)
    {
        if (sigismember(&set, i))
        {
            printf("%d ", i);
        }
    }
    putchar('\n');

    printf("按下换行键解除编号为2和3的信号的堵塞！\n");
    getchar();

    sigprocmask(SIG_SETMASK, &oldset, NULL);

    printf("按下换行键继续...\n");
    getchar();

    return 0;
}

