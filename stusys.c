#include "stusys.h"

void menu()
{
    printf("*********************************\n");
    printf("****  1.Add       2.Del      ****\n");
    printf("****  3.Score     4.Search   ****\n");
    printf("****  5.Modify    6.Sort     ****\n");
    printf("****  7.Show      8.Save     ****\n");
    printf("****  0.Exit                 ****\n");
    printf("*********************************\n");
}

void InitStuSys(StuSys *ps)
{
    ps->stu = (PeoInfo *)malloc(DEFAULT_SZ * sizeof(PeoInfo));
    if (ps == NULL)
    {
        return;
    }
    ps->size = 0;
    ps->capacity = DEFAULT_SZ;
    //加载学生管理系统的数据
    LoadStuSys(ps);
    printf("初始化成功！\n");
}

void LoadStuSys(StuSys *ps)
{
    //创建一个临时结构体变量接收文件中的数据
    PeoInfo tmp = {0};
    FILE *pfRead = fopen("stusys.dat", "rb");
    if (pfRead == NULL)
    {
        printf("LoadStusys:%s\n", strerror(errno));
        return;
    }
    while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
    {
        ps->stu[ps->size] = tmp;
        ps->size++;
        //判断学生管理系统的容量是否够，不够则扩容
        CheakCapacity(ps);
    }
    printf("加载成功！\n");
    fclose(pfRead);
    pfRead = NULL;
}

void CheakCapacity(StuSys *ps)
{

    if (ps->size == ps->capacity)
    {
        PeoInfo *ptr = (PeoInfo *)realloc(ps->stu, (ps->capacity + 2) * sizeof(PeoInfo));
        if (ptr == NULL)
        {
            printf("扩容失败！\n");
        }
        else
        {
            printf("扩容成功！\n");
            ps->stu = ptr;
            ps->capacity += 2;
        }
    }
}

void SaveStuSys(StuSys *ps)
{
    FILE *pfWrite = fopen("stusys.dat", "wb");
    if (pfWrite == NULL)
    {
        printf("SaveStuSys:%s\n", strerror(errno));
        return;
    }
    for (int i = 0; i < ps->size; i++)
    {
        fwrite(&ps->stu[i], sizeof(PeoInfo), 1, pfWrite);
    }
    fclose(pfWrite);
    pfWrite == NULL;
    printf("保存成功！\n");
}

void AddStuSys(StuSys *ps)
{
    CheakCapacity(ps);
    printf("请输入学生名字:>");
    scanf("%s", ps->stu[ps->size].name);
    printf("请输入成绩:>");
    scanf("%lf", &ps->stu[ps->size].score);
    ps->size++;
    printf("增加成功！\n");
}

void ShowStuSys(const StuSys *ps)
{
    if (ps->size == 0)
    {
        printf("当前学生成绩管理系统未录入信息！\n");
        return;
    }
    printf("%-12s%-6s\n", "名字", "成绩");
    for (int i = 0; i < ps->size; i++)
    {
        printf("%-12s", ps->stu[i].name);
        printf("%.2lf\n", ps->stu[i].score);
    }
    printf("\n");
    printf("展示成功！\n");
}

void DestroyStuSys(StuSys *ps)
{
    //释放之前开辟的空间
    free(ps->stu);
    ps->stu = NULL;
    memset(ps, 0, sizeof(StuSys));
}

void DelStuSys(StuSys *ps)
{
    char name[MAX_NAME];
    do
    {
        printf("请输入你要删除的学生名字:>");
        scanf("%s", name);
        int ret = FindByname(ps, name);
        if (ret == -1)
        {
            printf("未找到该学生，请重新输入！\n");
        }
        else
        {
            for (int i = ret; i < ps->size - 1; i++)
            {
                ps->stu[i] = ps->stu[i + 1];
            }
            ps->size--;
            break;
        }
    } while (1);
    printf("删除成功！\n");
}

int FindByname(const StuSys *ps, char name[])
{
    int i;
    for (i = 0; i < ps->size; i++)
    {
        if (strcmp(ps->stu[i].name, name) == 0)
        {
            break;
        }
    }
    if (i == ps->size)
    {
        return -1; //返回-1为未找到
    }
    return i;
}

void SearchStuSys(const StuSys *ps)
{
    char name[MAX_NAME];
    printf("请输入你要查找的学生姓名:>");
    scanf("%s", name);
    int ret = FindByname(ps, name);
    if (ret == -1)
    {
        printf("未找到该学生！\n");
    }
    else
    {
        printf("%-12s%-6s\n", "名字", "成绩");
        printf("%-12s", ps->stu[ret].name);
        printf("%.2lf\n", ps->stu[ret].score);
        printf("\n已找到！\n");
    }
}

void ModifyStuSys(StuSys *ps)
{
    char name[MAX_NAME];
    printf("请输入你要修改的学生姓名:>");
    scanf("%s", name);
    int ret = FindByname(ps, name);
    if (ret == -1)
    {
        printf("未找到该学生！\n");
    }
    else
    {
        printf("请输入学生名字:>");
        scanf("%s", ps->stu[ret].name);
        printf("请输入成绩:>");
        scanf("%lf", &ps->stu[ret].score);
        printf("修改成功！\n");
    }
}

void SortStuSys(StuSys *ps)
{
    PeoInfo tmp;
    int i, j;
    for (i = 0; i < ps->size; i++)
    {
        for (j = 0; j < ps->size - i - 1; j++)
        {
            if (ps->stu[j].score > ps->stu[j + 1].score)
            {
                tmp = ps->stu[j];
                ps->stu[j] = ps->stu[j + 1];
                ps->stu[j + 1] = tmp;
            }
        }
    }
    printf("排序成功！\n");
}

void ScoreStuSys(const StuSys *ps)
{
    double max = 0;
    double min = 0;
    double aver = 0;
    double sum = 0;
    double pass_rate = 0;
    int count = 0;
    max = ps->stu[0].score;
    min = ps->stu[0].score;
    sum = ps->stu[0].score;
    if (ps->stu[0].score > 60)
    {
        count++;
    }
    for (int i = 1; i < ps->size; i++)
    {
        if (ps->stu[i].score < min)
        {
            min = ps->stu[i].score;
        }
        if (ps->stu[i].score > max)
        {
            max = ps->stu[i].score;
        }
        if (ps->stu[i].score > 60)
        {
            count++;
        }
        sum = sum + ps->stu[i].score;
    }
    aver = sum / (ps->size);
    pass_rate = (double)count / (ps->size);
    printf("最高成绩为:>%.2lf\n", max);
    printf("最低成绩为:>%.2lf\n", min);
    printf("平均成绩为:>%.2lf\n", aver);
    printf("及格率为:>%.2lf%c\n", pass_rate*100,'%');
}