#include "linklist.h"

int main(int argc, char const *argv[])
{
    Linklist list = NULL;

    push_back(&list, 20);
    push_back(&list, 3);
    push_back(&list, 14);
    printf("size: %ld\n", list_size(list));
    print_list(list);

    push_front(&list, 10);
    print_list(list);

    // pop_back(&list);
    // print_list(list);

    // pop_front(&list);
    // print_list(list);

    sort_list(&list);
    print_list(list);

    destroy_list(list);
    return 0;
}
