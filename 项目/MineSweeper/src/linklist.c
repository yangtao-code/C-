#include "linklist.h"

// 创建一个链表
Linklist *Create_Linklist()
{
    Linklist *list = (Linklist *)malloc(sizeof(Linklist));
    list->first = NULL;
    list->last = NULL;
    list->n = 0;
    return list;
}

// 创建一个新的结点
Node *Create_Node(char *date)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strncpy(node->date, date, 50);
    node->next = NULL;
    node->pre = NULL;
    return node;
}

// 销毁一个链表
void Destroy_Linklist(Linklist *list)
{
    if (list->n = 0)
    {
        printf("list is emtpy!\n");
        return;
    }
    int n = list->n;
    Node *p = list->first;
    while (n--)
    {
        Node *tmp = p;
        p = p->next;
        free(tmp);
    }
    free(list);
}

// 给链表增加一个结点
void Push_Linklist(Linklist *list, char date[50])
{
    Node *node = Create_Node(date);
    list->n++;
    if (list->n == 1)
    {
        node->next = node;
        node->pre = node;
        list->first = node;
        list->last = node;
        return;
    }
    node->next = list->first;
    node->pre = list->last;
    list->first->pre = node;
    list->last->next = node;
    list->last = list->last->next;
}