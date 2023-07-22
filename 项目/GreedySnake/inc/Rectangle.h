#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

// 矩形类
class Rectangle
{
public:
    /***
     * @brief 构造函数,初始化矩形
     *
     * @param l 矩形的长度
     * @param w 矩形的宽
     * @param x 矩形左上角点的x轴坐标
     * @param y 矩形左上角点的y轴坐标
     * @param color 矩形的颜色
     */
    Rectangle(const unsigned int& l, const unsigned int& w,
              const int& x = 0, const int& y = 0,const unsigned int& color = 0x00);

    /***
     * @brief 移动矩形的位置
     *
     * @param x x坐标
     * @param y y坐标
     */
    void move(const int& x, const int& y);

    /***
     * @brief 设置矩形的颜色
     *
     * @param color 颜色值
     */
    void setColor(const unsigned int& color);

    /***
     * @brief 重设矩形大小(长和宽)
     *
     * @param l 矩形的长
     * @param w 矩形的宽
     */
    void resize(const unsigned int& l, const unsigned int& w);

    /****** 下面函数用于获取矩形的属性值 *******/
    unsigned int get_L();
    unsigned int get_W();
    unsigned int get_color();
    int get_X();
    int get_Y();
    /****************************************/

private:
    unsigned int m_l;     // 矩形的长
    unsigned int m_w;     // 矩形的宽
    int m_x0;             // 矩形左上角点的x轴坐标
    int m_y0;             // 矩形左上角点的y轴坐标
    unsigned int m_color; // 矩形的颜色
};

#endif