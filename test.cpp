#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#include <string>


class GoodGay
{
public:
	GoodGay();
	void visit();
	Building* building;

};

class Building
{
	friend void goodgay(Building* building);
	//friend class GoodGay;
	friend void GoodGay::visit();
public:
	Building();


public:
	string setting_room;
private:
	string bed_room;
};


void goodgay(Building* building)
{
	cout << "好基友函数正在访问：" << building->setting_room << endl;
	cout << "好基友函数正在访问：" << building->bed_room << endl;
}


int main()
{
	//Building building;
	//goodgay(&building);
	GoodGay g;
	g.visit();

	return 0;
}

Building::Building()
{
	setting_room = "客厅";
	bed_room = "卧室";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "好基友类正在访问：" << building->setting_room << endl;
	cout << "好基友类正在访问：" << building->bed_room << endl;
}




//class Person
//{
//public:
//	Person(int age)
//	{
//		this->age = age;
//	}
//	
//	Person& PersonAddage(Person& p)
//	{
//		this->age += p.age;
//		return *this;
//	}
//
//	int age;
//};
//
//int main()
//{
//	Person p1(20);
//
//	Person p2(10);
//
//	p2.PersonAddage(p1);
//
//	cout << "p2.age = " << p2.age << endl;
//	return 0;
//}

//class Person
//{
//public:
//	//1.创建构造函数
//	Person()
//	{
//		cout << "无参构造函数的调用！" << endl;
//	}
//
//	Person(int age, string& name)
//	{
//		m_age = age;
//		m_name = new string(name);
//		cout << "有参构造函数的调用！" << endl;
//	}
//	//拷贝结构函数
//	Person(const Person& p)
//	{
//		m_age = p.m_age;
//		m_name = new string(*p.m_name);
//		cout << "拷贝构造函数的调用！" << endl;
//	}
//
//	//2.创建析构函数
//	~Person()
//	{
//		cout << "析构函数的调用！" << endl;
//	}
//
//
//	int m_age;
//	string* m_name;
//};
//
//void test01()
//{
//	//括号法
//	/*Person p1;
//	Person p2(10);
//	Person p3(p2);*/
//
//	//显示法
//	/*Person p1;
//	Person p2 = Person(10);
//	Person p3 = Person(p2);*/
//
//	//隐式法
//	Person p1;
//	string name = "yangchunhau";
//	Person p2(20, name);
//	Person p3 = p2;
//
//	cout << "p2.m_age = " << p2.m_age << endl;
//	cout << "p3.m_name = " << *p3.m_name << endl;
//}
//
//int main()
//{
//	test01();
//
//	//Person p2;
//
//	return 0;
//}



