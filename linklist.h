#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int date;
    struct Node *next;
} Node, *Linklist;

//初始化头结点
Linklist list_init();
//创建一个新的结点
Linklist cread_list(int date);
//在链表头部增加一个元素
void push_front(Linklist list, int date);
//在链表尾部增加一个元素
void push_back(Linklist list, int date);
//删除链表第一个元素
void pop_front(Linklist list);
//删除链表第一个元素
void pop_back(Linklist list);
//求链表第一个元素,链表不能为控，否则结果未定义
int list_front(Linklist list);
//求链表最后一个元素,链表不能为控，否则结果未定义
int list_back(Linklist list);
//为链表所有元素按从大到小排序
void sort_list(Linklist list);
//打印链表中的所有元素
void print_list(Linklist list);
//求链表的长度
int list_size(Linklist list);
//销毁链表所有元素
void destroy_list(Linklist *list);
#endif