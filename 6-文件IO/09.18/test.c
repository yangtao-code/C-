/**
 * @file test.c
 * @author yannyangyang (2245377079@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("error: please input 1.* 2.* !\n");
        return -1;
    }
    int fd1 = open(argv[1], O_RDONLY);                           //打开文件1
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666); //打开文件2
    lseek(fd1, 0, SEEK_SET);
    lseek(fd2, 0, SEEK_SET);
    char str[10];
    int ret = 1;
    while (ret > 0)
    {
        ret = read(fd1, str, 10);
        write(fd2, str, 10);
    }
    close(fd1);
    close(fd2);
    return 0;
}
