#include <stdio.h>
#include "move.h"

void Move_right(int (*board)[ROW], int *score)
{
    //先移动位置
    compress_right(board);
    //合并
    merge_right(board, score);
    //再移动位置
    compress_right(board);

    Get_randnum(board);
    system("clear");
    Playboard(board, score);
}
void compress_right(int (*board)[ROW])
{
    for (int i = 0; i < ROW; i++)
    {
        int tmp[COL] = {0};
        int k = 0;
        //如果该行非零的元素，存入数组tmp中
        for (int j = COL - 1; j >= 0; j--)
        {
            if (board[i][j] != 0)
            {
                tmp[k++] = board[i][j];
            }
        }
        //将tmp中的元素放回该行
        for (int j = 0; j < COL; j++)
        {
            board[i][COL - j - 1] = tmp[j];
        }
    }
}
void merge_right(int (*board)[ROW], int *score)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = COL - 1; j > 0; j--)
        {
            if (board[i][j] == board[i][j - 1])
            {
                board[i][j] = 2 * board[i][j];
                board[i][j - 1] = 0;
                *score = *score + board[i][j];
            }
        }
    }
}

void Move_left(int (*board)[ROW], int *score)
{
    //先移动位置
    compress_left(board);
    //合并
    merge_left(board, score);
    //再移动位置
    compress_left(board);

    Get_randnum(board);
    system("clear");
    Playboard(board, score);
}
void compress_left(int (*board)[ROW])
{
    for (int i = 0; i < ROW; i++)
    {
        int tmp[COL] = {0};
        int k = 0;
        //如果该行非零的元素，存入数组tmp中
        for (int j = 0; j < COL; j++)
        {
            if (board[i][j] != 0)
            {
                tmp[k++] = board[i][j];
            }
        }
        //将tmp中的元素放回该行
        for (int j = 0; j < COL; j++)
        {
            board[i][j] = tmp[j];
        }
    }
}
void merge_left(int (*board)[ROW], int *score)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL - 1; j++)
        {
            if (board[i][j] == board[i][j + 1])
            {
                board[i][j] = 2 * board[i][j];
                board[i][j + 1] = 0;
                *score = *score + board[i][j];
            }
        }
    }
}

void Move_down(int (*board)[ROW], int *score)
{
    //先移动位置
    compress_down(board);
    //合并
    merge_down(board, score);
    //再移动位置
    compress_down(board);

    Get_randnum(board);
    system("clear");
    Playboard(board, score);
}
void compress_down(int (*board)[ROW])
{
    for (int j = 0; j < COL; j++)
    {
        int tmp[COL] = {0};
        int k = 0;
        //如果该列的元素非零，存入数组tmp中
        for (int i = ROW - 1; i >= 0; i--)
        {
            if (board[i][j] != 0)
            {
                tmp[k++] = board[i][j];
            }
        }
        //将tmp中的元素放回该列
        for (int i = 0; i < ROW; i++)
        {
            board[ROW - i - 1][j] = tmp[i];
        }
    }
}
void merge_down(int (*board)[ROW], int *score)
{
    for (int j = 0; j < COL; j++)
    {
        for (int i = ROW - 1; i > 0; i--)
        {
            if (board[i][j] == board[i - 1][j])
            {
                board[i][j] = 2 * board[i][j];
                board[i - 1][j] = 0;
                *score = *score + board[i][j];
            }
        }
    }
}

void Move_up(int (*board)[ROW], int *score)
{
    //先移动位置
    compress_up(board);
    //合并
    merge_up(board, score);
    //再移动位置
    compress_up(board);

    Get_randnum(board);
    system("clear");
    Playboard(board, score);
}
void compress_up(int (*board)[ROW])
{
    for (int j = 0; j < COL; j++)
    {
        int tmp[COL] = {0};
        int k = 0;
        //如果该列的元素非零，存入数组tmp中
        for (int i = 0; i < ROW; i++)
        {
            if (board[i][j] != 0)
            {
                tmp[k++] = board[i][j];
            }
        }
        //将tmp中的元素放回该列
        for (int i = 0; i < ROW; i++)
        {
            board[i][j] = tmp[i];
        }
    }
}
void merge_up(int (*board)[ROW], int *score)
{
    for (int j = 0; j < COL; j++)
    {
        for (int i = 0; i < ROW - 1; i++)
        {
            if (board[i][j] == board[i + 1][j])
            {
                board[i][j] = 2 * board[i][j];
                board[i + 1][j] = 0;
                *score = *score + board[i][j];
            }
        }
    }
}