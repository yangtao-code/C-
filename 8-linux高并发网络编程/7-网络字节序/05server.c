#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>

//服务器接收客户端的信息
void *server_to_client(void *arg)
{
    char buf[1024] = "";
    int cli_fd = *(int *)arg;
    int n = 0;
    while (1)
    {
        memset(buf, 0, 1024);
        n = read(STDIN_FILENO, buf, 1024);
        if (strcmp(buf, "quit\n") == 0)
        {
            printf("已退出...\n");
            kill(getpid(), SIGKILL);
        }
        write(cli_fd, buf, n);
    }
    return NULL;
}

//客户端接收服务器的信息
void *client_to_server(void *arg)
{
    char buf[1024] = "";
    int cli_fd = *(int *)arg;
    int n = 0;
    while (1)
    {
        n = read(cli_fd, buf, 1024);
        if (-1 == n)
        {
            perror("read client");
        }
        printf("%s\n", buf);
    }
}

int main(int argc, char const *argv[])
{
    //创建套接字
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1)
    {
        perror("socket");
        return 1;
    }
    //绑定
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8000);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr));
    //监听
    int ret = listen(sock_fd, 128);
    if (-1 == ret)
    {
        perror("listen");
        return 1;
    }
    //提取
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    int cli_fd = accept(sock_fd, (struct sockaddr *)&cliaddr, &len);
    if (-1 == cli_fd)
    {
        perror("accept");
        return 1;
    }

    //读写

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, server_to_client, &cli_fd);
    pthread_create(&tid2, NULL, client_to_server, &cli_fd);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    //关闭
    close(cli_fd);
    close(sock_fd);
    return 0;
}
