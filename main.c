#include "linklist.h"

int main(int argc, char const *argv[])
{
    Linklist head = list_init();

    push_back(head, 10);
    push_back(head, 20);
    push_back(head, 30);
    push_back(head, 40);
    print_list(head);
    printf("%d\n", list_size(head));

    push_front(head, 50);
    print_list(head);
    printf("%d\n", list_size(head));

    pop_back(head);
    print_list(head);
    printf("%d\n", list_size(head));

    pop_front(head);
    print_list(head);

    printf("%d\n", list_size(head));

    printf("%d\n", list_back(head));

    printf("%d\n", list_front(head));

    destroy_list(&head);
    return 0;
}
