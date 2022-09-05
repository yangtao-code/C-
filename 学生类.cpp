#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

#include <iostream>
using namespace std;

#include <string>
#include <math.h>
#include "circle.h"
#include "point.h"

int main()
{
	Circle c1;
	c1.set_x(0);
	c1.set_y(0);
	c1.set_r(1);

	Point p1;
	p1.set_x(1);
	p1.set_y(1);

	int ret = p1.point_place(c1);
	switch (ret)
	{
	case 1:
		cout << "该点在圆外！" << endl;
		break;
	case 0:
		cout << "该点在圆上！" << endl;
		break;
	case -1:
		cout << "该点在圆内！" << endl;
		break;
	}
	system("pause");
	return 0;
}

//class Cobe
//{
//
//public:
//	//行为
//	
//	void set_cobe(int len, int wide, int hight)
//	{
//		m_len = len;
//		m_wide = wide;
//		m_hight = hight;
//	}
//
//	//获取长
//	int getL()
//	{
//		return m_len;
//	}
//
//	//获取宽
//	int getW()
//	{
//		return m_wide;
//	}
//
//	//获取高
//	int getH()
//	{
//		return m_hight;
//	}
//
//	int get_area()
//	{
//		return 2 * (m_len * m_wide + m_len * m_hight + m_wide * m_hight);
//	}
//
//	int get_volume()
//	{
//		return m_len * m_wide * m_hight;
//	}
//
//	bool issameByclass(Cobe& c)
//	{
//		if (m_len == c.getL() && m_wide == c.getW() && m_hight == c.getH())
//		{
//			return true;
//		}
//		return false;
//	}
//
//private:
//	//属性
//	int m_len;
//	int m_wide;
//	int m_hight;
//
//};
//
//bool issame(Cobe c1, Cobe c2)
//{
//	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
//	{
//		return true;
//	}
//	return false;
//}
//
//
//int main()
//{
//	Cobe c1;
//	c1.set_cobe(10, 20, 10);
//	cout << "面积：" << c1.get_area() << " 体积：" << c1.get_volume() << endl;
//
//	Cobe c2;
//	c2.set_cobe(10, 20, 10);
//	cout << "面积：" << c2.get_area() << " 体积：" << c2.get_volume() << endl;
//
//	if (c1.issameByclass(c2))
//	{
//		cout << "成员函数推断：两个立方体是相等的！" << endl;
//	}
//	else
//	{
//		cout << "成员函数推断：两个立方体不是相等的！" << endl;
//	}
//
//	if (issame(c1,c2))
//	{
//		cout << "全局函数推断：两个立方体是相等的！" << endl;
//	}
//	else
//	{
//		cout << "全局函数推断：两个立方体不是相等的！" << endl;
//	}
//
//	system("pause");
//	return 0;
//}

//class Student
//{
//public:
//	string stu_name, stu_id;
//	void set_student(string name, string id)
//	{
//		stu_name = name;
//		stu_id = id;
//	}
//
//	//学生的姓名属性
//	//string stu_name;
//	/*void set_name(string name)
//	{
//		string stu_name = name;
//	}*/
//	//学生的学号属性
//	//string stu_id;
//	/*void set_id(string id)
//	{
//		string stu_id = id;
//	}*/
//
//	//行为
//	void show_stu()
//	{
//		cout << "姓名：" << stu_name;
//		cout << " 学号：" << stu_id<<endl;
//	}
//};


//int main()
//{
//	Student s1;
//	s1.stu_name = "zhangshan";
//	s1.stu_id = "202006020131";
//
//	s1.show_stu();
//
//	Student s2;
//	s2.set_student("lisi", "202006020129");
//	s2.show_stu();
//
//	system("pause");
//	return 0;
//}
