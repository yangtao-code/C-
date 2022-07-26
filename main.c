#include "seqqueue.h"

int main(int argc, char const *argv[])
{
    SeqQueue *queue = cread_queue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    while (queue->front != queue->rear)
    {
        printf("%d ", queue->date[queue->front]);
        dequeue(queue);
    }

    free(queue->date);
    queue->date = NULL;
    free(queue);
    queue = NULL;
    return 0;
}
