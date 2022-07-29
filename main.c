#include <stdio.h>
#include "btree.h"

int main(int argc, char const *argv[])
{
    BNode *root = create_btree();

    pre_order(root);
    printf("\n");

    mid_order(root);
    printf("\n");

    post_order(root);
    printf("\n");

    level_order(root);
    printf("\n");
    
    return 0;
}
