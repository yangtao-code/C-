#pragma once

#include "lcd.h"

/**
 * @brief 显示文子到屏幕是
 *
 * @param x0 起始横坐标
 * @param y0 起始纵坐标
 * @param w 文字宽度
 * @param h 文字高度
 * @param wordbuf   文字的缓冲区
 * @param wordnum   文字个数
 * @param backcolor 背景色
 * @param worldcolor    文字的颜色
 * @return int
 */
void display_words(int x0, int y0,
                   int w, int h,
                   char *wordbuf,
                   int wordnum,
                   unsigned int backcolor,
                   unsigned int wordcolor);