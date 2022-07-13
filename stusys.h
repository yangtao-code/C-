#ifndef STUSYS_H
#define STUSYS_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_NAME 12  //名字字符串最大输入
#define DEFAULT_SZ 3 //学生成绩管理系统的默认容量为3

typedef struct PeoInfo
{
    char name[MAX_NAME]; //名字
    double score;         //成绩

} PeoInfo;

typedef struct StuSys
{
    PeoInfo *stu; //
    int size;     //录入学生的个数
    int capacity; //当前学生成绩管理系统的最大容量
} StuSys;
//建立一个选项枚举，增加代码的可读性
enum Option
{
    EXIT = 0,   //退出
    ADD = 1,    //录入
    DEL = 2,    //删除
    SCORE = 3,  //显示最高分，最低分，平均分，及格率
    SEARCH = 4, //搜索
    MODIFY = 5, //修改
    SORT = 6,   //排序
    SHOW = 7,   //显示所有
    SAVE = 8    //保存学生管理系统
};
//选择菜单
void menu();
//初始化学生管理系统，并把存储的数据录入学生管理系统
void InitStuSys(StuSys *ps);
//把数据文件中的数据录入学生管理系统
void LoadStuSys(StuSys *ps);
//查找学生管理系统的容量够不够，不够就扩容
void CheakCapacity(StuSys *ps);
//保存学生管理系统的数据
void SaveStuSys(StuSys *ps);
//录入学生姓名和成绩
void AddStuSys(StuSys *ps);
//显示学生成绩管理系统的学生信息
void ShowStuSys(const StuSys *ps);
//删除学生信息
void DelStuSys(StuSys *ps);
//销毁学生成绩管理系统
void DestroyStuSys(StuSys *ps);
//查找学生并输出他的位置，返回-1为未找到
int FindByname(const StuSys *ps, char name[]);
//搜索一位学生的信息
void SearchStuSys(const StuSys *ps);
//修改学生信息
void ModifyStuSys(StuSys *ps);
//为学生成功管理系统按成绩排序
void SortStuSys(StuSys *ps);
//输出所有学生成绩的最高成绩和最低成绩，平均成绩，及格率
void ScoreStuSys(const StuSys* ps);

#endif