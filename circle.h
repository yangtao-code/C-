#pragma once

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <iostream>
using namespace std;

class Circle
{
	//����
private:
	int m_x;	//Բ�ĵ�x��
	int m_y;	//Բ�ĵ�y��
	int m_r;	//Բ�İ뾶
public:
	void set_x(int x);
	int get_x();
	
	void set_y(int y);
	int get_y();
	
	void set_r(int r);
	int get_r();
};

#endif 


