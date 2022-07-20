#include "linklist.h"

Linklist list_init()
{
    Linklist list = cread_list(0);
    list->next = list;
    return list;
}

Linklist cread_list(int date)
{
    Linklist p = (Linklist)malloc(sizeof(Node));
    p->date = date;
    p->next = NULL;
    return p;
}

void push_front(Linklist list, int date)
{
    Linklist p = cread_list(date);
    p->next = list->next;
    list->next = p;
}

void push_back(Linklist list, int date)
{
    Linklist li = list;
    Linklist p = cread_list(date);
    while (li->next != list)
    {
        li = li->next;
    }
    p->next = list;
    li->next = p;
}

void pop_front(Linklist list)
{
    if (list == list->next)
        return;
    Linklist p = list->next;
    list->next = p->next;
    free(p);
    p = NULL;
}

void pop_back(Linklist list)
{
    if (list->next == list)
        return;
    Linklist p1 = list;
    Linklist p = NULL;
    while (p1->next != list)
    {
        p = p1;
        p1 = p1->next;
    }
    free(p1);
    p1 = NULL;
    p->next = list;
}

int list_front(Linklist list)
{
    return list->next->date;
}

int list_back(Linklist list)
{
    Linklist p = list;
    while (p->next != list)
    {
        p = p->next;
    }
    return p->date;
}

void sort_list(Linklist list)
{
    int len = list_size(list);
    if (len < 2)
        return;
    int tmp = 0;
    Linklist p = NULL;
    for (int i = 0; i < len - 1; i++)
    {
        p = list->next;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (p->date > p->next->date)
            {
                tmp = p->date;
                p->date = p->next->date;
                p->next->date = tmp;
            }
            p = p->next;
        }
    }
}

void print_list(Linklist list)
{
    if (list_size(list) == 0)
    {
        printf("当前无链表元素！\n");
        return;
    }
    Linklist p = list->next;
    while (p != list)
    {
        printf("%d ", p->date);
        p = p->next;
    }
    printf("\n");
}

int list_size(Linklist list)
{
    int ret = 0;
    Linklist p = list->next;
    while (p != list)
    {
        ret++;
        p = p->next;
    }
    return ret;
}

void destroy_list(Linklist *list)
{
    Linklist p1 = *list;
    Linklist p = NULL;
    while (p1->next != *list)
    {
        p = p1;
        p1 = p1->next;
        free(p);
        p = NULL;
    }
    free(*list);
    *list = NULL;
}