#include <stdio.h>

int fabi(int n);
int fabi1(int n);

int main(int argc, char const *argv[])
{
    int n;
    printf("请输入: ");
    scanf("%d", &n);
    printf("第%d项为：%d\n", n, fabi1(n));
    return 0;
}

int fabi(int n)
{
    if (n < 2)
        return n;
    return fabi(n - 1) + fabi(n - 2);
}

int fabi1(int n)
{
    if (n < 2)
        return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++)
    {
        int tmp = b;
        b = a + b;
        a = tmp;
    }
    return b;
}