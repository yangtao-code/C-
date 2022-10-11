#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    while (1)
    {
        char str[100];
        printf("请输入命令：");
        fgets(str, 100, stdin);

        char *res[5];
        int i = 0;
        res[i] = strtok(str, " ");
        while (res[i] != NULL)
        {
            i++;
            res[i] = strtok(NULL, " ");
        }
        res[i - 1] = strtok(res[i - 1], "\n");
        if (strcmp(res[0], "exit") == 0)
            return 0;
        int ret = fork();
        if (ret < 0)
        {
            perror("fork");
        }
        else if (ret == 0)
        {
            execvp(res[0], res);
        }
        else
        {
            printf("成功！\n");
            sleep(1);
        }
    }

    return 0;
}
