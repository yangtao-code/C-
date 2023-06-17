#pragma once

#include <iostream>
using namespace std;

class Lcd
{
public:
    /**
     * @brief 初始化屏幕,打开屏幕文件,映射地址
     *
     */
    Lcd();

    /**
     * @brief 以正坐标轴显示一个像素点
     *
     * @param x 横坐标
     * @param y 纵坐标
     * @param color 颜色
     */
    void display_Point(int x, int y, unsigned int color);

    /**
     * @brief 在屏幕上显示一个像素点
     *
     * @param x x轴坐标
     * @param y y轴坐标
     * @param color 颜色值
     */
    void display_Square(int x0, int y0,
                        unsigned l, unsigned int w,
                        unsigned int color);

    void display_Circle(int x0, int y0, int r, unsigned int color);

    /**
     * @brief 显示bmp图片
     *
     * @param x0 显示的图片左上角的x轴坐标
     * @param y0 显示的图片左上角的y轴坐标
     * @param bmp_name bmp文件路径名称
     * @param int   返回0为正常打开,返回-1为异常
     */
    int display_bmp(int x0, int y0, const char *bmp_name);

    int display_jpg(int x0, int y0, const char *jpg_name);

    /**
     * @brief 打开一个bmp图片
     *
     * @param width 宽度
     * @param hight 高度
     * @param depth 深度
     * @return int 成功返回文件描述符,失败返回-1
     */
    int open_bmp(const char *bmp_name, int *width, int *hight, short *depth);

    /**
     * @brief 关闭屏幕
     *
     */
    ~Lcd();

    int lcd_fd;         // 屏幕的文件描述符
    unsigned int *plcd; // 屏幕的映射地址
};
