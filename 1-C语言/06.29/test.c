#include <stdio.h>
#include <stdbool.h>

// void Max(int *parr, int sz)
// {
//     int max = *parr;
//     for (int i = 0; i < sz; i++)
//     {
//         if (max < *(parr + i))
//         {
//             max = *(parr + i);
//         }
//     }
//     printf("max=%d\n", max);
// }

// void Min(int *parr, int sz)
// {
//     int min = *parr;
//     for (int i = 0; i < sz; i++)
//     {
//         if (min > *(parr + i))
//         {
//             min = *(parr + i);
//         }
//     }
//     printf("min=%d\n", min);
// }

// void Average(int *parr, int sz)
// {
//     int sum = 0;
//     for (int i = 0; i < sz; i++)
//     {
//         sum += *(parr + i);
//     }
//     float average = (float)sum / sz;
//     printf("average=%g\n", average);
// }

// void Ifadd(int *parr, int sz)
// {
//     bool flag = true;
//     for (int i = 0; i < sz - 1; i++)
//     {
//         if (*(parr + i) > *(parr + i + 1))
//         {
//             flag = false;
//             break;
//         }
//     }
//     printf("这个数据%s递增的！\n", (flag ? "是" : "不是"));
// }

// int main()
// {
//     int arr[5];
//     int *parr = arr;
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     for (int i = 0; i < sz; i++)
//     {
//         scanf("%d", parr + i);
//     }

//     for (int i = 0; i < sz; i++)
//     {
//         printf("%d ", *(parr + i));
//     }
//     printf("\n");

//     Max(arr, sz);

//     Min(arr, sz);

//     Average(arr, sz);

//     Ifadd(arr, sz);

//     return 0;
// }

// void Max(int arr[5], int sz)
// {
//     int max = arr[0];
//     int i;
//     for (i = 0; i < sz; i++)
//     {
//         if (max < arr[i])
//         {
//             max = arr[i];
//         }
//     }
//     printf("max=%d\n", max);
// }

// void Min(int arr[5], int sz)
// {
//     int min = arr[0];
//     int i;
//     for (i = 0; i < sz; i++)
//     {
//         if (min > arr[i])
//         {
//             min = arr[i];
//         }
//     }
//     printf("min=%d\n", min);
// }

// void Ifadd(int arr[5], int sz)
// {
//     int i = 1;
//     bool flag = true;
//     for (i = 0; i < sz - 1; i++)
//     {
//         if (arr[i] > arr[i + 1])
//         {
//             flag = false;
//             break;
//         }
//     }
//     printf("这个数据%s递增的！\n", (flag ? "是" : "不是"));
// }

// void Average(int arr[], int sz)
// {
//     int sum = 0;
//     float average;
//     for (int i = 0; i < sz; i++)
//     {
//         sum += arr[i];
//     }
//     average = (float)sum / sz;
//     printf("平均数为%g\n", average);
// }

// int main()
// {
//     int arr[5] = {0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int i;
//     for (i = 0; i < sz; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     for (i = 0; i < sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     Max(arr, sz);

//     Min(arr, sz);

//     Average(arr, sz);

//     Ifadd(arr, sz);

//     return 0;
// }