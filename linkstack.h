#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct Node1
{
    ElemType date;
    struct Node1 *next;
} Node1, *LinkList1;

typedef struct LinkStack
{
    LinkList1 front;
    LinkList1 rear;
} LinkStack;

LinkStack* Create_Stack();
void EnStack(LinkStack *stack, ElemType date);
void DeStack(LinkStack *stack);
ElemType Get_Stack_Top(LinkStack *stack);
int Stack_Size(LinkStack *stack);
void Print_Stack(LinkStack *stack);
void Destroy_Stack(LinkStack *stack);
bool Stack_Empty(LinkStack *stack);

#endif
