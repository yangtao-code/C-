#pragma once
#ifndef GAME_H_
#define GAME_H_

typedef unsigned char uchar;
typedef unsigned int uint;

#define SIMPLE 1
#define MIDDLE 2
#define EXPERT 3

//初级
#define ROW1 9
#define COL1 9
#define CNT1 10
//中级
#define ROW2 16
#define COL2 16
#define CNT2 40
//高级
#define ROW3 16
#define COL3 30
#define CNT3 99

//简单模式
void game_simple();
void init_simple(uchar (*board)[COL1 + 2], uchar (*display)[COL1 + 2]);
void display_simple(uchar(*board)[COL1 + 2], uchar(*display)[COL1 + 2]);
void scan_blank1(uchar(*board)[COL1 + 2], uchar(*display)[COL1 + 2], uint x, uint y);
uint mine_clear1(uchar(*board)[COL1 + 2], uchar(*display)[COL1 + 2], uint x, uint y);
uint is_win1(uchar(*display)[COL1 + 2]);

//中级模式
void game_middle();
void init_middle(uchar (*board)[COL2 + 2], uchar (*display)[COL2 + 2]);
void display_middle(uchar(*board)[COL2 + 2], uchar(*display)[COL2 + 2]);
void scan_blank2(uchar(*board)[COL2 + 2], uchar(*display)[COL2 + 2], uint x, uint y);
uint mine_clear2(uchar(*board)[COL2 + 2], uchar(*display)[COL2 + 2], uint x, uint y);
uint is_win2(uchar(*display)[COL2 + 2]);

//高级模式
void game_expert();
void init_expert(uchar (*board)[COL3 + 2], uchar (*display)[COL3 + 2]);
void display_expert(uchar(*board)[COL3 + 2], uchar(*display)[COL3 + 2]);
void scan_blank3(uchar(*board)[COL3 + 2], uchar(*display)[COL3 + 2], uint x, uint y);
uint mine_clear3(uchar(*board)[COL3 + 2], uchar(*display)[COL3 + 2], uint x, uint y);
uint is_win3(uchar(*display)[COL3 + 2]);

#endif