#include "linkqueue.h"

LinkQueue *Cread_Queue()
{
    LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void EnQueue(LinkQueue *queue, ElemType date)
{
    LinkList p = (LinkList)malloc(sizeof(Node));
    p->date = date;
    p->next = NULL;
    if (Queue_Empty(queue))
    {
        queue->front = p;
        queue->rear = p;
    }
    else
    {
        queue->rear->next = p;
        queue->rear = queue->rear->next;
    }
}

void DeQueue(LinkQueue *queue)
{
    if (Queue_Empty(queue))
        return;
    LinkList p = queue->front;
    queue->front = queue->front->next;
    free(p);
    p = NULL;
}

bool Queue_Empty(LinkQueue *queue)
{
    return queue->front == NULL;
}

void Destroy_Queue(LinkQueue *queue)
{
    while (!Queue_Empty(queue))
    {
        LinkList p = queue->front;
        queue->front = queue->front->next;
        free(p);
        p = NULL;
    }
}

void Print_Queue(LinkQueue *queue)
{
    LinkList p = queue->front;
    while (p)
    {
        printf("%d ", p->date);
        p = p->next;
    }
    printf("\n");
}

int Queue_Size(LinkQueue *queue)
{
    LinkList p = queue->front;
    int ret = 0;
    while (p)
    {
        ret++;
        p = p->next;
    }
    return ret;
}