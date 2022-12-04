#include "game.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

static uint cnt = CNT1;

void game_simple()
{

	uchar board[ROW1 + 2][COL1 + 2];	//�洢���׺�ÿ����Χ8������ĵ��׸���
	memset(board, '0', sizeof(board));
	uchar display[ROW1 + 2][COL1 + 2] = { 0 };	//��ʾ����
	init_simple(board, display);
	while (true)
	{
		//��ӡ������
		display_simple(board, display);
		uchar option;	//ѡ����컹������,��ΪpʱΪ���죬qʱΪ����
		uint  x, y;		//Ҫ����������
	again:
		cout << "�����ʽ��q x y��,��ѡ��:>";
		cin >> option >> x >> y;
		switch (option)
		{
		case 'q':		//����
		{
			uint ret = mine_clear1(board, display, x, y);
			if (ret == 0)
				return;
		}
		break;
		case 'p':
			display[x][y] = 'p';
			cnt--;
			break;
		case '0':
			cout << "�����˳���Ϸ..." << endl;
			Sleep(1000);
			cout << "�˳��ɹ�..." << endl;
			return;
		default:
			cout << "ѡ�����,������ѡ��:>" << endl;
			goto again;
		}

	}
}

void init_simple(uchar(*board)[COL1 + 2], uchar(*display)[COL1 + 2])
{
	//������õ���
	uint cnt = CNT1;
	while (cnt)
	{
		uint x = rand() % ROW1 + 1;
		uint y = rand() % COL1 + 1;
		if (board[x][y] != '*')
		{
			board[x][y] = '*';
			cnt--;
		}
	}
	//��ʼ��ÿ����Χ�ĵ��׸���
	for (uint i = 1; i < ROW1 + 1; i++)
	{
		for (uint j = 1; j < COL1 + 1; j++)
		{
			if (board[i][j] != '*')
			{
				uchar k = '0';
				for (uint x = i - 1; x <= i + 1; x++)
				{
					for (uint y = j - 1; y <= j + 1; y++)
					{
						if (board[x][y] == '*')
						{
							k++;
						}
					}
				}
				board[i][j] = k;
			}
		}
	}
	//��ʼ����ʾ��ά����
	for (uint i = 0; i < ROW1 + 1; i++)
	{
		for (uint j = 0; j < COL1 + 1; j++)
		{
			if (i == 0)
			{
				display[i][j] = '0' + j;
			}
			else if (j == 0)
			{
				display[i][j] = '0' + i;
			}
			else
			{
				display[i][j] = '#';
			}
			if (i == 0 && j == 0)
			{
				display[i][j] = ' ';
			}


		}
	}

}

void display_simple(uchar(*board)[COL1 + 2], uchar(*display)[COL1 + 2])
{
	system("cls");
	cout << "���׸�����" << cnt << endl;
	//��ʾ����
	for (uint i = 0; i < ROW1 + 2; i++)
	{
		for (uint j = 0; j < COL1 + 2; j++)
		{
			cout << " "<<display[i][j] << " ";
		}
		cout << endl;
	}
}

void scan_blank1(uchar(*board)[COL1 + 2], uchar(*display)[COL1 + 2], uint x, uint y)
{
	if (display[x][y] == 'p')
	{
		cnt++;
	}
	if ('0' == board[x][y])
	{
		for (uint i = x - 1; i <= x + 1; i++)
		{
			for (uint j = y - 1; j <= y + 1; j++)
			{
				if (i > 0 && i < ROW1 + 1 && j > 0 && j < COL1 + 1)
				{
					if (display[i][j] == '#')
					{
						display[i][j] = board[i][j];
						if (board[i][j] == '0')
						{
							scan_blank1(board, display, i, j);
						}

					}

				}
			}
		}
	}
	else
	{
		display[x][y] = board[x][y];
	}
}

uint is_win1(uchar(*display)[COL1 + 2])
{
	for (uint i = 1; i < ROW1 + 1; i++)
	{
		for (uint j = 1; j < COL1 + 1; j++)
		{
			if (display[i][j] == '#')
				return 0;
		}
	}
	return 1;
}

uint mine_clear1(uchar(*board)[COL1 + 2], uchar(*display)[COL1 + 2], uint x, uint y)
{
	if (board[x][y] == '*')
	{
		//��ӡ�����е���
		for (uint i = 1; i < ROW1 + 1; i++)
		{
			for (uint j = 1; j < COL1 + 1; j++)
			{
				display[i][j] = board[i][j];
			}
		}
		display_simple(board, display);
		cout << "���ź��������ˣ�����" << endl;
		Sleep(1000);
		system("pause");
		return 0;
	}
	else
	{
		scan_blank1(board, display, x, y);
		uint ret = is_win1(display);
		if (ret == 1)
		{
			cout << "��ϲ��Ӯ��...." << endl;
			Sleep(1000);
			system("pause");
			return 0;
		}
	}
	return 1;
}