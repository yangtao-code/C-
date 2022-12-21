#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "wrap.h"

int main(int argc, char const *argv[])
{
    //创建套接字,绑定
    int fd_serv = tcp4bind(8080, NULL);

    //监听
    Listen(fd_serv, 128);
    //提取
    //读写
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    while (1)
    {
        char ip[16] = "";
        //提取连接
        int fd_cli = Accept(fd_serv, (struct sockaddr *)&cliaddr, &len);
        printf("client  %s 已连接server,port %d.\n",
               inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16), ntohs(cliaddr.sin_port));
        //创建子进程
        pid_t pid = -1;
        pid = fork();
        if (-1 == pid)
        {
            perror("fork");
            return 1;
        }
        else if (0 == pid)
        {
            //子进程关闭服务器描述符
            Close(fd_serv);
            while (1)
            {
                //缓冲区
                char buf[1024] = "";
                //  读客户端发来的信息
                int n = read(fd_cli, buf, 1024);
                //读取失败打印错误信息,退出子进程
                if (n < 0)
                {
                    perror("");
                    close(fd_cli);
                    exit(0);
                }
                else if (n == 0)
                {
                    printf("client %s exit.\n",
                           inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16));
                    close(fd_cli);
                    exit(0);
                }
                else
                {
                    printf("%s\n", buf);
                    write(fd_cli, buf, sizeof(buf));
                }
            }
        }
        else
        {
            //父进程关闭客户端文件描述符
            close(fd_cli);
        }
    }

    return 0;
}
