#pragma once

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <iostream>
using namespace std;

class Circle
{
	//属性
private:
	int m_x;	//圆心的x轴
	int m_y;	//圆心的y轴
	int m_r;	//圆的半径
public:
	void set_x(int x);
	int get_x();
	
	void set_y(int y);
	int get_y();
	
	void set_r(int r);
	int get_r();
};

#endif 


