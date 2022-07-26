#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 6

typedef int ElemType;

typedef struct SeqQueue
{
    int front;
    int rear;
    ElemType *date;

} SeqQueue;
//创建一个队列
SeqQueue *cread_queue();
//增加一个元素
void enqueue(SeqQueue *queue, ElemType date);
//删除一个元素
void dequeue(SeqQueue *queue);

bool empty(SeqQueue *queue);

#endif