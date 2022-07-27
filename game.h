
#ifndef GAME_H_
#define GAME_H_

#define ROW 4    //2048行数
#define COL 4    //2048列数
#define WIN 2048 //当达到这个数时，玩家赢

enum direction
{
    UP = 'w',
    DOWN = 's',
    LEFT = 'a',
    RIGHT = 'd',
    EXIT = '0'
};

/**
 * @brief 游戏界面选择菜单
 * 
 */
void menu();

/**
 * @brief 游戏开始界面
 * 
 */
void playgame();

/**
 * @brief 初始化游戏数据
 * 
 */
void InitGame(int (*board)[ROW]);

/**
 * @brief 生成一个随机数
 * 
 */
void Get_randnum(int (*board)[ROW]);

/**
 * @brief 打印界面
 * 
 * @param score 
 */
void Playboard(int (*board)[ROW], int *score);

/**
 * @brief 判断是否赢,返回1为赢,返回-1为输,返回其他数为游戏继续
 * 
 * @return int 
 */
int If_Win(int (*board)[ROW]);

/**
 * @brief 判断是否输,返回-1为输
 * 
 * @return int 
 */
int If_Lose(int (*board)[ROW]);

/**
 * @brief 判断是否结束游戏
 * 
 * @return int 
 */
int If_game_over(int (*board)[ROW]);

/**
 * @brief 判断2048所有位置有没有满，返回1为已满
 * 
 * @return int 
 */
int If_Full(int (*board)[ROW]);

/**
 * @brief 判断2048还可不可以移动，返回1为不可以移动
 * 
 * @return int 
 */
int If_Move(int (*board)[ROW]);

#endif