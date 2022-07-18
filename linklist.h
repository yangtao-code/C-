#ifndef LINKLIST_H_
#define LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int date;
    struct Node *next;
};
typedef struct Node Node;
typedef struct Node *Linklist;

Linklist cread_node(int date);
//将整数值插到链表尾
void push_back(Linklist *list, int a);
//将整数插入链表头
void push_front(Linklist *list, int a);
//求链表的长度
size_t list_size(Linklist list);
//打印链表
void print_list(Linklist list);
//删除链表最后一个元素
void pop_back(Linklist *list);
//删除链表第一个元素
void pop_front(Linklist *list);
//释放链表开辟的空间
void destroy_list(Linklist list);
//按从大到小排序
void sort_list(Linklist* list);
#endif