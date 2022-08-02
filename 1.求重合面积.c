#include <stdio.h>
#include <stdlib.h>

//矩形的数据
typedef struct rectangle_squareness
{
    int x1, y1; //矩形左上角坐标
    int x2, y2; //矩形右下角坐标
    int area;   //矩形面积
} rangle_square;

void get_area(rangle_square *date, int k, int *area_sum);

int main(int argc, char const *argv[])
{
    int N;            //矩形个数
    int area_sum = 0; //矩形重合面积和
    printf("你要输入几个矩形：");
    scanf("%d", &N);
    rangle_square *date = (rangle_square *)malloc(sizeof(rangle_square) * N);
    for (int i = 0; i < N; i++)
    {
        printf("请输入第%d个矩形：\n", i + 1);
        scanf("%d%d", &date[i].x1, &date[i].y1);
        scanf("%d%d", &date[i].x2, &date[i].y2);
        get_area(date, i, &area_sum);
    }

    printf("重合的面积为：%d\n", area_sum / 10000);
    return 0;
}

void get_area(rangle_square *date, int k, int *area_sum)
{
    for (int i = 0; i < k; i++)
    {
        for (int x = date[k].x1 * 100; x <= date[k].x2 * 100; x++)
        {
            for (int y = date[k].y1 * 100; y <= date[k].y2 * 100; y++)
            {
                if (x >= date[i].x1 * 100 && x <= date[i].x2 * 100 && y >= date[i].y1 * 100 && y <= date[i].y2 * 100)
                    (*area_sum)++;
            }
        }
    }
}
