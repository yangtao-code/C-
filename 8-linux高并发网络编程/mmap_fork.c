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
    //打开文件
    int fd = -1;
    fd = open("1.txt", O_RDWR);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    void *addr = NULL;
    addr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }
    close(fd);
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        memcpy(addr, "abcdedffv", strlen("abcdedffv"));
    }
    else
    {
        wait(NULL);
        printf("addr:%s\n", (char *)addr);
    }
    munmap(addr, 1024);

    return 0;
}
