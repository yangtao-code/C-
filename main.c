#include <stdio.h>
#include "btree.h"

int main(int argc, char const *argv[])
{
    int a[] = {100,213, 42, 13, 6, 1, 334, 13, 77};
    int sz = sizeof(a) / sizeof(a[0]);
    //创建二叉排序树
    BNode *root = create_btree(a, sz);

    mid_order(root);
    printf("\n");

    BNode *ret = search(root, 14);
    if (ret == NULL)
        printf("搜索的数不存在\n");
    else
        printf("找到了\n");

    deleteNode(root, 213);
    mid_order(root);
    printf("\n");

    return 0;
}
