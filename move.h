#ifndef MOVE_H_
#define MOVE_H_

#include "game.h"

/**
 * @brief 上移模块
 * 
 * @param score 
 */
void Move_up(int (*board)[ROW], int *score);
void compress_up(int (*board)[ROW]);
void merge_up(int (*board)[ROW], int *score);

/**
 * @brief 下移模块
 * 
 * @param score 
 */
void Move_down(int (*board)[ROW], int *score);
void compress_down(int (*board)[ROW]);
void merge_down(int (*board)[ROW], int *score);

/**
 * @brief 左移模块
 * 
 * @param score 
 */
void Move_left(int (*board)[ROW], int *score);
void compress_left(int (*board)[ROW]);
void merge_left(int (*board)[ROW], int *score);

/**
 * @brief 右移模块
 * 
 * @param score 
 */
void Move_right(int (*board)[ROW], int *score);
void compress_right(int (*board)[ROW]);
void merge_right(int (*board)[ROW], int *score);

#endif