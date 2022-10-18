#include <stdio.h>

#define MIN(X, Y) X < Y ? X : Y

int main()
{
    int x = 1, y = 2;
    int min = MIN(x, y);
    printf("%d", min);
    return 0;
}

// typedef struct Test
// {
//     int a;
//     int b;
// }Test;

// int main()
// {
//     Test t;

//     return 0;
// }

// int main()
// {
//     int a=1;
//     char c=(char)a;
//     if(c==1)
//     {
//         printf("小端！\n");
//     }
//     else if(c==0)
//     {
//         printf("大端！\n");
//     }
//     return 0;
// }

// union Test
// {
//     int a;
//     char c;
// };

// typedef union
// {
//     short a;
//     char c;
// } Test;

// int main()
// {
//     union Test t;
//     t.a=1;
//     if(t.c==1)
//     {
//         printf("小端！\n");
//     }
//     else if(t.c==0)
//     {
//         printf("大端！\n");
//     }
//     return 0;
// }

// typedef struct Student
// {
//     int id;
//     char s;
//     char name[20];
//     double score[];
// }Stu;

// int main()
// {
//     printf("%ld\n",sizeof(Stu));
//     return 0;
// }