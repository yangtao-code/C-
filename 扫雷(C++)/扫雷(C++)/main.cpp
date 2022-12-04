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
	cout << "|         1. ��ʼ��Ϸ          |" << endl;
	cout << "|         0. ������Ϸ          |" << endl;
	cout << "--------------------------------" << endl;
}

//����������������Χ��9 * 9�ķ��񣬲������10��
//���м�����������Χ��16 * 16�ķ��񣬲������40��
//���߼�����������Χ��16 * 30�ķ��񣬲������99����
void game_menu()
{
	cout << "--------------------------------" << endl;
	cout << "|          1. ��             |" << endl;
	cout << "|          2. �м�             |" << endl;
	cout << "|          3. ����             |" << endl;
	cout << "--------------------------------" << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		cout << "��ѡ��:>";
		cin >> input;
		switch (input)
		{
		case PLAYGAME:
			game_level();
			break;
		case ENDGAME:
			break;
		default:
			cout << "ѡ�����������ѡ��!" << endl;
			break;
		}
	} while (input);

	cout << "�����˳�....." << endl;
	Sleep(1000);
	cout << "�˳��ɹ�..." << endl;
	return 0;
}

void game_level()
{
	int input;
	game_menu();
again:
	cout << "��ѡ���Ѷ�:>";
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
		cout << "ѡ�����������ѡ��.." << endl;
		goto again;
	}
}
