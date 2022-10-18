#include <stdio.h>
#include <math.h>

// int main()
// {
//     char a=250;
//     unsigned char f;
//     f=a+249;
//     printf("%d\n",f);
//     printf("%u\n",f);
//     char g;
//     g=a+249;
//      printf("%d\n",g);
//      printf("%u\n",g);
// }
// int main()
// {
//     int score;
//     scanf("%d", &score);
//     if (score >= 90)
//     {
//         printf("A\n");
//     }
//     else if (score >= 80 && score < 90)
//     {
//         printf("B\n");
//     }
//     else if (score >= 70 && score < 80)
//     {
//         printf("C\n");
//     }
//     else
//     {
//         printf("D\n");
//     }
//     return 0;
// }

void Max(int *n)
{
    int arr[10];
    int i, j;
    printf("请输入这%d数:>", *n);
    for (i = 0; i < *n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < *n; i++)
    {
        for (int j = i + 1; j < *n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(i=0;i<*n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("你要输入几个数");
    scanf("%d", &n);
    Max(&n);
    return 0;
}

// int main()
// {
//     int i;
//     printf("100~1000之间的水仙花数有：\n");
//     for (i = 100; i < 1000; i++)
//     {
//         int a = i / 100;
//         int b = i % 100 / 10;
//         int c = i % 10;
//         if (i == a * a * a + b * b * b + c * c * c)
//         {
//             printf("%d ", i);
//         }
//     }
// }
// int main()
// {
//     int n;
//     printf("请输入一个三位数:>");
//     scanf("%d", &n);
//     int a = a / 100;
//     int b = a % 100 / 10;
//     int c = a % 10;
//     int s = a ^ 3 + b ^ 3 + c ^ 3;
//     if (n == s)
//     {
//         printf("%d是一个水仙花数",n);
//     }
//     else
//     {
//         printf("%d不是一个水仙花数",n);
//     }
//     return 0;
// }

// int main()
// {
//     int a = 3;
//     int b = pow(a, 3);
//     printf("%d\n", b);
//     return 0;
// }

// int main()
// {
//     int a;
//     printf("请输入上个月的用电量：");
//     scanf("%d", &a);
//     double m = 0;
//     if (a <= 200)
//     {
//         m = a * 0.588;
//     }
//     else if (a > 200 && a <= 450)
//     {
//         m = 200 * 0.588 + (a - 200) * 0.638;
//     }
//     else
//     {
//         m = 200 * 0.588 + 250 * 0.638 + (a - 450) * 0.888;
//     }
//     printf("电费为%g\n", m);
//     return 0;
// }

// int main()
// {
//     int a = 1;
//     a = a++;
//     printf("%d\n", a);
//     return 0;
// }