#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

void dstime(const tm *ptm); //打印当前系统时间

int main(int argc, char const *argv[])
{
    while (1)
    { //获取当前系统时间
        time_t numtime = time(NULL);
        cout << "numtime = " << numtime << endl;
        tm *local;
        local = localtime(&numtime);
        dstime(local);
        sleep(1);
    }
    return 0;
}

void dstime(const tm *ptm)
{
    char *pxq[] = {"日", "一", "二", "三", "四", "五", "六"};

    cout << ptm->tm_year + 1900 << "年" << ptm->tm_mon << "月" << ptm->tm_mday << "日\t";
    cout << ptm->tm_hour << ":" << ptm->tm_min << ":" << ptm->tm_sec << "\t";
    cout << "星期" << pxq[ptm->tm_wday] << "\t";
    cout << "当年的第" << ptm->tm_yday << "天" << endl;
}
