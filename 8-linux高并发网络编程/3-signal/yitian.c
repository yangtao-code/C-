/************************************************
**    本程序为易甜大可爱而作，用于感谢她的陪伴和支持。
**    时间 2022年11月4日凌晨1点
*************************************************/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("请选择 1 or 0\n");
    printf("你觉得易甜是个什么样的人！\n");
    int input = -1;
    printf("请选择：");
    scanf("%d", &input);
    if (input == 1)
    {
        printf("易甜是个大傻逼！\n");
        printf("为什么你会觉得她是这样的？\n");
        printf("请选择：");
        scanf("%d", &input);
        if (input == 1)
        {
            printf("因为易甜是个超级无敌超级超级超级超级大傻逼啊！\n");
        }
        else
        {
            printf("因为易甜是个可爱的大傻逼！\n");
        }
    }
    else if (input == 0)
    {
        printf("易甜是个超级漂亮，超级可爱，超级体贴的人！\n");
        printf("为什么你会觉得她是这样的？\n");
        printf("请选择：");
        scanf("%d", &input);
        if (input == 1)
        {
            printf("因为她知道关心体贴我啊！\n");
        }
        else
        {
            printf("被逼的，呜呜呜！\n");
        }
    }
    getchar();
    return 0;
}
