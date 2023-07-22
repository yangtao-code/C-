#include <iostream>
using namespace std;
#include "Rectangle.h"

Rectangle::Rectangle(const unsigned int& l, const unsigned int& w,
                     const int& x, const int& y, const unsigned int& color)
    : m_l(l), m_w(w), m_x0(x), m_y0(y), m_color(color)
{
    // this->m_l = l;
    // this->m_w = w;
    // this->m_x0 = x;
    // this->m_y0 = y;
    // this->m_color = color;
}

void Rectangle::move(const int &x, const int &y)
{
    this->m_x0 = x;
    this->m_y0 = y;
}

void Rectangle::setColor(const unsigned int &color)
{
    this->m_color = color;
}

void Rectangle::resize(const unsigned int &l, const unsigned int &w)
{
    this->m_l = l;
    this->m_w = w;
}

unsigned int Rectangle::get_L()
{
    return this->m_l;
}

unsigned int Rectangle::get_W()
{
    return this->m_w;
}

unsigned int Rectangle::get_color()
{
    return this->m_color;
}

int Rectangle::get_X()
{
    return this->m_x0;
}

int Rectangle::get_Y()
{
    return this->m_y0;
}