/*  触摸屏有关函数  */
#ifndef __TS_H__
#define __TS_H__

typedef enum WAY
{
    SHUT = 0,
    PRESS,
    UP,
    DOWN,
    LEFT,
    RIGHT
} WAY;

/**
 * @brief 初始化触摸屏函数,打开触摸屏
 *
 * @return int 成功返回0,失败返回-1
 */
int open_ts();

/**
 * @brief 关闭触摸屏
 *
 */
int close_ts();

/**
 * @brief 获得触摸屏的触摸方向
 *
 * @return int 返回方向值
 */
int get_state(int *x, int *y);

/**
 * @brief 程序退出线程函数
 *
 * @param arg
 * @return void*
 */
int Close_software(int x, int y);

/**
 * @brief 返回上一级内容
 * 
 * @param x 
 * @param y 
 * @return int 返回1为返回上一级,返回0为不返回
 */
int return_pre(int x, int y);

#endif
