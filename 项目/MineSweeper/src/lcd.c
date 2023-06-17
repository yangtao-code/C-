#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <math.h>
#include <jconfig.h>
#include <jerror.h>
#include <jmorecfg.h>
#include <jpeglib.h>
#include "lcd.h"

unsigned int *plcd = NULL;

int lcd_fd = -1;

void init_lcd()
{
    lcd_fd = open("/dev/fb0", O_RDWR);
    if (lcd_fd < 0)
    {
        perror("open /dev/fb0 failed");
        exit(1);
    }

    plcd = mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if (plcd == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
}

void display_Point(int x, int y, unsigned int color)
{
    if (x >= 0 && x < 800 && y >= 0 && y < 480)
        *(plcd + 800 * (479 - y) + x) = color;
}

void display_ry_Point(int x, int y, unsigned int color)
{
    if (x >= 0 && x < 800 && y >= 0 && y < 480)
        *(plcd + 800 * y + x) = color;
}

void display_Square(int x0, int y0, unsigned l, unsigned int w, unsigned int color)
{
    for (int j = y0; j < y0 + w; j++)
    {
        for (int i = x0; i < x0 + l; i++)
        {
            display_ry_Point(i, j, color);
        }
    }
}

void display_Circle(int x0, int y0, int r, unsigned int color)
{
    for (int j = y0 - r; j < y0 + r; j++)
    {
        for (int i = x0 - r; i < x0 + r; i++)
        {
            if ((i - x0) * (i - x0) + (j - y0) * (j - y0) <= r * r)
            {
                display_Point(i, j, color);
            }
        }
    }
}

void display_semicircle(int x0, int y0, int r, unsigned int color)
{
    for (int j = y0 - r; j < y0 + r; j++)
    {
        for (int i = x0 - r; i < x0; i++)
        {
            if ((i - x0) * (i - x0) + (j - y0) * (j - y0) <= r * r)
            {
                display_Point(i, j, color);
            }
        }
    }
}

int open_bmp(const char *bmp_name, int *width, int *hight, short *depth)
{
    // 1.打开bmp图片
    int bmp_fd = open(bmp_name, O_RDONLY);
    if (bmp_fd < 0)
    {
        perror("open bmp failed");
        return -1;
    }
    lseek(bmp_fd, 0, SEEK_SET);
    char buf[4] = "";
    // 读bmp头,宽,高,深度
    int n = read(bmp_fd, buf, 2);
    if (buf[0] != 0x42 || buf[1] != 0x4d || n != 2)
    {
        printf("%s not bmp or The bmp is damaged.\n ", bmp_name);
        close(bmp_fd);
        return -1;
    }

    lseek(bmp_fd, 0x12, SEEK_SET);
    n = read(bmp_fd, width, 4);
    if (n != 4)
    {
        perror("read bmp failed");
        close(bmp_fd);
        return -1;
    }
    lseek(bmp_fd, 0x16, SEEK_SET);
    n = read(bmp_fd, hight, 4);
    if (n != 4)
    {
        perror("read bmp failed");
        close(bmp_fd);
        return -1;
    }
    lseek(bmp_fd, 0x1c, SEEK_SET);
    n = read(bmp_fd, depth, 2);
    if (n != 2)
    {
        perror("read bmp failed");
        close(bmp_fd);
        return -1;
    }
    if (!(*depth == 32 || *depth == 24))
    {
        printf("NOT depth!\n");
        close(bmp_fd);
        return -1;
    }
    return bmp_fd;
}

int display_bmp(int x0, int y0, const char *bmp_name)
{
    int width, hight;
    short depth;
    // 打开bmp图片,并读取宽度,高度,深度,文件描述符
    int bmp_fd = open_bmp(bmp_name, &width, &hight, &depth);
    if (bmp_fd == -1)
        return -1;
    // 获取像素数组
    int line_valid_bytes = abs(width) * depth / 8; // 一行的有效字节数
    int line_bytes;                                // 一行的实际字节数 = 一行的有效字节数 + 赖子
    int laizi = 0;                                 // 赖子
    if (line_valid_bytes % 4 != 0)
    {
        laizi = 4 - line_valid_bytes % 4;
    }
    line_bytes = line_valid_bytes + laizi;
    int bytes = line_bytes * abs(hight); // 像素数组大小
    char bmp_buf[bytes];                 // 定义色素数组缓冲区
    lseek(bmp_fd, 0x36, SEEK_SET);

    int n = read(bmp_fd, bmp_buf, bytes); // 读bmp的色素数组
    if (n != bytes)
    {
        printf("read bmp failed\n");
        close(bmp_fd);
        return -1;
    }
    int i = 0;
    char a, r, g, b;    // 透明度和三原色
    unsigned int color; // 颜色
    for (int y = 0; y < abs(hight); y++)
    {
        for (int x = 0; x < abs(width); x++)
        {
            b = bmp_buf[i++];
            g = bmp_buf[i++];
            r = bmp_buf[i++];
            if (depth == 32)
            {
                a = bmp_buf[i++];
            }
            else if (depth == 24)
            {
                a = 0;
            }
            color = a << 24 | r << 16 | g << 8 | b;
            display_ry_Point(width > 0 ? x + x0 : abs(width) - x - 1 + x0,
                             hight > 0 ? abs(hight) - y - 1 + y0 : y + y0,
                             color);
        }
        i = i + laizi;
    }
    // 关闭bmp图片
    close(bmp_fd);
    return 0;
}

int display_jpg(int x0, int y0, const char *jpg_name)
{
    if (NULL == strstr(jpg_name, ".jpg"))
    {
        printf("%s不是一个jpg图片!\n", jpg_name);
        return -1;
    }
    // 第一步:分配并初始化应该jpeg解压缩对象
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo); // 初始化cinfo这个解压缩对象
    // 第二步:指定要解压的JPEG文件
    // 1.打开jpg文件
    FILE *infile = fopen(jpg_name, "rb");
    if (infile == NULL)
    {
        perror("fopen failed");
        return -1;
    }
    // 2. 指定要解压的jpg文件
    jpeg_stdio_src(&cinfo, infile);

    // 第三步:调用jpeg_read_header获取图像信息(比如:宽/高等)

    jpeg_read_header(&cinfo, TRUE);
    // 第四步:设置参数,一般采用默认参数

    // 第五步:开始解压缩
    jpeg_start_decompress(&cinfo);
    printf("%s: 宽 = %d,高 = %d,分度值 = %d\n",
           jpg_name, cinfo.output_width, cinfo.output_height, cinfo.output_components);
    // 行字节数
    int rowbyte = cinfo.output_width * cinfo.output_components;
    // 总字节数
    int byte = cinfo.output_width * cinfo.output_height * cinfo.output_components;

    // cinfo.output_scanline表示现在已经解压扫描读取了多少行的数据,初始值为0
    unsigned char *buf = (unsigned char *)malloc(rowbyte);
    while (cinfo.output_scanline < cinfo.output_height)
    {

        // 第一个参数表示解压对象
        // 第二个参数表示保存解压后的数据的空间(二级指针)
        // 第三个参数表示读取多少行数据进行解压
        jpeg_read_scanlines(&cinfo, &buf, 1);

        // cinfo.output_scanline 自动+1
        // 将读取出来并解压缩的JPEG的一行显示到屏幕的对应位置上去
        unsigned int color;
        int x;
        int i = 0;
        unsigned char a, r, g, b;
        for (x = 0; x < cinfo.output_width; x++)
        {

            if (cinfo.output_components == 3)
            {
                a = 0xff;
            }
            else
            {
                a = buf[i++];
            }
            r = buf[i++];
            g = buf[i++];
            b = buf[i++];
            color = (r << 16) | (g << 8) | b;
            display_ry_Point(x0 + x, y0 + cinfo.output_scanline - 1, color);
        }
    }

    /* Step 7: 调用jpeg_finish_decompress完成解压 */
    jpeg_finish_decompress(&cinfo);

    /* Step 8: 调用jpeg_destroy_decompress销毁解压缩对象 */
    jpeg_destroy_decompress(&cinfo);
    
    free(buf);
    fclose(infile);
    return 0;
}

void destroy_lcd()
{
    munmap(plcd, 800 * 480 * 4);
    plcd = NULL;
    int ret = close(lcd_fd);
    if (ret == -1)
    {
        perror("close lcd_fd failed");
        exit(1);
    }
}