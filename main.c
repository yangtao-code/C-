#include "linklist.h"

int main(int argc, char const *argv[])
{
    Linklist head = list_init();

    push_back(head, 100);
    push_back(head, 200);
    push_back(head, 300);
    print_list(head);
    printf("size: %d\n", list_size(head));

    push_front(head, 400);
    print_list(head);
    printf("size: %d\n", list_size(head));

    pop_back(head);
    print_list(head);
    printf("size: %d\n", list_size(head));

    pop_front(head);
    print_list(head);
    printf("size: %d\n", list_size(head));

    printf("%d\n", list_front(head));
    printf("%d\n", list_back(head));

    destroy_list(&head);
    return 0;
}
