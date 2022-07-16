#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void menu()
{
	printf("***************************\n");
	printf("****  1.paly   0.exit  ****\n");
	printf("***************************\n");
}

int game()
{
	//1。生成一个随机数
	int r = 0;
	r = rand() % 100 + 1;
	//2.猜数字
	int guess=0;
	
	while (1)
	{
		printf("请猜数字：");
	    scanf("%d", &guess);
		if (guess > r)
		{
			printf("猜大了\n");
		}
		else if (guess < r)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你猜对了\n");
			break;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;

		}
	} while (input);
	return 0;
}