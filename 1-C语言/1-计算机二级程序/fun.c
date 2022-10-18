#include "fun.h"

int fun1(char *str)
{
    int ret = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            ret++;
        }
    }
    return ret;
}

void fun2(Stu a[], Stu *s)
{
    *s = a[0];
    for (int i = 0; i < 5; i++)
    {
        if (s->score > a[i].score)
        {
            *s = a[i];
        }
    }
}

void fun3(int (*a)[N], int m)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            a[i][j] *= m;
        }
    }
}

double fun4(int (*a)[N])
{
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
            {
                cnt++;
                sum += a[i][j];
            }
        }
    }
    return (double)sum / cnt;
}

double fun5(double a)
{
    int tmp = (a * 1000 + 5) / 10;
    return tmp / 100.0;
}

void fun6(int (*a)[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }
}