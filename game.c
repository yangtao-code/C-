#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "move.h"

void playgame()
{
    srand((unsigned int)time(NULL));
    int board[ROW][COL] = {0}; //创建一个二维数据储存2048游戏数据
    int score = 0;             //  游戏分数
    //初始化游戏数据
    InitGame(board);
    Playboard(board, &score);
    //  W为上   S为下   A为左   D为右
    char input = 0;
    printf("请选择：");
    do
    {
        scanf("%c", &input);
        switch (input)
        {
        case UP:
            Move_up(board, &score);
            break;
        case DOWN:
            Move_down(board, &score);
            break;
        case LEFT:
            Move_left(board, &score);
            break;
        case RIGHT:
            Move_right(board, &score);
            break;
        case EXIT:
            return;
        default:
            break;
        }
        if (If_game_over(board) == 1)
            break;
    } while (1);
}

int If_game_over(int (*board)[ROW])
{
    if (If_Win(board) == 1)
    {
        printf("恭喜您赢了！\n");
        return 1;
    }
    if (If_Lose(board) == -1)
    {
        printf("很遗憾，您输了！\n");
        return 1;
    }
    return 0;
}

int If_Lose(int (*board)[ROW])
{
    if (If_Full(board) && If_Move(board))
    {
        return -1;
    }
    return 0;
}

int If_Move(int (*board)[ROW])
{
    for (int i = 1; i < ROW - 1; i++)
    {
        if (board[i][0] == board[i - 1][0] || board[i][0] == board[i + 1][0])
            return 0;
        if (board[i][COL - 1] == board[i - 1][COL - 1] || board[i][COL - 1] == board[i + 1][COL - 1])
            return 0;
    }
    for (int j = 1; j < COL - 1; j++)
    {
        if (board[0][j] == board[0][j - 1] || board[0][j] == board[0][j + 1])
            return 0;
        if (board[ROW - 1][j] == board[ROW - 1][j - 1] || board[ROW - 1][j] == board[ROW - 1][j + 1])
            return 0;
    }
    for (int i = 1; i < ROW - 1; i++)
    {
        for (int j = 1; j < COL - 1; j++)
        {
            if (board[i][j] == board[i - 1][j])
                return 0;
            if (board[i][j] == board[i + 1][j])
                return 0;
            if (board[i][j] == board[i][j - 1])
                return 0;
            if (board[i][j] == board[i][j + 1])
                return 0;
        }
    }
    return 1;
}

int If_Full(int (*board)[ROW])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (board[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

int If_Win(int (*board)[ROW])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (board[i][j] == WIN)
                return 1;
        }
    }
    return 0;
}

void Playboard(int (*board)[ROW], int *score)
{
    printf("****  2048小游戏 ****\n");
    printf("        当前分数：%d\n", *score);
    printf("_____________________\n");
    for (int i = 0; i < ROW; i++)
    {
        printf("|    |    |    |    |\n|");
        for (int j = 0; j < COL; j++)
        {

            printf("%-4d|", board[i][j]);
        }
        printf("\n");
        printf("|___________________|\n");
    }
}

void InitGame(int (*board)[ROW])
{
    Get_randnum(board);
    Get_randnum(board);
}

void Get_randnum(int (*board)[ROW])
{
    if (If_Full(board) == 1)
        return;
    int rand_num[3] = {2, 2, 4};
    int row, col, k;
    while (1)
    {
        row = rand() % ROW;
        col = rand() % COL;
        if (board[row][col] == 0)
        {
            k = rand() % 3;
            board[row][col] = rand_num[k];
            break;
        }
    }
}

void menu()
{
    printf("***************************\n");
    printf("*** 1.playgame   0.exit ***\n");
    printf("***************************\n");
}
