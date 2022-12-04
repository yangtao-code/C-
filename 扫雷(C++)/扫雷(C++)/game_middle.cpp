#include "game.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

static uint cnt = CNT2;

void game_middle()
{
	uchar board[ROW2 + 2][COL2 + 2];	//�洢���׺�ÿ����Χ8������ĵ��׸���
	memset(board, '0', sizeof(board));
	uchar display[ROW2 + 2][COL2 + 2] = { 0 };	//��ʾ����
	init_middle(board, display);
	while (true)
	{
		//��ӡ������
		display_middle(board, display);
		uchar option;	//ѡ����컹������,��ΪpʱΪ���죬qʱΪ����
		uint  x, y;		//Ҫ����������
	again:
		cout << "�����ʽ��q x y��,��ѡ��:>";
		cin >> option >> x >> y;
		switch (option)
		{
		case 'q':		//����
		{
			uint ret = mine_clear2(board, display, x, y);
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

void init_middle(uchar(*board)[COL2 + 2], uchar(*display)[COL2 + 2])
{
	//������õ���
	uint cnt = CNT2;
	while (cnt)
	{
		uint x = rand() % ROW2 + 1;
		uint y = rand() % COL2 + 1;
		if (board[x][y] != '*')
		{
			board[x][y] = '*';
			cnt--;
		}
	}
	//��ʼ��ÿ����Χ�ĵ��׸���
	for (uint i = 1; i < ROW2 + 1; i++)
	{
		for (uint j = 1; j < COL2 + 1; j++)
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
	for (uint i = 0; i < ROW2 + 1; i++)
	{
		for (uint j = 0; j < COL2 + 1; j++)
		{
			if (i == 0)
			{
				display[i][j] = j;
			}
			else if (j == 0)
			{
				display[i][j] = i;
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

void display_middle(uchar(*board)[COL2 + 2], uchar(*display)[COL2 + 2])
{
	system("cls");
	cout << "���׸�����" << cnt << endl;
	//��ʾ����
	for (uint i = 1; i < ROW2+ 1; i++)
	{
		for (uint j = 1; j < COL2+ 1; j++)
		{
			cout << " "<<display[i][j] << " ";
		}
		cout << endl;
	}
}

void scan_blank2(uchar(*board)[COL2 + 2], uchar(*display)[COL2 + 2], uint x, uint y)
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
				if (i > 0 && i < ROW2+ 1 && j > 0 && j < COL2+ 1)
				{
					if (display[i][j] == '#')
					{
						display[i][j] = board[i][j];
						if (board[i][j] == '0')
						{
							scan_blank2(board, display, i, j);
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

uint mine_clear2(uchar(*board)[COL2 + 2], uchar(*display)[COL2 + 2], uint x, uint y)
{
	if (board[x][y] == '*')
	{
		//��ӡ�����е���
		for (uint i = 1; i < ROW2 + 1; i++)
		{
			for (uint j = 1; j < COL2 + 1; j++)
			{
				display[i][j] = board[i][j];
			}
		}
		display_middle(board, display);
		cout << "���ź��������ˣ�����" << endl;
		Sleep(1000);
		system("pause");
		return 0;
	}
	else
	{
		scan_blank2(board, display, x, y);
		uint ret = is_win2(display);
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

uint is_win2(uchar(*display)[COL2 + 2])
{
	for (uint i = 1; i < ROW2 + 1; i++)
	{
		for (uint j = 1; j < COL2 + 1; j++)
		{
			if (display[i][j] == '#')
				return 0;
		}
	}
	return 1;
}