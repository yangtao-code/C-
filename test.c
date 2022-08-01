#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief 判断是否为质数
 * 
 * @param a 
 * @return true 返回true为是质数
 * @return false 返回false不是质数
 */
bool is_prier(int a);

/**
 * @brief 去除字符串中的空格
 * 
 * @param str 
 */
void del_space_char(char *str);

void the_most_buygoods();

int main(int argc, char const *argv[])
{
    the_most_buygoods();
    return 0;
}

void the_most_buygoods()
{
    int goods_pride[5] = {13, 15, 12, 18, 10};
    int money = 50; //自己有多少钱
    int goods_num[5];   //购买商品的数量
    int k;
    int arr[32];    //
    for (k = 0; k < 32; k++)
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            goods_num[i] = !!(k & (1 << i));
            sum = sum + goods_num[i] * goods_pride[i];
        }
        if (sum < money)
            arr[k] = money - sum;
        else
            arr[k] = sum - money;
    }
    int n = 0;
    for (k = 0; k < 32; k++)
    {
        if (arr[n] > arr[k])
            n = k;
    }
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        int a = !!(n & (1 << i));
        goods_num[i] = a;
        sum = sum + goods_pride[i] * a;
    }
    printf("最优解为：\n");
    for(int i=0;i<5;i++)
    {
        printf("%c: %d\n",'A'+i,goods_num[i]);
    }
    printf("%d\n", sum);
}

// int main()
// {
//     char str[256];
//     int i, j;
//     gets(str);
//     for (i = 0; str[i] != '\0'; i++)
//     {
//         if (i == 0)
//             printf("%c", str[i]);
//         else
//         {
//             for (j = 0; j < i; j++)
//             {
//                 if (str[i] == str[j])
//                     break;
//             }
//             if (i == j)
//                 printf("%c", str[i]);
//         }
//     }
//     printf("\n");
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     char str[256];
//     printf("请输入一段字符串：");
//     gets(str);

//     del_space_char(str);
//     printf("%s\n", str);

//     return 0;
// }

void del_space_char(char *str)
{
    char tmp[100];
    int i = 0;
    int k = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            ;
        else
        {
            tmp[k] = str[i];
            k++;
        }
        i++;
    }
    strcpy(str, tmp);
}

// int main(int argc, char const *argv[])
// {
//     int a;
//     printf("请输入一个正数:");
//     scanf("%d", &a);

//     //a是质数，直接输出，不是执行else
//     if (is_prier(a))
//     {
//         printf("%d\n", a);
//     }
//     else
//     {
//         for (int i = a - 1, j = a + 1; i > 2; i--, j++)
//         {
//             if (is_prier(i) && is_prier(j))
//             {
//                 printf("%d,%d\n", i, j);
//                 break;
//             }
//             else if (is_prier(i))
//             {
//                 printf("%d\n", i);
//                 break;
//             }
//             else if (is_prier(j))
//             {
//                 printf("%d\n", j);
//                 break;
//             }
//         }
//     }
//     return 0;
// }

bool is_prier(int a)
{
    for (int i = 2; i <= a / 2; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}