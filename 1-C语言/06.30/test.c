#include <stdio.h>
#include <stdbool.h>

int init(int array[])
{
    printf("数组初始化\n");
    int k = 0;
    printf("你要输入几个数：");
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return k;
}

void reverse(int array[], int k)
{
    printf("倒置数组\n");
    for (int i = 0, j = k - 1; i < j; i++, j--)
    {
        array[i] = array[i] ^ array[j];
        array[j] = array[i] ^ array[j];
        array[i] = array[i] ^ array[j];
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void empty(int array[], int k)
{
    printf("数组置零\n");
    for (int i = 0; i < k; i++)
    {
        array[i] = '\0';
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int arr[100];
    int len = 0;
    len = init(arr);
    reverse(arr, len);
    empty(arr, len);
    return 0;
}

// int main()
// {
//     int a[][3] = {1, 2, 3, 4, 5, 6, 7};
//     int sz = (sizeof(a) / sizeof(a[0][0])) / 3;
//     for (int i = 0; i < sz; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// int main()
// {
//     while (1)
//     {
//         int n;
//         int r = scanf("%d", &n);
//         if (r == 0)
//         {
//             printf("输入错误，请重新输入！\n");
//             continue;
//         }
//         printf("r=%d,n=%d\n", r, n);

//     }
//     return 0;
// }

// int main()
// {
//     int arr[100] = {0};
//     int tep = 0;
//     int k = 0; //比较数的个数
//     printf("你想比较几个数的大小：");
//     scanf("%d", &k);
//     for (int i = 0; i < k; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     for (int i = 0; i < k; i++)
//     {
//         int min = arr[i];
//         for (int j = i; j < k; j++)
//         {
//             if (arr[j] < min)
//             {
//                 min = arr[j];
//                 arr[j] = arr[i];
//             }
//             arr[i] = min;
//         }
//         bool flag = true;
//         for (int j = 0; j < k - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 flag = false;
//                 break;
//             }
//         }

//         for (int j = 0; j < k; j++)
//         {
//             printf("%d ", arr[j]);
//         }
//         printf("\n");
//         if (flag == true)
//         {
//             break;
//         }
//     }

//     return 0;
// }

// int main()
// {
//     int arr[5] = {0};
//     int tep = 0;
//     for (int i = 0; i < 5; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         int min = arr[i];
//         for (int j = i; j < 5; j++)
//         {
//             if (arr[j] < min)
//             {
//                 min = arr[j];
//                 arr[j] = arr[i];
//             }
//             arr[i] = min;
//         }
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     return 0;
// }

// int main()
// {
//     int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int k = 0;
//     for (int j = 0; j < 10; j++)
//     {
//         printf("%d ", a[j]);
//     }
//     printf("\n");
//     for (int i = 0; i < 10 - 1; i++)
//     {
//         for (int j = 0; j < 10 - i - 1; j++)
//         {
//             if (a[j] < a[j + 1])
//             {
//                 a[j] = a[j] ^ a[j + 1];
//                 a[j + 1] = a[j] ^ a[j + 1];
//                 a[j] = a[j] ^ a[j + 1];
//                 k++;
//             }
//             for (int j = 0; j < 10; j++)
//             {
//                 printf("%d ", a[j]);
//             }
//             printf("\n");
//         }

//         printf("--------------------\n");
//     }
//     printf("一共交换了%d次\n", k);
//     return 0;
// }
