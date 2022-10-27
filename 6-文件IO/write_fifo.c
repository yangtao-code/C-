#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int fd = open("my_fifo", O_WRONLY | O_NONBLOCK);
    if (fd < 0)
    {
        perror("open");
        return -1;
    }
    char send[100];
    fgets(send, 100, stdin);
    write(fd, send, strlen(send));
    printf("write to my_fifo buf[ %s ]\n", send);

    return 0;
}
