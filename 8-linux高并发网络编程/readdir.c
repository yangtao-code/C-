/**
 * @file opendir.c
 * @author yangtao (you@domain.com)
 * @brief 打开一个目录,并将这个文件里面的文件以及文件类型显示到屏幕。
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
    struct dirent *d = NULL;
    // 1.打开一个目录
    dir = opendir(argv[1]);
    if (dir == NULL)
    {
        perror("opendir");
        exit(-1);
    }
    printf("opendir succes! \n");

    //读目录
    d = readdir(dir);
    while (d != NULL)
    {
        switch (d->d_type)
        {
        case DT_BLK:
            printf("dirname:%s  type:this is a block device.", d->d_name);
            break;
        case DT_CHR:
            printf("dirname:%s  type:this is a character device.", d->d_name);
            break;
        case DT_DIR:
            printf("dirname:%s  type:this is a directory.", d->d_name);
            break;
        case DT_FIFO:
            printf("dirname:%s  type:this is a named pipe(FIFO).", d->d_name);
            break;
        case DT_LNK:
            printf("dirname:%s  type:this is a symbolic link.", d->d_name);
            break;
        case DT_REG:
            printf("dirname:%s  type:this is a regular file.", d->d_name);
            break;
        case DT_SOCK:
            printf("dirname:%s  type:this is a UNIX domain socket.", d->d_name);
            break;
        case DT_UNKNOWN:
            printf("dirname:%s  type:this file type is unkown.", d->d_name);
            break;
        }
        printf("\n");
        d = readdir(dir);
    }

    // 2.关闭目录
    closedir(dir);
    return 0;
}
