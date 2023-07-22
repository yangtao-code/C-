#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

// 矩形类
class Rectangle
{
private:
    uint32_t w;          // 矩形的长
    uint32_t h;          // 矩形的高
    uint32_t fill_color; // 矩形的颜色

public:
    /***
     * @brief 构造函数,初始化矩形
     *
     * @param _w 矩形的长
     * @param _h 矩形的高
     * @param _color 矩形的填充颜色
     */
    Rectangle(const uint32_t &_w, const uint32_t &_h,
              const uint32_t &_color = 0xffffff)
        : w(_w), h(_h), fill_color(_color)
    {
    }

    /***
     * @brief 设置矩形的颜色
     *
     * @param _color 颜色值
     */
    void setcolor(const uint32_t &_color)
    {
        this->fill_color = _color;
    }

    /***
     * @brief 重设矩形大小(长和宽)
     *
     * @param _w 矩形的长
     * @param _h 矩形的高
     */
    void resize(const uint32_t &_w, const uint32_t &_h)
    {
        this->w = _w;
        this->h = _h;
    }

    /***
     * @brief 在s屏幕上画出矩形
     *
     * @param s 屏幕
     * @param x0 x轴坐标
     * @param y0 y轴坐标
     */
    void draw(Screen &s, const int &x0, const int &y0)
    {
        for (int y = y0; y < y0 + h; y++)
        {
            for (int x = x0; x < x0 + w; x++)
            {
                s.draw_Point(x, y, fill_color);
            }
        }
    }

    /****** 下面函数用于获取矩形的属性值 *******/

    // 获取矩形的长度
    uint32_t get_w() const
    {
        return this->w;
    }

    // 获取矩形的高度
    uint32_t get_h() const
    {
        return this->h;
    }
    
    // 获取矩形的填充颜色
    uint32_t get_color() const
    {
        return this->fill_color;
    }
 
    /****************************************/
};

#endif