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

/*
    #include <pthread.h>
    int pthread_create(
            pthread_t *restrict tidp,   //新创建的线程ID指向的内存单元。
            const pthread_attr_t *restrict attr,  //线程属性，默认为NULL
            void *(*start_rtn)(void *), //新创建的线程从start_rtn函数的地址开始运行
            void *restrict arg //默认为NULL。若上述函数需要参数，将参数放入结构中并将地址作为arg传入。
            );
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int val = 0;

void *pthread1(void *arg)
{
    while (1)
    {
        printf("this is thread1 val++\n");
        val++;
        sleep(1);
    }
    return NULL;
}

void *pthread2(void *arg)
{ 
    while (1)
    {
        printf("this is thread2 : %d\n", val);
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
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}
