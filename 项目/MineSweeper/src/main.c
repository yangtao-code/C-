#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lcd.h"
#include "ts.h"
#include "MineSweeper.h"

int main(int argc, char const *argv[])
{
    init_lcd(); // 初始化屏幕
    open_ts();  // 打开触摸屏
    int x, y;
    while (1)
    {
        display_bmp(0, 0, "./pic/menu.bmp");

        get_state(&x, &y);

        Close_software(x, y);

        if (x >= 300 && x < 500)
        {
            if (y >= 150 && y < 250)
            {
                game_level();
            }
            else if (y >= 300 && y < 400)
            {
                display_jpg(250, 165, "./pic/10.jpg");
                while (1)
                {
                    get_state(&x, &y);
                    if (x >= 275 && x <= 385 && y >= 210 && y <= 285)
                    {
                        display_Square(0, 0, 800, 480, 0xffffff);
                        close_ts();    // 关闭触摸屏
                        destroy_lcd(); // 关闭屏幕
                        // printf("程序正在退出!\n");
                        
                        printf("退出成功!\n");
                        exit(0);
                    }
                    else if (x >= 420 && x <= 525 && y >= 210 && y <= 285)
                    {
                        break;
                    }
                }
            }
        }
    }

    return 0;
}