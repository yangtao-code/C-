/**
 * @file getpid.c
 * @author your name (you@domain.com)
 * @brief 获得当前进程的进程号
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    //获取进程号
    pid_t pid = getpid();
    printf("pid: %d\n", pid);


    return 0;
}
