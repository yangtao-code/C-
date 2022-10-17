/**
 * @file opendir.c
 * @author yangtao (you@domain.com)
 * @brief 打开一个目录以及关闭一个目录。
 * @version 0.1
 * @date 2022-10-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
    //输入的格式，argv[1]为标准输入的第一个目录
    if (argc != 2)
    {
        printf("命令错误,请输入./opendir *\n");
        return -1;
    }
    DIR *dir = NULL;
    // 1.打开一个目录
    dir = opendir(argv[1]);
    if (dir == NULL)
    {
        perror("opendir");
        exit(-1);
    }
    printf("opendir succes! \n");
    
    // 关闭目录
    closedir(dir);
    return 0;
}
