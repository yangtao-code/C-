#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

sem_t producer, consumer;
int array[10];
int top = -1;

void *Producer(void *arg)
{
    while (1)
    {
        sem_wait(&producer);
        array[++top] = rand()%100;
        printf("生产 %d\n",array[top]);
        sem_post(&consumer);
        sleep(rand()%3);
    }
}

void *Consumer(void *arg)
{
    while (1)
    {
        sem_wait(&consumer);
        printf("消费 %d\n",array[top]);
        top--;
        sem_post(&producer);
        sleep(rand()%3);

    }
}

int main()
{
    srand(time(NULL));
    pthread_t tid1, tid2;
    sem_init(&producer, 0, 10);
    sem_init(&consumer, 0, 0);

    pthread_create(&tid1, NULL, Producer, NULL);
    pthread_create(&tid2, NULL, Consumer, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sem_destroy(&producer);
    sem_destroy(&consumer);

    return 0;
}