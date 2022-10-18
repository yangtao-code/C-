/**
 * @file 2test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

// int main()
// {
//     int a=0;
//     scanf("%d",&a);
//     for(int i=31;i>=0;i--)
//     {
//         if((a>>i)&1==1)
//         {
//             printf("%d ",1);
//         }
//         else
//         {
//             printf("%d ",0);
//         }
//     }
//     printf("\n");
//     return 0;
// }

// int main()
// {
//     int a;
//     int n=0;
//     scanf("%d",&a);
//     for(int i=0;i<32;i++)
//     {
//         if(1 == ((a>>i)&1))
//         {
//            n++;
//         }
//     }
//     printf("%d\n",n);
//     return 0;
// }

void print1(int a)
{
    for (int i = 31; i >= 0; i--)
    {
        if ((a >> i) & 1 == 1)
        {
            printf("%d ", 1);
        }
        else
        {
            printf("%d ", 0);
        }
    }
    printf("\n");
}

int main()
{
    int a;
    scanf("%d", &a);
    int b = a & (~(1 << 4));
    printf("%d\n", b);
    print1(a);
    print1(b);
    return 0;
}