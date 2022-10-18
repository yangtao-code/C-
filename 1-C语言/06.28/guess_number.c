#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void meun()
{
    printf("********************\n");
    printf("***1.play  0.exit***\n");
    printf("********************\n");
}

void game()
{
    int a;
    int b;
    printf("请输入你要猜的范围：");
    scanf("%d%d", &a, &b);
    int r = rand() % b + a;
    int guess;
    int count = 0;
    while (1)
    {
        printf("当前范围为 %d ~ %d \n", a, b);
        printf("请输入你猜的数字:>");
        scanf("%d", &guess);
        count++;
        if (guess == r)
        {
            printf("恭喜你猜对了！你一共猜了%d次\n", count);
            break;
        }
        else if (guess < r)
        {
            printf("猜小了!\n");
            a = guess;
        }
        else
        {
            printf("猜大了！\n");
            b = guess;
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        meun();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("游戏结束!\n");
            break;
        default:
            printf("选择错误，请重新选择:>\n");
            break;
        }
    } while (input);

    return 0;
}