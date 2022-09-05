#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

#include "circle.h"

void Circle::set_x(int x)
{
	m_x = x;
}
int Circle::get_x()
{
	return m_x;
}

void Circle::set_y(int y)
{
	m_y = y;
}
int Circle::get_y()
{
	return m_y;
}

void Circle::set_r(int r)
{
	m_r = r;
}
int Circle::get_r()
{
	return m_r;
}
