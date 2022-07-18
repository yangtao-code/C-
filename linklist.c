#include "Linklist.h"

Linklist cread_node(int date)
{
    Linklist p = (Linklist)malloc(sizeof(Node));
    p->date = date;
    p->next = NULL;
}

void push_back(Linklist *list, int date)
{
    Linklist p = cread_node(date);
    if (*list == NULL)
    {
        *list = p;
    }
    else
    {
        Linklist tmp = *list;
        while (1)
        {
            if (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            else
            {
                break;
            }
        }
        tmp->next = p;
    }
}

void push_front(Linklist *list, int date)
{
    Linklist p = cread_node(date);
    if (*list == NULL)
    {
        *list = p;
        return;
    }
    p->next = *list;
    *list = p;
}

size_t list_size(Linklist list)
{
    if (list == NULL)
    {
        return 0;
    }
    else
    {
        size_t ret = 0;
        while (list != NULL)
        {
            ++ret;
            list = list->next;
        }
        return ret;
    }
}

void print_list(Linklist list)
{
    if (list == NULL)
    {
        printf("当前链表元素为零！");
        return;
    }
    while (list)
    {
        printf("%d ", list->date);
        list = list->next;
    }
    printf("\n");
}

void destroy_list(Linklist list)
{
    Linklist p = NULL;
    while (list != NULL)
    {
        p = list;
        list = list->next;
        free(p);
        p = NULL;
    }
}

void pop_back(Linklist *list)
{
    Linklist p1 = *list;
    if (p1 == NULL)
    {
        return;
    }
    else if (p1->next == NULL)
    {
        free(p1);
        p1 = NULL;
        return;
    }
    Linklist p2 = NULL;
    while (1)
    {
        p2 = p1;
        p1 = p1->next;
        if (p1->next == NULL)
        {
            free(p1);
            p1 = NULL;
            p2->next = NULL;
            break;
        }
    }
}

void pop_front(Linklist *list)
{
    Linklist p = *list;
    if (p == NULL)
    {
        return;
    }
    else if (p->next == NULL)
    {
        free(p);
        p = NULL;
        return;
    }
    *list = (*list)->next;
    free(p);
    p = NULL;
}

void sort_list(Linklist *list)
{
    Linklist p = NULL;
    Linklist tmp = (Linklist)malloc(sizeof(Node));
    int n = list_size(*list);
    for (int i = 0; i < n - 1; i++)
    {
        p = *list;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p->date > p->next->date)
            {
                tmp->date = p->date;
                p->date = p->next->date;
                p->next->date = tmp->date;
            }
            p = p->next;
        }
    }
}