#include <stdio.h>

/**
 * @brief 实现判断一个数组是否有序
 * 
 * @param a 
 * @param sz 
 * @return int 返回1为有序,0为无序
 */
int is_order(int *a, int sz);

int main(int argc, char const *argv[])
{
    int a[5];
    printf("请输入五个数：\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    if (is_order(a, 5) == 1)
    {
        printf("该数组有序！\n");
    }
    else
    {
        printf("该数组无序！\n");
    }

    return 0;
}

int is_order(int *a, int sz)
{
    int flag1 = 1; //创建一个递增的flag,1为是递增
    int flag2 = 1; //创建一个递减的flag,1为是递减
    int flag3 = 1; //创建一个一直不变发flag,1为一直保存不变
    for (int i = 0; i < sz - 1; i++)
    {
        if (a[i] >= a[i + 1])
        {
            flag1 = 0;
            break;
        }
    }
    for (int i = 0; i < sz - 1; i++)
    {
        if (a[i] <= a[i + 1])
        {
            flag2 = 0;
            break;
        }
    }
    for (int i = 0; i < sz - 1; i++)
    {
        if (a[i] != a[i + 1])
        {
            flag3 = 0;
            break;
        }
    }
    if (flag1 || flag2 || flag3)
        return 1;
    return 0;
}