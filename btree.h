#ifndef BREE_H_
#define BREE_H_

typedef int ElemType;

typedef struct BNode
{
    ElemType date;
    struct BNode *lchild;
    struct BNode *rchild;
} BNode;

/**
 * @brief Create a btree object
 * 
 * @param a 数组
 * @param sz 数组元素个数
 * @return BNode* 
 */
BNode *create_btree(int *a, int sz);

/**
 * @brief 为二叉排序树插入一个数
 * 
 * @param root 树根
 * @param date 数据
 */
BNode *insert(BNode *root, ElemType date);

/**
 * @brief 中序遍历
 * 
 * @param root 
 */
void mid_order(BNode *root);


/**
 * @brief 搜索指定的数，返回NULL为不存在
 * 
 * @param root 
 * @param value 要查找的数
 * @return BNode* 
 */
BNode *search(BNode *root, ElemType value);

/**
 * @brief 删除指定的元素
 * 
 * @param root 
 * @param value 
 * @return BNode* 
 */
BNode *deleteNode(BNode *root, ElemType value);

/**
 * @brief 找到
 * 
 * @param root 
 * @return ElemType 
 */
ElemType minvalueNode(BNode *root);

#endif