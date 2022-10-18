#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
/**
 * @brief 实现数组的输入
 * 
 * @param arr 数组名
 * @param len 数组长度
 */
void input_array(int arr[], int len)
{
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand();
    }
}

/**
 * @brief 实现数组的打印
 * 
 * @param arr 数组名
 * @param len 数组长度
 */
void print_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief 求数组最大值
 * 
 * @param arr 数组名
 * @param len 数组长度
 * @return int 返回数组的最大值
 */
int array_max(int arr[], int len)
{
    int max = arr[0];
    for (int i = 0; i < len; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

/**
 * @brief 求数组最小值
 * 
 * @param arr 数组名
 * @param len 数组长度
 * @return int 返回数组最小值
 */
int array_min(int arr[], int len)
{
    int min = arr[0];
    for (int i = 0; i < len; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

/**
 * @brief 求数组所有元素的平均值
 * 
 * @param arr 数组名
 * @param len 数组长度
 * @return int 返回平均值
 */
int array_average(int arr[], int len)
{

    int average;
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    average = sum / len;
    return average;
}
// int main()
// {
//     int arr[100];
//     int len;
//     int max, min, average;
//     printf("你想输入几个数：");
//     scanf("%d", &len);
//     input_array(arr, len);
//     print_array(arr, len);
//     max = array_max(arr, len);
//     min = array_min(arr, len);
//     average = array_average(arr, len);
//     printf("max=%d \nmin=%d \naverage=%d\n", max, min, average);
//     return 0;
// }

/**
 * @brief 计算三个数的最大值
 * 
 */
void print_max()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int max;
    if (a > b && a > c)
    {
        max = a;
    }
    else if (b > a && b > c)
    {
        max = b;
    }
    else
    {
        max = c;
    }
    printf("max=%d\n", max);
}

/**
 * @brief 判断这一年是不是闰年
 * 
 */
void year()
{
    int year;
    printf("请输入一个年份：");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        printf("%d是闰年！\n", year);
    }
    else
    {
        printf("%d不是闰年！\n", year);
    }
}

/**
 * @brief 判断一个数是否水仙花数
 * 
 */
void if_shuixinghua()
{
    int a;
    int arr[10];
    int k = 0;
    printf("请输入一个数：");
    scanf("%d", &a);
    int b = a;
    while (a != 0)
    {
        arr[k] = a % 10;
        a = a / 10;
        k++;
    }
    int sum = 0 ;
    for (int i = 0; i < k; i++)
    {
        sum += pow(arr[i], 3);
    }
    if (sum == b)
    {
        printf("%d是水仙花数！\n", b);
    }
    else
    {
        printf("%d不是水仙花数！\n", b);
    }
}

int main()
{
    //print_max();
    //year();
    if_shuixinghua();
    return 0;
}

// int main()
// {
//     int i, n[4] = {1};
//     for (i = 1; i <= 3; i++)
//     {
//         n[i] = n[i - 1] * 2 + 1;
//         printf("%d ", n[i]);
//     }
//     printf("\n");
//     return 0;
// }

// int main()
// {
//     int num[26] = {0};
//     int ch;
//     while ((ch = getchar()) != '#')
//     {
//         if (ch >= 'A' && ch <= 'Z')
//         {
//             num[ch - 'A']++;
//         }
//     }
//     for (int i = 0; i < 26; i++)
//     {
//         printf("%c: %d\n", 'A' + i, num[i]);
//     }
//     return 0;
// }

// int main()
// {
//     int n;
//     while (1)
//     {
//         int r = scanf("%d", &n);
//         printf("r=%d,n=%d\n", r, n);
//         if (r == 0)
//         {
//             while (getchar() != '\n')
//                 ;

//             printf("输入错误,请重新输入！\n");
//             continue;
//         }
//     }
//     return 0;
// }

// int main()
// {
//     int n = 0;
//     again:
//     int r = scanf("%d", &n);
//     if(r==0)
//     {
//         printf("输入错误，请重新输入！\n");
//         goto again;
//     }
//     printf("r=%d,n=%d\n", r, n);
//     return 0;
// }