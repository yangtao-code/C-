#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    while (1)
    {
        char buf[256]; //存放指令字符串
        char *str[10];
        printf("请输入指令：");
        fgets(buf, 256, stdin);
        str[0] = strtok(buf, " ");
        int i = 0;
        while (str[i] != NULL)
        {
            i++;
            str[i] = strtok(NULL, " ");
        }
        str[i - 1] = strtok(str[i - 1], "\n");
        pid_t pid = -1;
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            return -1;
        }
        //子进程
        if (pid == 0)
        {
            int ret = execlp(str[0], str,NULL);
            if (ret < 0)
            {
                perror("exec");
                exit(1);
            }
            exit(0);
        }
        wait(NULL);
    }
    return 0;
}
