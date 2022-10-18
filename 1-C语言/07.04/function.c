#include "test.h"

int a=10;
void foo()
{
    a++;
    printf("%d\n", a);
}


void nixu(int a)
{
    printf("%d", a % 10);
    a = a / 10;
    if (a == 0)
    {
        printf("\n");
    }
    else
    {
        nixu(a);
    }
}

unsigned long fibonacii(int n)
{
    unsigned long a = 1, b = 1;
    int k = 1;
    unsigned long fi;
    if (n == 1 || n == 2)
    {
        fi = 1;
        return 1;
    }
    while (k <= n-2)
    {
        fi = a + b;
        a = b;
        b = fi;
        k++;
    }
    return fi;

    // if (n == 1 || n == 2)
    // {
    //     return 1;
    // }
    // return fibonacii(n - 1) + fibonacii(n - 2);
}

int arr_sum(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    return arr[n - 1] + arr_sum(arr, n - 1);
}

int mul(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * mul(n - 1);
}