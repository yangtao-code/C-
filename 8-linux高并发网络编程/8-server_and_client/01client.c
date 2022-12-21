#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    //创建套接字
    int sock_fd;
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    //连接服务器
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    inet_pton(AF_INET, "192.168.44.1", &addr.sin_addr.s_addr);
    connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr));
    //读写服务器
    printf("连接服务器成功!\n");
    char buf[1024] = "";
    while (1)
    {
        int n = read(STDIN_FILENO, buf, 1024);
        write(sock_fd, buf, n);

        n = read(sock_fd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, n);
    }
    //关闭服务器
    close(sock_fd);
    return 0;
}
