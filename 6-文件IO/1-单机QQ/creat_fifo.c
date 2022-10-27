#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h>

int main()
{
    int ret = unlink("ych.dat");
    if (ret < 0)
    {
        perror("unlink ych.dat");
        return -1;
    }

    ret = unlink("yt.dat");
    if (ret < 0)
    {
        perror("unlink yt.dat");
        return -1;
    }

    ret = mkfifo("yt.dat", S_IRUSR | S_IWUSR);
    if (ret != 0)
    {
        perror("mkfifo yt.dat");
        return -1;
    }

    ret = mkfifo("ych.dat", S_IRUSR | S_IWUSR);
    if (ret != 0)
    {
        perror("mkfifo ych.dat");
        return -1;
    }
    return 0;
}