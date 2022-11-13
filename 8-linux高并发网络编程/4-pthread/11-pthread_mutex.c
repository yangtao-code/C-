#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void printer(char *str)
{
    pthread_mutex_lock(&mutex);
    while (*str != '\0')
    {
        putchar(*str);
        fflush(stdout);
        str++;
        // sleep(1);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
}

void *thread1(void *arg)
{
    char *str = "hello";
    printer(str);
}

void *thread2(void *arg)
{
    char *str = "world";
    printer(str);
}

int main(int argc, char const *argv[])
{
    pthread_t tid1, tid2;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&tid1, NULL, thread1, NULL);
    //sleep(1);
    pthread_create(&tid2, NULL, thread2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}
