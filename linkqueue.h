#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"

typedef BNode* ElemType;

typedef struct Node
{
    ElemType date;
    struct Node *next;
} Node, *LinkList;

typedef struct LinkQueue
{
    LinkList front;
    LinkList rear;
} LinkQueue;

//创建一个链式队列
LinkQueue *Cread_Queue();
//增加一个队列元素
void EnQueue(LinkQueue *queue, ElemType date);
//删除队列一个元素
void DeQueue(LinkQueue *queue);
//判断队列是否为空
bool Queue_Empty(LinkQueue *queue);
//销毁队列
void Destroy_Queue(LinkQueue *queue);
//打印队列
//void Print_Queue(LinkQueue *queue);
//求队列的元素个数
int Queue_Size(LinkQueue *queue);

#endif