#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

//打印信号集
void show_sigset(sigset_t *s)
{
    int i = 1;
    for (i = 1; i < 32; i++)
    {
        if (sigismember(s, i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    sigset_t set;

    //将信号集清空
    sigemptyset(&set);
    show_sigset(&set);

    sigfillset(&set);
    show_sigset(&set);

    sigdelset(&set,SIGQUIT);
    sigdelset(&set,SIGINT);
    show_sigset(&set);

    sigaddset(&set,SIGINT);
    sigaddset(&set,SIGQUIT);
    show_sigset(&set);

    return 0;
}
