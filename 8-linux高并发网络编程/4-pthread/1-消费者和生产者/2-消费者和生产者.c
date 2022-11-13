#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

sem_t consumer, producer;

int top = 0;

char buf[10][50];
//生产者线程
void *Producer(void *arg);
//消费者线程
void *Consumer(void *arg);

int main(int argc, char const *argv[])
{
    pthread_t tid1, tid2;
    sem_init(&producer, 0, 0);
    sem_init(&consumer, 0, 0);
    //创建消费者线程，和生产者线程

    pthread_create(&tid1, NULL, Producer, NULL);
    pthread_create(&tid2, NULL, Consumer, NULL);

    //等待线程退出
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    //销毁信号量
    sem_destroy(&producer);
    sem_destroy(&consumer);
    return 0;
}

void *Producer(void *arg)
{
    int k = 0;
    int produce_speed = 2;
    while (1)
    {
        sem_getvalue(&producer, &top);
        if (top >= 10)
        {
            printf("仓库已经满了，不能再生产了！\n");
            produce_speed = 2;
        }
        else
        {
            if (0 == top)
                produce_speed = 1;
            k++;
            printf("生产者生产了商品%d\n", k);
            strcpy(buf[top], "商品");
            sem_post(&producer);
            sem_post(&consumer);
        }

        sleep(produce_speed);
    }
}

void *Consumer(void *arg)
{
    int consume_speed = 2;
    while (1)
    {
        sleep(consume_speed);
        sem_wait(&producer);
        sem_wait(&consumer);
        sem_getvalue(&consumer, &top);
        if (top == 10)
            consume_speed = 1;
        else if (top == 0)
            consume_speed = 2;
        printf("消费者消费了：%s ,仓库还有%d个商品\n", buf[top - 1], top);
        memset(buf[top - 1], 0, 50);
    }
}