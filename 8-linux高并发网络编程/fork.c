#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
    }
    else if (pid == 0)
    {
        printf("子进程：%d ", getpid());
        printf("父进程：%d ", getppid());
        printf("组进程：%d\n\n",getpgid(getpid()));
        exit(0);
    }
		
    else
    {
        wait(NULL);
        printf("本进程：%d ", getpid());
        printf("父进程：%d ", getppid());
        printf("组进程：%d\n\n",getpgid(getpid()));
    }

    return 0;
}
