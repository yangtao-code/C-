#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    unsigned char buf[] = "192.168.31.1";
    unsigned int num;
    //将字符串转化为32位大端数据
    inet_pton(AF_INET, buf, &num);
    unsigned char *c = (unsigned char *)&num;
    printf("%d %d %d %d\n", *c, *(c + 1), *(c + 2), *(c + 3));
    //将32位数据转为ipv4字符串
    char ipv4[16] = {0};
    printf("%s\n",inet_ntop(AF_INET,&num,ipv4,16));
    return 0;
}
