#include "game.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

static uint cnt = CNT1;

void game_simple()
{

	uchar board[ROW1 + 2][COL1 + 2];	//存储地雷和每点周围8个方块的地雷个数
	memset(board, '0', sizeof(board));
	uchar display[ROW1 + 2][COL1 + 2] = { 0 };	//显示棋盘
	init_simple(board, display);
	while (true)
	{
		//打印出棋盘
		display_simple(board, display);
		uchar option;	//选择插旗还是排雷,当为p时为插旗，q时为排雷
		uint  x, y;		//要操作的坐标
	again:
		cout << "输入格式（q x y）,请选择:>";
		cin >> option >> x >> y;
		switch (option)
		{
		case 'q':		//排雷
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
			cout << "正在退出游戏..." << endl;
			Sleep(1000);
			cout << "退出成功..." << endl;
			return;
		default:
			cout << "选择错误,请重新选择:>" << endl;
			goto again;
		}

	}
}

void init_simple(uchar(*board)[COL1 + 2], uchar(*display)[COL1 + 2])
{
	//随机设置地雷
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
	//初始化每点周围的地雷个数
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
	//初始化显示二维数组
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
	cout << "地雷个数：" << cnt << endl;
	//显示棋盘
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
		//打印出所有地雷
		for (uint i = 1; i < ROW1 + 1; i++)
		{
			for (uint j = 1; j < COL1 + 1; j++)
			{
				display[i][j] = board[i][j];
			}
		}
		display_simple(board, display);
		cout << "很遗憾，您输了！！！" << endl;
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
			cout << "恭喜你赢了...." << endl;
			Sleep(1000);
			system("pause");
			return 0;
		}
	}
	return 1;
}