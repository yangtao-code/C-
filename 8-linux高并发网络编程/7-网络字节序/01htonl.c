#include <stdio.h>
#include <arpa/inet.h>

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned short ushort;

int main(int argc, char const *argv[])
{
    uchar buf[4] = {192, 168, 31, 1};
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", buf[i]);
    }
    printf("\n");
    uint ipv4 = *(uint *)buf;

    uchar *c = (uchar *)&ipv4;
    printf("%d %d %d %d\n", *c, *(c + 1), *(c + 2), *(c + 3));
    ipv4 = htonl(ipv4);
    c = (uchar *)&ipv4;
    printf("%d %d %d %d\n", *c, *(c + 1), *(c + 2), *(c + 3));
    return 0;
}
