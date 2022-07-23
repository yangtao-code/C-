#include "linkstack.h"

LinkStack *Create_Stack()
{
    LinkStack *p = (LinkStack *)malloc(sizeof(LinkStack));
    p->front = NULL;
    p->rear = NULL;
}

void EnStack(LinkStack *stack, ElemType *date)
{
    LinkList1 p = (LinkList1)malloc(sizeof(Node1));
    strcpy(p->date, date);
    p->next = stack->front;
    if (Stack_Empty(stack))
    {
        stack->front = p;
        stack->rear = p;
    }
    else
    {
        p->next = stack->front;
        stack->front = p;
    }
}

void DeStack(LinkStack *stack)
{
    if (Stack_Empty(stack))
        return;
    LinkList1 p = stack->front;
    stack->front = stack->front->next;
    free(p);
    p = NULL;
}

ElemType* Get_Stack_Top(LinkStack *stack)
{
    return stack->front->date;
}

int Stack_Size(LinkStack *stack)
{
    int size = 0;
    LinkList1 p = stack->front;
    while (p)
    {
        size++;
        p = p->next;
    }
    return size;
}

bool Stack_Empty(LinkStack *stack)
{
    return stack->front == NULL;
}

void Print_Stack(LinkStack *stack)
{
    LinkList1 p = stack->front;
    while (p)
    {
        printf("%s\n", p->date);
        p = p->next;
    }
}

void Destroy_Stack(LinkStack *stack)
{
    while (Stack_Empty(stack))
    {
        LinkList1 p = stack->front;
        stack->front = stack->front->next;
        free(p);
        p = NULL;
    }
}