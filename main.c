#include "linkqueue.h"

int main(int argc, char const *argv[])
{
    LinkQueue *queue = Cread_Queue();

    EnQueue(queue, 10);
    EnQueue(queue, 20);
    EnQueue(queue, 30);
    EnQueue(queue, 40);
    Print_Queue(queue);
    printf("size: %d\n", Queue_Size(queue));

    DeQueue(queue);
    Print_Queue(queue);
    printf("size: %d\n", Queue_Size(queue));

    Destroy_Queue(queue);
    free(queue);
    queue = NULL;
    return 0;
}
