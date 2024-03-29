#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int fd = -1;
    fd = open("read.txt", O_WRONLY | O_CREAT, 0644);
    if (fd < 0)
    {
        perror("open");
        exit(-1);
    }
    lseek(fd, 0, SEEK_END);
    char buf[] = "abcdef";
    write(fd, buf, sizeof(buf));
    close(fd);
    return 0;
}
