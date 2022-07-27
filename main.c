#include "game.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int input;
    do
    {
        //打印菜单
        menu();
        printf("请选择：");
        scanf("%d", &input);
        getchar();
        switch (input)
        {
        case 1:
            playgame();
            break;
        case 0:
            printf("退出成功，欢迎下次再玩！\n");
            break;
        default:
            printf("选择错误，请重新选择！\n");
            break;
        }
    } while (input);
    return 0;
}
