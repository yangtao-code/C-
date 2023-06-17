#pragma once

#include <iostream>
using namespace std;

typedef enum WAY
{
    CLICK = 0, // 点击
    PRESS = 1, // 按压
    UP = 2,    // 上滑
    DOWN = 3,  // 下滑
    LEFT = 4,  // 左滑
    RIGHT = 5  // 右滑
} WAY;

//触摸状态结构体
typedef struct StateInfo
{
    bool is_used; // 看这个触摸状态是否已经被使用
    int x0;       // 触摸的起始x坐标
    int y0;       // 触摸的起始y坐标
    int x;        // 触摸的离开x坐标
    int y;        // 触摸的离开y坐标
    WAY way;      // 触摸状态

} StateInfo;

// 触摸屏类
class Ts
{
public:
    // 构造函数,初始化触摸屏
    Ts();
    // 析构函数,关闭触摸屏
    ~Ts();
    // 获取触摸状态
    int get_state();

    int ts_fd; // 触摸屏的文件描述符

    StateInfo s; // 存放触摸的状态信息
};