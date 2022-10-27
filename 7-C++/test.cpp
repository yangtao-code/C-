#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        m_a = 100;
    }
    void func(int a)
    {
        cout << "Base func(int a)" << endl;
    }
    void func()
    {
        cout << "Base func()" << endl;
    }
    int m_a;
};
class Son : public Base
{
public:
    Son()
    {
        m_a = 200;
    }
    void func()
    {
        cout << "Son func()" << endl;
    }
    int m_a;
};

void test1()
{
    Son s;
    cout << "(Son) m_a = " << s.m_a << endl;
    cout << "(Base) m_a = " << s.Base::m_a << endl;
}
void test2()
{
    Son s;
    s.func();
    s.Base::func(10);
    s.Base::func();
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    return 0;
}
