#include <stdio.h>

// int main()
// {
//     const char* p="hello world";
//     printf("%s\n",p);
//     return 0;
// }

int max_print(int (*p)[3], int row)
{
    int max = **p;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (*(*(p + i) + j) > max)
            {
                max = *(*(p + i) + j);
            }
        }
    }
    return max;
}

int main()
{
    int a[][3] = {1, 2, 3, 4, 5, 1, 2, 3, 4};
    int max;
    max = max_print(a, 3);
    printf("%d\n", max);
    return 0;
}


// int max_print(int (*parr)[3], int row)
// {
//     int max = **parr;
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             if (max < *(*(parr + i) + j))
//                 max = *(*(parr + i) + j);
//         }
//     }
//     return max;
// }

// int main()
// {
//     int arr[][3] = {1, 2, 3, 4, 5, 4, 3 , 2, 1};
//     int max;
//     max = max_print(arr, 3);
//     printf("max=%d\n", max);
//     return 0;
// }