#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void thread_clean(void *str)
{
    printf("clean up :%s\n",(char*) str);
    free(str);
}

void *thread1(void *arg)
{
    printf("this is a new thread!\n");

    char *ptr = (char *)malloc(100);
    strcpy(ptr, "mallory from malloc!");
    pthread_cleanup_push(thread_clean, (void *)ptr);

    printf("before exit!\n");
    pthread_exit(0);

    printf("before pop!\n");
    pthread_cleanup_pop(0);
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    pthread_create(&tid, NULL, thread1, NULL);
    pthread_join(tid, NULL);
    printf("pross is dying!\n");

    return 0;
}
