#include <iostream>
#include <thread>
using namespace std;

int main()
{
    int num = thread::hardware_concurrency();
    cout << "CPU number: " << num << endl;
}




// #include <iostream>
// using namespace std;

// #include "Screen.h"
// #include "Rectangle.hpp"

// int main(int argc, char const *argv[])
// {
//     Screen s;
    
//     //s.draw_Rectangle(800,480,0,0,0xff0000);

//     Rectangle rect(800,480,0xffffff);
//     rect.draw(s,0,0);

//     return 0;
// }
