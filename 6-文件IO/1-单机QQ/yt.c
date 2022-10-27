#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    system("clear");
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return -1;
    }
    //子进程
    else if (pid == 0)
    {
        while (1)
        {
            int fd2 = open("ych.dat", O_WRONLY);
            if (fd2 < 0)
            {
                perror("open");
                return -1;
            }
            char send[1024];
            //printf("yt:");
            fgets(send, 1024, stdin);

            write(fd2, send, strlen(send));
            
        }
    }
    else
    {
        while (1)
        {
            int fd1 = open("yt.dat", O_RDONLY);
            if (fd1 < 0)
            {
                perror("father open");
                return -1;
            }
            char buf[1024];
            memset(buf, 0, sizeof(buf));
            read(fd1, buf, 1024);
            if (strlen(buf) > 0)
                printf("ych: %s", buf);
            sleep(1);
        }
    }
    return 0;
}