#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    //以读写方式打开一个文件
    int fd = -1;
    fd = open("1.txt", O_RDWR | O_CREAT);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    void *addr = NULL;
    //将文件映射到内存
    addr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }
    //关闭文件
    close(fd);
    //写储存映射区
    memcpy(addr,"1234567890",10);
    //关闭映射存储区
    munmap(addr, 1024);

    return 0;
}
