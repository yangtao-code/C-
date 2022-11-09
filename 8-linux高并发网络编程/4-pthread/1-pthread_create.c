/**
 * @file 1-pthread_create.c
 * @author your name (you@domain.com)
 * @brief 本程序用于创建一个线程
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *pthread1(void *arg)
{
    int i = 1;
    while (1)
    {
        printf("this is thread1 : %d\n", i);
        i++;
        sleep(1);
    }
    return NULL;
}

void *pthread2(void *arg)
{
    int i = 1;
    while (1)
    {
        printf("this is thread2 : %d\n", i);
        i++;
        sleep(1);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t tid1, tid2;
    int a = 100;
    int i = 1;
    pthread_create(&tid1, NULL, pthread1, NULL);
    pthread_create(&tid2, NULL, pthread2, NULL);
    while (a--)
    {
        printf("this is main : %d\n", i);
        i++;
        sleep(1);
    }
    return 0;
}
