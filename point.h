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
	
	//�жϵ��Բ��λ�ù�ϵ������1Ϊ��Բ�ϣ�����-1Ϊ��Բ�ڣ�����1Ϊ��Բ��
	int point_place(Circle c);
	
};

#endif // !POINT_H_


