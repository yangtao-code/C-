#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "lcd.h"
#include "ts.h"
#include "MineSweeper.h"

unsigned int cnt;

static int x0;
static int y0;
static int x;
static int y;

void game_level()
{
    while (1)
    {
        display_bmp(0, 0, "./pic/level.bmp");
        display_bmp(750, 430, "./pic/return.bmp");

        get_state(&x, &y);          // 获取点击触摸屏状态
        Close_software(x, y);       // 退出软件端口
        int ret = return_pre(x, y); // 返回上一级端口
        if (ret == 1)
        {
            return;
        }
        if (x >= 270 && x < 500)
        {
            if (y >= 120 && y < 190)
            {
                ROW = 9;
                COL = 9;
                CNT = 10;
            }
            else if (y >= 230 && y < 310)
            {
                ROW = 16;
                COL = 16;
                CNT = 40;
            }
            else if (y >= 350 && y < 430)
            {
                ROW = 16;
                COL = 30;
                CNT = 99;
            }
            else
            {
                continue;
            }
            int ret = play_game();
            if (ret == 0)
            {
                display_bmp(0, 0, "./pic/game_over.bmp");
                while (1)
                {
                    get_state(&x, &y);
                    if (x >= 0 && x < 800 && y >= 0 && y < 480)
                        break;
                }
            }
        }
    }
}

int play_game()
{
    srand((unsigned int)time(NULL));
    x0 = 400 - (COL * 20) / 2;
    y0 = 100;

    uchar board[ROW + 2][COL + 2]; // 存储地雷和每点周围8个方块的地雷个数
    memset(board, '0', sizeof(board));
    uchar display[ROW + 2][COL + 2]; // 显示棋盘
    memset(board, '0', sizeof(display));
    init_board(board, display);

    while (1)
    {
        display_bmp(0, 0, "./pic/panel.bmp");
        display_bmp(750, 430, "./pic/return.bmp");
        display_board(board, display);
        int ret = mine_clear(board, display);
        if (ret == -1)
        {
            return -1;
        }
        if (ret == 0)
        {
            return 0;
        }
        ret = is_win(display);
        if (ret == 1)
        {
            printf("恭喜你赢了....\n");
            sleep(1);
            return 0;
        }
    }
}

void init_board(uchar (*board)[COL + 2], uchar (*display)[COL + 2])
{
    // 随机设置地雷
    cnt = CNT;
    while (cnt)
    {
        uint x = rand() % ROW + 1;
        uint y = rand() % COL + 1;
        if (board[x][y] != '*')
        {
            board[x][y] = '*';
            cnt--;
        }
    }
    // 初始化每点周围的地雷个数
    for (uint i = 1; i < ROW + 1; i++)
    {
        for (uint j = 1; j < COL + 1; j++)
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
    // 初始化显示二维数组
    for (uint i = 1; i < ROW + 1; i++)
    {
        for (uint j = 1; j < COL + 1; j++)
        {
            display[i][j] = '#';
        }
    }
    cnt = CNT;
}

void display_board(uchar (*board)[COL + 2], uchar (*display)[COL + 2])
{

    display_Square(x0, 40, COL * 20, 60, 0x7F7F7F);
    display_Square(x0 + 10, 50, COL * 20 - 20, 40, 0xC3C3C3);
    printf("地雷个数: %d\n", cnt);
    // 显示棋盘
    for (uint i = 1; i < ROW + 1; i++)
    {
        for (uint j = 1; j < COL + 1; j++)
        {
            printf(" %c ", display[i][j]);
            if (display[i][j] == '#')
            {
                display_bmp(x0 + (j - 1) * 20, y0 + (i - 1) * 20, "./pic/block.bmp");
            }
            else if (display[i][j] == 'p')
            {
                display_bmp(x0 + (j - 1) * 20, y0 + (i - 1) * 20, "./pic/flag.bmp");
            }
            else if (display[i][j] >= '0' && display[i][j] <= '8')
            {
                char bmp_name[50] = "";
                sprintf(bmp_name, "./pic/%c.bmp", display[i][j]);
                display_bmp(x0 + (j - 1) * 20, y0 + (i - 1) * 20, bmp_name);
            }
            else
            {
                display_bmp(x0 + (j - 1) * 20, y0 + (i - 1) * 20, "./pic/mine.bmp");
            }
        }
        printf("\n");
    }
}

uint mine_clear(uchar (*board)[COL + 2], uchar (*display)[COL + 2])
{
    int x, y, way;
    while (1)
    {
        way = get_state(&x, &y);
        int ret = return_pre(x, y); // 返回上一级端口
        if (ret == 1)
        {
            return -1;
        }
        ret = Close_software(x, y);
        if (ret == 0)
        {
            display_bmp(0, 0, "./pic/panel.bmp");
            display_bmp(750, 430, "./pic/return.bmp");
            display_board(board, display);
            continue;
        }

        x = (x - x0) / 20 + 1;
        y = (y - y0) / 20 + 1;
        printf("(x , y) = (%d , %d)\n", x, y);
        if (x >= 0 && x <= COL && y >= 0 && y <= ROW)
            break;
    }
    if (way == PRESS)
    {
        if (display[y][x] == '#')
        {
            display[y][x] = 'p';
            cnt--;
        }
        else if (display[y][x] == 'p')
        {
            display[y][x] = '#';
            cnt++;
        }
    }

    else if (board[y][x] == '*' && display[y][x] != 'p')
    {
        // 打印出所有地雷
        for (uint i = 1; i < ROW + 1; i++)
        {
            for (uint j = 1; j < COL + 1; j++)
            {
                display[i][j] = board[i][j];
            }
        }
        display_board(board, display);
        printf("很遗憾, 您输了 !!!\n");
        sleep(1);
        return 0;
    }
    else if (display[y][x] != '#' && display[y][x] != 'p')
    {
        char count = '0';
        for (uint i = y - 1; i <= y + 1; i++)
        {
            for (uint j = x - 1; j <= x + 1; j++)
            {
                if ('p' == display[i][j])
                {
                    count++;
                }
            }
        }
        if (count == display[y][x])
        {
            for (uint i = y - 1; i <= y + 1; i++)
            {
                for (uint j = x - 1; j <= x + 1; j++)
                {
                    if ('#' == display[i][j])
                    {
                        display[i][j] = board[i][j];
                        if (board[i][j] == '*')
                        {
                            // 打印出所有地雷
                            for (uint i = 1; i < ROW + 1; i++)
                            {
                                for (uint j = 1; j < COL + 1; j++)
                                {
                                    display[i][j] = board[i][j];
                                }
                            }
                            display_board(board, display);
                            printf("很遗憾, 您输了 !!!\n");
                            sleep(1);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    else
    {
        scan_blank(board, display, y, x);
    }
    return 1;
}

void scan_blank(uchar (*board)[COL + 2], uchar (*display)[COL + 2], uint x, uint y)
{
    if (display[x][y] == 'p')
    {
        display[x][y] = '#';
        cnt++;
    }
    else if ('0' == board[x][y])
    {
        for (uint i = x - 1; i <= x + 1; i++)
        {
            for (uint j = y - 1; j <= y + 1; j++)
            {
                if (i > 0 && i < ROW + 1 && j > 0 && j < COL + 1)
                {
                    if (display[i][j] == '#')
                    {
                        display[i][j] = board[i][j];
                        if (board[i][j] == '0')
                        {
                            scan_blank(board, display, i, j);
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

uint is_win(uchar (*display)[COL + 2])
{
    if (cnt != 0)
        return 0;

    for (uint i = 1; i < ROW + 1; i++)
    {
        for (uint j = 1; j < COL + 1; j++)
        {
            if (display[i][j] == '#')
                return 0;
        }
    }
    return 1;
}