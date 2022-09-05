#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

#include "point.h"


void Point::set_x(int x)
{
	m_x = x;
}
int Point::get_x()
{
	return m_x;
}

void Point::set_y(int y)
{
	m_y = y;
}
int Point::get_y()
{
	return m_y;
}
//�жϵ��Բ��λ�ù�ϵ������1Ϊ��Բ�ϣ�����-1Ϊ��Բ�ڣ�����1Ϊ��Բ��
int Point::point_place(Circle c)
{
	int a = pow(c.get_r(), 2);
	int b = pow(m_x - c.get_x(), 2) + pow(m_y - c.get_y(), 2);
	if (a == b)
	{
		return 0;
	}
	else if (a < b)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
