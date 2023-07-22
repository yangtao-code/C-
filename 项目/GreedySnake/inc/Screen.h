#ifndef __SCREEN_H__
#define __SCREEN_H__

// 屏幕默认的文件地址
#define DEV_PATH "/dev/fb0"

// 屏幕类
class Screen
{
private:
    /* 数据成员: 描述 对象的 属性的 */
    const char *dev_node;    // 屏幕文件的文件名
    int fd;                  // 文件描述符
    uint32_t lcd_width;      // 显示屏每一行有多少个像素点
    uint32_t lcd_height;     // 显示屏总共有多少行
    uint32_t bits_per_pixel; // 每个像素点占多少bits
    int32_t *plcd;           // 指向屏幕 帧缓冲区的首地址

public:
    /***
     * @brief 构造函数,用来打开屏幕文件和映射地址
     *
     * @param file 屏幕文件地址
     */
    Screen(const char *file = DEV_PATH);

    /***
     * @brief 析构函数,解映射、关闭屏幕文件描述符,回收资源
     *
     */
    ~Screen();

    /***
     * @brief 在屏幕上画一个点
     *
     * @param x 点在屏幕上的x轴坐标
     * @param y 点在屏幕上的y轴坐标
     * @param color 颜色值
     */
    void draw_Point(const int &x, const int &y, const uint32_t &color = 0x00);

    /***
     * @brief   在屏幕上画一个矩形
     *
     * @param w 矩形的长
     * @param h 矩形的宽
     * @param x0 矩形的左上角点的x轴坐标
     * @param y0 矩形的左上角点的y轴坐标
     * @param color 矩形颜色
     */
    void draw_Rectangle(const int &w, const int &h,
                        const int &x0, const int &y0,
                        const uint32_t &color = 0x00);



    /****   下面函数用于获取屏幕的信息    ****/

    uint32_t get_lcd_width() const
    {
        return this->lcd_width;
    }

    uint32_t get_lcd_height() const
    {
        return this->lcd_height;
    }

    uint32_t get_bits_per_pixel() const
    {
        return this->get_bits_per_pixel;
    }

    /***************************************/
};

#endif
