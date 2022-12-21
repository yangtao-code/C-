#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    // 1.创建子进程,关闭父进程
    pid_t pid = -1;
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid > 0)
    {
        //关闭父进程
        exit(0);
    }
    // 2.创建会话,完全脱离控制终端
    pid = setsid();
    if (-1 == pid)
    {
        perror("setsid");
        return 1;
    }
    // 3.改变工作目录为根目录
    chdir("/");
    // 4.重设文件权限掩码
    umask(0);
    // 5.关闭文件描述符
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    //开始执行守护进程
    while (1)
    {
        system("date >> /home/china/code/8-linux高并发网络编程/6-daemonprocess/1-获取时间/time.log");
        sleep(2);
    }
    return 0;
}
