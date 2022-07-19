#include "linklist.h"

Linklist list_init()
{
    Linklist phead = cread_list(0);
    return phead;
}

Linklist cread_list(int date)
{
    Linklist list = (Linklist)malloc(sizeof(Node));
    list->date = date;
    list->next = NULL;
    return list;
}

void push_back(Linklist list, int date)
{
    Linklist p = cread_list(date);
    while (list->next)
    {
        list = list->next;
    }
    list->next = p;
}

void push_front(Linklist list, int date)
{
    Linklist p = cread_list(date);
    p->next = list->next;
    list->next = p;
}

void pop_back(Linklist list)
{
    Linklist p = NULL;
    if (list->next == NULL)
        return;
    while (list->next)
    {
        p = list;
        list = list->next;
    }
    free(list);
    list == NULL;
    p->next = NULL;
}

void pop_front(Linklist list)
{
    Linklist p = list->next;
    if (list->next == NULL)
        return;
    p = p->next;
    free(list->next);
    list->next = p;
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
    if (list->next == NULL)
    {
        printf("当前链表为空！\n");
        return;
    }
    list = list->next;
    while (1)
    {
        printf("%d ", list->date);
        list = list->next;
        if (list == NULL)
            break;
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