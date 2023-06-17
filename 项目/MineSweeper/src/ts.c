#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include "ts.h"
#include "lcd.h"

int ts_fd = -1;

int open_ts()
{
    ts_fd = open("/dev/input/event0", O_RDWR | O_NONBLOCK);
    if (ts_fd < 0)
    {
        perror("open /dev/input/event0 failed");
        return -1;
    }
    return 0;
}

int get_state(int *x, int *y)
{
    lseek(ts_fd, 0, SEEK_SET);
    struct input_event ev;
    // 触摸第一次的坐标
    int x0 = -1, y0 = -1;
    int num = 0;
    // 实时坐标,最终为手最后一次离开触摸屏的
    while (1)
    {
        if (ev.type == EV_KEY && ev.code == 330 && ev.value == 1)
        {
            num = 0;
        }
        num++;
        int n = read(ts_fd, &ev, sizeof(struct input_event));
        if (n != sizeof(struct input_event))
        {
            continue;
        }
        if (ev.type == EV_ABS && ev.code == ABS_X)
        {
            if (x0 == -1)
            {
                x0 = ev.value;
            }
            *x = ev.value;
        }
        if (ev.type == EV_ABS && ev.code == ABS_Y)
        {
            if (y0 == -1)
            {
                y0 = ev.value;
            }
            *y = ev.value;
        }
        if (ev.type == EV_KEY && ev.code == 330 && ev.value == 0)
        {
            printf("leave\n");
            break;
        }
    }
    x0 = x0 * 800 / 1024;
    *x = *x * 800 / 1024;
    y0 = y0 * 480 / 600;
    *y = *y * 480 / 600;
    printf("触摸开始坐标(%d , %d)\n", x0, y0);
    printf("触摸结束坐标(%d , %d)\n", *x, *y);
    printf("num = %d\n", num);
    if (x0 == *x && y0 == *y)
    {
        if (*x >= 760 && *x < 800 && *y >= 0 && *y < 20)
        {
            printf("SHUT\n");
            return SHUT;
        }
        else if (num > 400000)
        {
            printf("PRESS\n");
            return PRESS;
        }
        return -1;
    }
    // 根据斜率k获得方向值
    int k = abs((*y - y0) / (double)(*x - x0));
    // 上下方向
    if (k >= 1)
    {
        if (*y > y0)
        {
            printf("DOWN\n");
            return DOWN;
        }
        else if (*y < y0)
        {
            printf("UP\n");
            return UP;
        }
    }
    else
    {
        if (*x > x0)
        {
            printf("RIGHT\n");
            return RIGHT;
        }
        else if (*x < x0)
        {
            printf("LEFT\n");
            return LEFT;
        }
    }
}

int Close_software(int x, int y)
{
    if (x >= 760 && x < 800 && y >= 0 && y < 20)
    {
        display_jpg(250, 165, "./pic/10.jpg");
        while (1)
        {
            get_state(&x, &y);
            if (x >= 275 && x <= 385 && y >= 210 && y <= 285)
            {
                display_Square(0,0,800,480,0xffffff);
                close_ts();    // 关闭触摸屏
                destroy_lcd(); // 关闭屏幕
                // printf("程序正在退出!\n");
                sleep(1);
                printf("退出成功!\n");
                exit(0);
            }
            else if (x >= 420 && x <= 525 && y >= 210 && y <= 285)
            {
                return 0;
            }
        }
    }
}

int return_pre(int x, int y)
{
    if ((x - 775) * ((x - 775)) + (y - 455) * (y - 455) <= 625)
    {
        return 1;
    }
    return 0;
}

int close_ts()
{
    int ret = close(ts_fd);
    if (ret < 0)
    {
        perror("close /dev/input/event0 failed");
        return -1;
    }
    return 0;
}
