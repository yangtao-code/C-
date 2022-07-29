#include "btree.h"
#include "linkqueue.h"
#include <stdio.h>
#include <stdlib.h>

BNode *create_btree()
{
    BNode *root = NULL;
    ElemType1 tmp;
    scanf("%c", &tmp);
    if (tmp != '#')
    {
        root = (BNode *)malloc(sizeof(BNode));
        root->date = tmp;
        root->lchild = create_btree();
        root->rchild = create_btree();
    }
    return root;
}

void pre_order(BNode *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->date);
    pre_order(root->lchild);
    pre_order(root->rchild);
}

void mid_order(BNode *root)
{
    if (root == NULL)
        return;
    mid_order(root->lchild);
    printf("%c ", root->date);
    mid_order(root->rchild);
}

void post_order(BNode *root)
{
    if (root == NULL)
        return;
    post_order(root->lchild);
    post_order(root->rchild);
    printf("%c ", root->date);
}

void level_order(BNode *root)
{
    LinkQueue *queue = Cread_Queue();
    EnQueue(queue, root);
    while (Queue_Empty(queue) != 1)
    {
        ElemType tmp = queue->front->date;
        DeQueue(queue);
        printf("%c ", tmp->date);
        if (tmp->lchild != NULL)
            EnQueue(queue, tmp->lchild);
        if (tmp->rchild != NULL)
            EnQueue(queue, tmp->rchild);
    }
}