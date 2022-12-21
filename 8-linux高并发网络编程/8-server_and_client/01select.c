/**
 * @file 01select.c
 * @author your name (you@domain.com)
 * @brief select的使用
 * @version 0.1
 * @date 2022-12-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "wrap.h"

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("argc < 2 ! a.out ****\n");
        return 1;
    }
    // 创建套接字,绑定
    int lfd = tcp4bind(atoi(argv[1]), NULL);
    // 监听
    Listen(lfd, 128);
    int maxfd = lfd; // 最大文件描述符
    fd_set oldset, rset;
    FD_ZERO(&oldset);
    FD_ZERO(&rset);
    // 将lfd增加到oldset中
    FD_SET(lfd, &oldset);
    while (1)
    {
        rset = oldset; // 将oldset赋给需要监听的集合
        int n = select(maxfd + 1, &rset, NULL, NULL, NULL);
        if (n < 0)
        {
            perror("");
            break;
        }
        else if (n == 0)
        {
            continue; // 如果没有变化,继续监听
        }
        else // 发生了变化
        {
            // lfd有了变化,代表有新的连接过来
            if (FD_ISSET(lfd, &rset))
            {
                struct sockaddr_in cliaddr;
                socklen_t len = sizeof(cliaddr);
                char ip[16] = "";
                // 提取
                int cfd = Accept(lfd, (struct sockaddr *)&cliaddr, &len);
                printf("new client ip = %s,port = %d\n",
                       inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16),
                       ntohs(cliaddr.sin_port));
                // 将cfd增加到oldset集合里面,方便下次监听
                FD_SET(cfd, &oldset);
                if (cfd > maxfd)
                    maxfd = cfd;
                // 如果只有lfd变化,continue
                if (--n == 0)
                    continue;
            }
            // cfd 遍历lfd之后的文件描述符是否在rset中,在则cfd变化
            for (int i = lfd + 1; i <= maxfd; i++)
            {
                if (FD_ISSET(i, &rset))
                {
                    char buf[1500] = "";
                    int ret = Read(i, buf, 1500);
                    if (ret < 0) // 出错,将cfd关闭
                    {
                        perror("");
                        close(i);
                        FD_CLR(i, &oldset);
                        continue;
                    }
                    else if (ret == 0)
                    {
                        printf("client close\n");
                        close(i);
                        FD_CLR(i, &oldset);
                    }
                    else
                    {
                        printf("%s", buf);
                        fflush(stdout);
                        Write(i, buf, ret);
                    }
                }
            }
        }
    }
    return 0;
}
