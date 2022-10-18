#include <stdio.h>

void foo()
{
    printf("hello world!\n");
}

int main()
{
#ifdef DBUG
    foo();
#endif
    return 0;
}

// #define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

// struct Lin
// {
//     int a;
//     struct Lin* p;
// };

// int main()
// {
//     getc;
//     int x = 1, y = 2;
//     int min = MIN(x, y);
//     printf("%d", min);
//     return 0;
// }