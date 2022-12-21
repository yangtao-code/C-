#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include "wrap.h"

typedef struct c_info
{
    int cli_fd;
    struct sockaddr_in cliaddr;
} INFO;

// 服务器发送信息给客户端
//  void *server_to_client(void *arg)
//  {
//      INFO *info = (INFO *)arg;
//      char ip[16] = "";
//      printf("new client ip = %s ,port = %d\n",
//             inet_ntop(AF_INET, &(info->cliaddr.sin_addr.s_addr), ip, 16),
//             ntohs(info->cliaddr.sin_port));
//      while (1)
//      {
//          int n = 0;
//          char buf[1024] = "";
//          memset(buf, 0, 1024);
//          n = read(STDIN_FILENO, buf, 1024);
//          //退出接口,输入quit退出.
//          if (strcmp(buf, "quit\n") == 0)
//          {
//              printf("已退出...\n");
//              kill(getpid(), SIGKILL);
//          }
//          write(info->cli_fd, buf, n);
//      }
//      pthread_exit(NULL);
//  }

// 服务器接收客户端的信息
void *client_to_server(void *arg)
{
    char buf[1024] = "";
    INFO *info = (INFO *)arg;
    char ip[16] = "";
    printf("new client ip = %s ,port = %d\n",
           inet_ntop(AF_INET, &(info->cliaddr.sin_addr.s_addr), ip, 16),
           ntohs(info->cliaddr.sin_port));
    int n = 0;
    while (1)
    {
        n = read(info->cli_fd, buf, 1024);
        if (-1 == n)
        {
            perror("");
            break;
        }
        else if (0 == n)
        {
            printf("client close!\n");
            break;
        }
        else
        {
            printf("%s", buf);
            Write(info->cli_fd, buf, sizeof(buf));
            memset(buf,0,1024);
        }
    }
    close(info->cli_fd);
    free(info);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("argc < 2?? a.out ****\n");
        return 1;
    }
    // 创建套接字
    // 绑定
    int serv_fd = tcp4bind(atoi(argv[1]), NULL);

    // 监听
    Listen(serv_fd, 128);
    // 提取

    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    while (1)
    {
        int cli_fd = Accept(serv_fd, (struct sockaddr *)&cliaddr.sin_addr.s_addr, &len);
        INFO *info = (INFO *)malloc(sizeof(INFO));
        info->cli_fd = cli_fd;
        info->cliaddr = cliaddr;
        // 读写
        pthread_t tid1, tid2;
        // pthread_create(&tid1, NULL, server_to_client, info);
        pthread_create(&tid2, NULL, client_to_server, info);
    }

    // 关闭
    close(serv_fd);
    return 0;
}
