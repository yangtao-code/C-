#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread1(void *arg)
{
    int i = 0;
    while (1)
    {
        i++;
        printf("son: %d\n", i);
        sleep(1);
        if (i == 3)
        {
            pthread_exit((void *)1);
        }
    }
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, thread1, NULL);
    void *value = NULL;
    if (ret != 0)
    {
        perror("pthread_create");
        return 1;
    }
    pthread_join(tid, &value);
    printf("value: %p\n", (int *)value);
    printf("I'm leaving!\n");
    return 0;
}
