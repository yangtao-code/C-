#ifndef BTREE_H_
#define BTREE_H_

typedef char ElemType1;

typedef struct BNode
{
    ElemType1 date;
    struct BNode *lchild;
    struct BNode *rchild;
} BNode;

//创建二叉树
BNode *create_btree();
//先序遍历
void pre_order(BNode *root);
//中序遍历
void mid_order(BNode *root);
//后序遍历
void post_order(BNode *root);
//层次遍历
void level_order(BNode *root);

#endif