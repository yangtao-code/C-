#include <stdio.h>
#include <math.h>

// int main()
// {
//     int i = 1;
//     if (i >= 0)
//         ;
//     return 0;
// }

// int main()
// {
//     int i=1;
//     if(i=2)
//     {
//         printf("%d\n",i);
//     }
//     else
//         printf("0\n");
//     return 0;
// }

// int main()
// {
//     int a;
//     a = (int)((double)(3 / 2) + 0.5 + (int)1.99 * 2);
//     printf("%d\n", a);
//     return 0;
// }

// int main()
// {
//     float x = 2.5, y = 4.7;
//     int a = 7;
//     float z = x + a % 3 * (int)(x + y) % 2 / 4;
//     printf("%lf\n", z);
//     return 0;
// }

// int Print1(int b, int arr[100], int n)
// {
//     for(n=0;n<100;n++)
//     {
//         arr[n]=b%10;
//         if((b%10)!=0)
//         {
//             b=b/10;
//         }
//         else
//         {
//             break;
//         }
//     }
//     return arr[100];
// }

// int main()
// {
//     int a = 0;
//     int arr[100] = {0};
//     int n = 0;
//     int m = 0;
//     printf("水仙花数有：\n");
//     for (int i = 1; i <= 10000; i++)
//     {
//         Print1(i, arr, n);
//         for (int j = 0; j < 100; j++)
//         {
//             m += pow(arr[j], 3);
//         }
//         if (m == i)
//         {
//             printf("%d ", i);
//         }
//     }
//     printf("\n");
//     return 0;
// }

int main()
{
    int a = 0;
    scanf("%d", &a);
    for (int i = 31; i >= 0; i--)
    {
        printf("%d ", 1 & (a >> i));
    }
    printf("\n");
    return 0;
}

// int main()
// {
//     int i=1;
//     int j=1;
//     for(i=1;i<=9;i++)
//     {
//         for(j=1;j<=i;j++)
//         {
//             printf("%d*%d=%2d ",i,j,i*j);
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     int sum = 0;
//     int i = 1;
//     do
//     {
//         sum += i;
//         i++;
//     } while (i <= 100);
//     printf("sum=%d\n", sum);
//     return 0;
// }

// int main()
// {
//     int a;
//     scanf("%d", &a);
//     int q = a / 1000;
//     int b = (a % 1000) / 100;
//     int s = a % 100 / 10;
//     int g = a % 10;
//     a = q + b * 10 + s * 100 + g * 1000;
//     printf("%d", a);
//     return 0;
// }

// int main()
// {
//     int i = 1;
//     int sum = 0;
//     while (i <= 100)
//     {
//         if (i % 2 == 0)
//         {
//             i++;
//             continue;
//         }
//         else
//         {
//             i++;
//             sum += i;
//         }
//     }
//     printf("%d\n", sum);
//     return 0;
// }
// int main()
// {
//     int a;
//     int b;
//     int c;
//     int s = 0;
//     printf("*****************\n");
//     printf("**1.加法  0.退出**\n");
//     printf("*****************\n");
// again:
//     printf("请选择:>");
//     scanf("%d", &c);
//     if (c == 1)
//     {
//         printf("请输入两个数:>");
//         scanf("%d%d", &a, &b);
//         goto add;
//     }
//     else
//     {
//         printf("选择错误，请重新选择！\n");
//         goto again;
//     }
// add:
//     s = a + b;
//     printf("%d\n", s);
//     return 0;
// }

// int main()
// {
//     int sum = 0;
//     int i = 1;
// again:
//     sum += i;
//     i += 2;
//     if (i <= 100)
//     {
//         goto again;
//     }
//     printf("%d\n", sum);
//     return 0;
// }
