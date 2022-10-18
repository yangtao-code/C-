#include <stdio.h>
#include <string.h>

void f(int a, int b);
char PriStr(char ch1);
void swap(int *p1, int *p2);
void Add(int *x, int *y, int *ret);

#include <stdio.h>

int main()
{
    int a[2][2] = {12, 20, 30, 40};
    int *p;
    p = a[0];
    printf("%d", *(p + 1)+1);
    // int grid[50][100]={0};
    // grid[0][0]=1;
    // printf("%d\n",**grid);
    return 0;
}

// int main()
// {
//     int a[] = {1, 2, 3, 4, 5};
//     int *p2 = (int *)(&a + 1);
//     printf("%d,%d\n", *(a + 1), *(p2 - 1));
//     return 0;
// }

// int main()
// {
//     char ch[][5] = {"safa1", "2141d"};
//     char(*ch2)[5] = ch;
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < 5; j++)
//         {
//             printf("%c ", *(*(ch2 + i) + j));
//         }
//         printf("\n");
//     }
//     //printf("%ld\n",sizeof(int*));
//     return 0;
// }

// int main()
// {
//     int a;
//     int b;
//     int sum = 0;
//     scanf("%d%d", &a, &b);
//     Add(&a, &b, &sum);
//     printf("sum=%d\n", sum);
//     return 0;
// }
void Add(int *x, int *y, int *ret)
{
    *ret = *x + *y;
}

// int main()
// {
//     int a = 10, b = 30;
//     printf("&a=%p\n",&a);
//     printf("&b=%p\n",&b);
//     swap(&a, &b);
//     printf("a = %d,b = %d\n", a, b);
//     return 0;
// }
void swap(int *p1, int *p2)
{
    // int *t;
    // printf("t=%p\n",t);

    int t;
    t = *p1;
    *p1 = *p2;
    *p2 = t;

    // *p1 = *p1 ^ *p2;
    // *p2 = *p1 ^ *p2;
    // *p1 = *p1 ^ *p2;
}

// int main()
// {
//     int a = 10;
//     int *pa = &a;
//     printf("&a=%p\n", &a);
//     printf("&a=%p\n", pa);
//     printf("a=%d\n", a);
//     printf("a=%d\n", *pa);
//     return 0;
// }
// int main()
// {
//     char ch;
//     printf("\nPleae enter a char:");
//     ch = getchar();
//     ch = PriStr(ch);
//     if (ch == 0)
//     {
//         puts("No find,good bye!\n");
//     }
//     return 0;
// }

char PriStr(char ch1)
{
    int i = 0, j = 0;
    static char *ch2[] = {"hello world!", "glad to meet tou",
                          "anything new", "everything is fine", "avv"};
    while (i++ < 5)

        if (ch1 == *ch2[i - 1])
        {
            puts(ch2[i - 1]);
            j = 1;
        }
    return j;
}

// int main()
// {
//     int x = 1, y = 3, z = 2;
//     if (x > y)
//         f(x, y);
//     else if (y > z)
//         f(x, z);

//     printf("%d,%d,%d\n", x, y, z);
// }
void f(int a, int b)
{
    int t;
    t = a;
    a = b;
    b = t;
}