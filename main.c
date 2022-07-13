/**
 * @file 学生成绩管理系统
 * @author 阳涛 (2245377079@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "stusys.h"

int main()
{
    int input; //创建选择变量，从键盘输入
    //创建学生管理系统
    StuSys stusys;
    //初始化学生管理系统
    InitStuSys(&stusys);

    do
    {
        menu(); //菜单函数
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            AddStuSys(&stusys);
            break;
        case DEL:
            DelStuSys(&stusys);
            break;
        case SCORE:
            ScoreStuSys(&stusys);
            break;
        case SEARCH:
            SearchStuSys(&stusys);
            break;
        case MODIFY:
            ModifyStuSys(&stusys);
            break;
        case SORT:
            SortStuSys(&stusys);
            break;
        case SHOW:
            ShowStuSys(&stusys);
            break;
        case SAVE:
            SaveStuSys(&stusys);
            break;
        case EXIT:
            SaveStuSys(&stusys);
            DestroyStuSys(&stusys);
            printf("已退出！\n");
            break;
        default:
            printf("选择错误，请重新选择:>\n");
            break;
        }
    } while (input);

    return 0;
}
