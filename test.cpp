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
	cout << "�û��Ѻ������ڷ��ʣ�" << building->setting_room << endl;
	cout << "�û��Ѻ������ڷ��ʣ�" << building->bed_room << endl;
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
	setting_room = "����";
	bed_room = "����";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "�û��������ڷ��ʣ�" << building->setting_room << endl;
	cout << "�û��������ڷ��ʣ�" << building->bed_room << endl;
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
//	//1.�������캯��
//	Person()
//	{
//		cout << "�޲ι��캯���ĵ��ã�" << endl;
//	}
//
//	Person(int age, string& name)
//	{
//		m_age = age;
//		m_name = new string(name);
//		cout << "�вι��캯���ĵ��ã�" << endl;
//	}
//	//�����ṹ����
//	Person(const Person& p)
//	{
//		m_age = p.m_age;
//		m_name = new string(*p.m_name);
//		cout << "�������캯���ĵ��ã�" << endl;
//	}
//
//	//2.������������
//	~Person()
//	{
//		cout << "���������ĵ��ã�" << endl;
//	}
//
//
//	int m_age;
//	string* m_name;
//};
//
//void test01()
//{
//	//���ŷ�
//	/*Person p1;
//	Person p2(10);
//	Person p3(p2);*/
//
//	//��ʾ��
//	/*Person p1;
//	Person p2 = Person(10);
//	Person p3 = Person(p2);*/
//
//	//��ʽ��
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



