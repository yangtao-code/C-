/**
 * @file fpathconf.c
 * @author your name (you@domain.com)
 * @brief   测试long fpathconf(int __fd, int __name)函数,查看管道缓冲区大小
 * @version 0.1
 * @date 2022-10-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd[2];
    int ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe");
        return -1;
    }
    int buf = fpathconf(fd[0], _PC_PIPE_BUF);
    printf("%d\n", buf);

    return 0;
}
