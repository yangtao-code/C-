#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    pid_t pid = -1;
    pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        return 1;
    }
    if (0 == pid)
    {
        exit(2);
    }
    printf("%d\n", pid);
    return 1;
}
