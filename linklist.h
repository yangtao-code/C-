#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node
{
    int date;
    struct Node *next;
} Node, *Linklist;

//创建一个头结点
Linklist list_init();
//创建一个新的结点
Linklist cread_list(int date);
//在链表尾部增加一个元素
void push_back(Linklist list, int date);
//在链表头部增加一个元素
void push_front(Linklist list, int date);
//删除链表最后面的一个元素
void pop_back(Linklist list);
//删除链表第一个元素
void pop_front(Linklist list);
//获取链表最后一个元素的值,链表不能为空，否则结果未定义
int list_back(Linklist list);
//获取链表第一个元素的值,链表不能为空，否则结果未定义
int list_front(Linklist list);
//求链表元素个数
int list_size(Linklist list);
//打印链表元素
void print_list(Linklist list);
//销毁malloc开辟的空间
void destroy_list(Linklist* list);
#endif
