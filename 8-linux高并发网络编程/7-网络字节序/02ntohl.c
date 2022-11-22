#include <stdio.h>
#include <arpa/inet.h>

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned short ushort;

int main(int argc, char const *argv[])
{
    uchar buf[4] = {192, 168, 31, 1};
    uint ipv4 = *(uint *)buf;

    uchar *c = (uchar *)&ipv4;
    printf("%d %d %d %d\n", *c, *(c + 1), *(c + 2), *(c + 3));
    //主机将数据转化为大端模式
    ipv4 = htonl(ipv4);
    c = (uchar *)&ipv4;
    printf("%d %d %d %d\n", *c, *(c + 1), *(c + 2), *(c + 3));
    printf("网络将大端模式的数据转换为主机的数据存储模式!\n");
    ipv4 = ntohl(ipv4);
    c = (uchar *)&ipv4;
    printf("%d %d %d %d\n", *c, *(c + 1), *(c + 2), *(c + 3));
    return 0;
}
