#include "linklist.h"

int main(int argc, char const *argv[])
{
    //初始化头结点
    Linklist head = list_init();
    printf("%p\n", head);
    printf("%p\n", head->next);

    print_list(head);

    push_front(head, 10);
    push_front(head, 20);
    push_front(head, 30);
    print_list(head);
    printf("size:%d\n", list_size(head));

    sort_list(head);
    print_list(head);
    printf("size:%d\n", list_size(head));


    printf("%d\n",list_front(head));
    printf("%d\n",list_back(head));

    // pop_front(head);
    // print_list(head);
    // printf("size:%d\n", list_size(head));

    pop_back(head);
    print_list(head);
    printf("size:%d\n", list_size(head));

    // push_back(head,50);
    // print_list(head);
    // printf("size:%d\n", list_size(head));

    destroy_list(&head);
    return 0;
}
