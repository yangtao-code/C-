#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    int ret = unlink("my_fifo");
    if (ret < 0)
    {
        perror("unlink fifo");
        return -1;
    }
    ret = mkfifo("my_fifo", S_IRUSR | S_IWUSR);
    if (ret != 0)
    {
        perror("mkfifo");
        return -1;
    }

    int fd = open("my_fifo", O_CREAT | O_RDONLY | O_NONBLOCK);
    if (fd < 0)
    {
        perror("open");
        return -1;
    }

    while (1)
    {
        char recv[1000];
        memset(recv, 0, sizeof(recv));
        read(fd, recv, sizeof(recv));
        if (strlen(recv) > 0)
            printf("read from my_fifo buf[ %s ]\n", recv);
        sleep(1);
    }

    return 0;
}
