#include <stdio.h>

/**
 * @brief 
 * 
 * @param arr 为一个二维数组输入数
 * @param x     行
 * @param y     列
 */
void input_arr(int (*arr)[3], int x, int y);

void print_arr(int (*arr)[3], int x, int y);
int arr_max(int (*arr)[3], int x, int y);
int arr_min(int (*arr)[3], int x, int y);
double arr_avg(int (*arr)[3], int x, int y);

int main()
{
    int a=(unsigned char)-1<<2;
    printf("%d\n",a);
    printf("%u\n",a);
    return 0;
}
// int main()
// {
//     int arr[3][3] = {0};
//     input_arr(arr, 3, 3);
//     print_arr(arr, 3, 3);
//     int max = arr_max(arr, 3, 3);
//     printf("max=%d\n", max);
//     int min = arr_min(arr, 3, 3);
//     printf("min=%d\n", min);
//     double average = arr_avg(arr, 3, 3);
//     printf("average=%g\n", average);
//     return 0;
// }

void input_arr(int (*arr)[3], int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", (*(arr + i) + j));
        }
    }
}

void print_arr(int (*arr)[3], int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}
int arr_max(int (*arr)[3], int x, int y)
{
    int max = (*arr)[0];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (max < *(*(arr + i) + j))
                max = *(*(arr + i) + j);
        }
    }
    return max;
}
int arr_min(int (*arr)[3], int x, int y)
{
    int min = (*arr)[0];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (min > *(*(arr + i) + j))
                min = *(*(arr + i) + j);
        }
    }
    return min;
}
double arr_avg(int (*arr)[3], int x, int y)
{
    int sum = 0;
    double avg;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            sum += *(*(arr + i) + j);
        }
    }
    avg = (double)sum / (x * y);
    return avg;
}