#ifndef FUN_H_
#define FUN_H_


#define N 3

/**
 * @brief 函数功能为统计字符串中单词数量
 * 
 * @param str 
 * @return int 
 */
int fun1(char *str);

typedef struct Stu
{
    char name[10];
    int score;
} Stu;

/**
 * @brief 找出学生数组中的最低分，通过形参返回主函数
 * 
 * @param a 
 * @param s 
 */
void fun2(Stu a[],Stu *s);


/**
 * @brief 使N*N数组的上三角*m
 * 
 * @param m 
 */
void fun3(int (*a)[N],int m);

double fun4(int (*a)[N]);

double fun5(double a);

void fun6(int (*a)[N]);

#endif