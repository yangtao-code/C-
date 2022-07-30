#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

BNode *create_btree(int *a, int sz)
{
    BNode *root = NULL;
    if (sz == 0)
        return root;
    for (int i = 0; i < sz; i++)
    {
        root = insert(root, a[i]);
    }
    return root;
}

BNode *insert(BNode *root, ElemType date)
{
    if (root == NULL)
    {
        root = (BNode *)malloc(sizeof(BNode));
        root->date = date;
        root->lchild = NULL;
        root->rchild = NULL;
        return root;
    }
    if (date <= root->date)
    {
        root->lchild = insert(root->lchild, date);
    }
    else
    {
        root->rchild = insert(root->rchild, date);
    }
    return root;
}

void mid_order(BNode *root)
{
    if (root == NULL)
        return;

    mid_order(root->lchild);
    printf("%d ", root->date);
    mid_order(root->rchild);
}

BNode *search(BNode *root, ElemType value)
{
    if (root == NULL || root->date == value)
        return root;
    if (value < root->date)
        return search(root->lchild, value);
    return search(root->rchild, value);
}

BNode *deleteNode(BNode *root, ElemType value)
{
    //要删除的数不存在，
    if (root == NULL)
        return root;
    //如果要删除的数小于root的值，说明在左子树
    if (value < root->date)
    {
        root->lchild = deleteNode(root->lchild, value);
        return root;
    }
    //如果要删除的数大于root的值，说明在右子树
    else if (value > root->date)
    {
        root->rchild = deleteNode(root->rchild, value);
        return root;
    }
    else
    {
        if (root->lchild == NULL)
        {
            BNode *tmp = root;
            root = root->rchild;
            free(tmp);
            return root;
        }
        else if (root->rchild == NULL)
        {
            BNode *tmp = root;
            root = root->lchild;
            free(tmp);
            return root;
        }
        else
        {
            ElemType tmp = minvalueNode(root->lchild);
            root->date = tmp;
            root->lchild = deleteNode(root->lchild, tmp);
            return root;
        }
    }
}

ElemType minvalueNode(BNode *root)
{
    while (root->rchild != NULL)
    {
        root = root->rchild;
    }
    return root->date;
}