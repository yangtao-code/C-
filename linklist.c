#include "linklist.h"

Linklist list_init()
{
    Linklist phead = cread_list(0);
    return phead;
}

Linklist cread_list(int date)
{
    Linklist list = (Linklist)malloc(sizeof(DNode));
    list->date = date;
    list->prior = NULL;
    list->next = NULL;
    return list;
}

void push_back(Linklist list, int date)
{
    if (list == NULL)
        return;
    Linklist p = cread_list(date);
    while (list->next != NULL)
    {
        list = list->next;
    }
    list->next = p;
    p->prior = list;
}

void push_front(Linklist list, int date)
{
    if (list == NULL)
        return;
    Linklist p = cread_list(date);
    p->next = list->next;
    p->prior = list;
    list->next = p;
}

void pop_back(Linklist list)
{
    if (list == NULL || list->next == NULL)
        return;
    Linklist p = NULL;
    while (list->next)
    {
        p = list;
        list = list->next;
    }
    p->next = NULL;
    free(list);
    list == NULL;
}

void pop_front(Linklist list)
{
    if (list->next == NULL || list == NULL)
        return;
    Linklist p = list->next;
    p = p->next;
    free(list->next);
    list->next = p;
    p->prior = list;
} 

int list_back(Linklist list)
{
    while (list->next)
    {
        list = list->next;
    }
    return list->date;
}

int list_front(Linklist list)
{
    list = list->next;
    return list->date;
}

int list_size(Linklist list)
{
    int ret = 0;
    while (list->next)
    {
        list = list->next;
        ret++;
    }
    return ret;
}

void print_list(Linklist list)
{
    if (list == NULL)
        return;
    if (list->next == NULL)
    {
        printf("当前链表为空！\n");
        return;
    }
    list = list->next;
    while (list != NULL)
    {
        printf("%d ", list->date);
        list = list->next;
    }
    printf("\n");
}

void destroy_list(Linklist *list)
{
    Linklist p = NULL;
    while (*list)
    {
        p = (*list);
        *list = (*list)->next;
        free(p);
        p = NULL;
    }
}