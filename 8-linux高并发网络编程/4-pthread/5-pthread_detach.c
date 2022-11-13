#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread1(void *arg)
{
    while (1)
    {
        printf("I'm running!\n");
        sleep(1);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t tid1;
    int ret = pthread_create(&tid1, NULL, thread1, NULL);
    if (ret != 0)
    {
        perror("pthread_create");
        return 1;
    }
    pthread_detach(tid1);
    sleep(3);
    printf("I'm leaving.\n");
    return 0;
}
