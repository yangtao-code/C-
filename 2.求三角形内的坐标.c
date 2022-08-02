#include <stdio.h>

typedef struct zuobiao
{
    int x;
    int y;
} zuobiao;

/**
 * @brief 获得该三角形所在的矩形范围
 * 
 */
void get_scope();

/**
 * @brief 输出在三角形内的坐标
 * 
 */
void print_zuobiao();

/**
 * @brief 根据三角形的三个顶点实现求三角形的面积
 * 
 * @param s1 
 * @param s2 
 * @param s3 
 * @return int 
 */
int get_area(zuobiao s1, zuobiao s2, zuobiao s3);

zuobiao s[4];
int x_min, x_max; //矩形坐标的最小值
int y_min, y_max; //矩形坐标的最大值

int main(int argc, char const *argv[])
{
    printf("请输入三角形的三个坐标：\n");

    for (int i = 1; i <= 3; i++)
    {
        printf("第%d个坐标：\n", i);
        scanf("%d%d", &s[i].x, &s[i].y);
    }

    get_scope();

    print_zuobiao();

    return 0;
}

void print_zuobiao()
{
    int area = get_area(s[1], s[2], s[3]); //三角形的面积
    if (area == 0)
    {
        printf("输入错误，该图形不是三角形！\n");
        return;
    }

    for (int i = x_min; i <= x_max; i++)
    {
        for (int j = y_min; j <= y_max; j++)
        {
            s[0].x = i;
            s[0].y = j;
            int a1 = get_area(s[1], s[2], s[0]);
            int a2 = get_area(s[2], s[3], s[0]);
            int a3 = get_area(s[3], s[1], s[0]);
            int area3 = a1 + a2 + a3; //该矩形内的一点与三角形三个顶点组成的三个三角形的面积和
            //如果面积相同，说明该点在三角形内
            if (area == area3)
                printf("( %d , %d )\n", i, j);
        }
    }
}

int get_area(zuobiao s1, zuobiao s2, zuobiao s3)
{
    int area = s1.x * s2.y +
               s2.x * s3.y +
               s3.x * s1.y -
               s1.x * s3.y -
               s2.x * s1.y -
               s3.x * s2.y;
    if (area > 0)
        return area;
    else
        return 0 - area;
}

void get_scope()
{
    x_min = s[1].x, x_max = s[1].x;
    y_min = s[1].y, y_max = s[1].y;
    for (int i = 2; i <= 3; i++)
    {
        if (x_min > s[i].x)
            x_min = s[i].x;
        if (x_max < s[i].x)
            x_max = s[i].x;
        if (y_min > s[i].y)
            y_min = s[i].y;
        if (y_max < s[i].y)
            y_max = s[i].y;
    }
}
