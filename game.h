#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//告诉我们四种状态
//  '*'   玩家赢
//  'a'   电脑赢
//  'Q'   和局
//  'C'   游戏继续
char IsWin(char board[ROW][COL], int row, int col);