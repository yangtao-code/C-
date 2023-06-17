/*
    双向循环链表
*/
#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char date[50];     // 数据域,存储文件名字
    struct Node *next; // 这个结点的下一个结点
    struct Node *pre;  // 这个结点的上一个结点
} Node;

typedef struct Linklist
{
    Node *first; // 链表的第一个元素
    Node *last;  // 链表的最后一个元素
    int n;       // 链表元素个数
} Linklist;

// 创建一个链表
Linklist *Create_Linklist();

// 创建一个新的结点
Node *Create_Node(char *date);

// 销毁一个链表
void Destroy_Linklist(Linklist *list);

// 给链表增加一个结点
void Push_Linklist(Linklist* list,char date[50]);

#endif