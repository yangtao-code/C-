#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>

int main(int argc, char const *argv[])
{
    int fd;
    fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        printf("open %s error!\n", argv[1]);
        perror("open:");
        return -1;
    }
    printf("%d\n", fd);
    
    return 0;
}
