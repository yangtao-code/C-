#include <stdio.h>
#include "fun.h"

int main(int argc, char const *argv[])
{
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    fun6(a);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // float a;
    // printf("请输入一个浮点数：");
    // scanf("%f", &a);
    // printf("%lf\n", fun5(a));

    // int a[N][N] = {1, 2, 3, 4,
    //                5, 6, 7, 8,
    //                9, 10, 11, 12,
    //                13, 14, 15, 16};
    // fun3(a, 2);
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         printf("%-3d", a[i][j]);
    //     }
    //     printf("\n");
    // }

    // double aver = fun4(a);
    // printf("aver = %lf\n", aver);

    // Stu a[5] = {{"ych1", 60}, {"ych2", 70}, {"ych3", 50}, {"ych4", 80}, {"ych5", 100}};
    // Stu s;
    // fun2(a, &s);
    // printf("name: %s\nscore: %d\n", s.name, s.score);

    // char str[100];
    // scanf("%s", str);
    // int count = fun1(str);
    // printf("count = %d\n", count);
    return 0;
}
