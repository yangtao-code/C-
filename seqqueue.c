#include "seqqueue.h"

SeqQueue *cread_queue()
{
    SeqQueue *queue = (SeqQueue *)malloc(sizeof(SeqQueue));
    queue->date = (ElemType *)malloc(sizeof(ElemType)*MAX_SIZE);
    queue->front = 0;
    queue->rear = 0;
    return queue;
}
//增加一个元素
void enqueue(SeqQueue *queue, ElemType date)
{
    if ((queue->rear + 1) % MAX_SIZE == queue->front)
        return;
    queue->date[queue->rear] = date;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
}
//删除一个元素
void dequeue(SeqQueue *queue)
{
    if (queue->front == queue->rear)
        return;
    queue->front = (queue->front + 1) % MAX_SIZE;
}

bool empty(SeqQueue *queue)
{
    if (queue->front == queue->rear)
        return true;
    return false;
}