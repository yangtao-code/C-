#include <iostream>
#include <windows.h>
#include <time.h>
#include "game.h"
using namespace std;

#define PLAYGAME 1
#define ENDGAME 0

void game_level();

void menu()
{
	cout << "--------------------------------" << endl;
	cout << "|         1. 开始游戏          |" << endl;
	cout << "|         0. 结束游戏          |" << endl;
	cout << "--------------------------------" << endl;
}

//【初级】：雷区范围是9 * 9的方格，部署地雷10个
//【中级】：雷区范围是16 * 16的方格，部署地雷40个
//【高级】：雷区范围是16 * 30的方格，部署地雷99个雷
void game_menu()
{
	cout << "--------------------------------" << endl;
	cout << "|          1. 简单             |" << endl;
	cout << "|          2. 中级             |" << endl;
	cout << "|          3. 困难             |" << endl;
	cout << "--------------------------------" << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		cout << "请选择:>";
		cin >> input;
		switch (input)
		{
		case PLAYGAME:
			game_level();
			break;
		case ENDGAME:
			break;
		default:
			cout << "选择错误，请重新选择!" << endl;
			break;
		}
	} while (input);

	cout << "正在退出....." << endl;
	Sleep(1000);
	cout << "退出成功..." << endl;
	return 0;
}

void game_level()
{
	int input;
	game_menu();
again:
	cout << "请选择难度:>";
	cin >> input;
	switch (input)
	{
	case SIMPLE:
		game_simple();
		break;
	case MIDDLE:
		game_middle();
		break;
	case EXPERT:
		game_expert();
		break;
	default:
		cout << "选择错误，请重新选择.." << endl;
		goto again;
	}
}
