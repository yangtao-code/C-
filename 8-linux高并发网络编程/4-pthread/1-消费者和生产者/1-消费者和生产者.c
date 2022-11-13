#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

sem_t sem;

int value = 0;

char buf[10][50];

void *producer(void *arg);

void *consumer(void *arg);

int main(int argc, char const *argv[])
{
    pthread_t tid1, tid2;
    sem_init(&sem, 0, 0);
    //创建消费者线程，和生产者线程
    
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);

    //等待线程退出
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sem_destroy(&sem);
    return 0;
}

void *producer(void *arg)
{
    int k = 0;
    while (1)
    {
        sem_getvalue(&sem, &value);
        if (value >= 10)
        {
            printf("仓库已经满了，不能再生产了！\n");
        }
        else
        {
            k++;
            printf("生产者生产了商品%d\n", k);
            strcpy(buf[value], "商品");
            sem_post(&sem);
        }
        sleep(1);
    }
}

void *consumer(void *arg)
{
    while (1)
    {
        sem_wait(&sem);
        printf("消费者消费了：%s\n", buf[value]);
        memset(buf[value], 0, 50);
        sleep(2);
    }
}