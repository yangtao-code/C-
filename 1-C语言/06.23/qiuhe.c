/**
 * @file qiuhe.c
 * @author your name (you@domain.com)
 * @brief 这是求1~100之间的偶数和
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main()
{
    int a=0;
    int s=0;
    for(a = 0; a <= 100; a+= 2)
    {
        s=s+a;
    }
    printf("%d\n",s);
    return 0;
} 