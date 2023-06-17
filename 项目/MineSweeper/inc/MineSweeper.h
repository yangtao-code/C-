#ifndef __MINESWEEPER_H__
#define __MINESWEEPER_H__

typedef unsigned char uchar;

int ROW;
int COL;
int CNT;

// 游戏水平选择界面
void game_level();

/**
 * @brief 游戏主体程序
 *
 * @param ROW 棋盘的行
 * @param COL 棋盘的列
 * @return int 返回0为游戏失败,返回1为游戏成功
 */
int play_game();

/**
 * @brief 初始化棋盘
 *
 */
void init_board(uchar (*board)[COL + 2], uchar (*display)[COL + 2]);

void display_board(uchar (*board)[COL + 2], uchar (*display)[COL + 2]);

uint mine_clear(uchar (*board)[COL + 2], uchar (*display)[COL + 2]);

void scan_blank(uchar(*board)[COL + 2], uchar(*display)[COL + 2], uint x, uint y);

/**
 * @brief 判断你是否赢
 * 
 * @return uint 
 */
uint is_win(uchar (*display)[COL + 2]);

#endif