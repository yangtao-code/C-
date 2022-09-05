#pragma once

#ifndef POINT_H_
#define POINT_H_

#include <iostream>
using namespace std;

#include "circle.h"

class Point
{
private:
	int m_x;
	int m_y;

public:
	void set_x(int x);
	int get_x();

	void set_y(int y);
	int get_y();
	
	//判断点和圆的位置关系，返回1为在圆上，返回-1为在圆内，返回1为在圆外
	int point_place(Circle c);
	
};

#endif // !POINT_H_


