#include <iostream>
#include <array>
#include <vector>
using namespace std;

class Swap
{
public:
    Swap(int &a, int &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

class BubbleSort
{
public:
    void operator()(std::vector<int> &ar)
    {
        for (int i = ar.size() - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (ar[j] > ar[j + 1])
                {
                    Swap(ar[j], ar[j + 1]);
                }
            }
        }
    }
};

void print_arr(std::vector<int> &arr)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(nullptr));

    std::vector<int> arr;
    for (int i = 0; i < 5; i++)
    {
        arr.push_back(rand() % 99 + 1);
    }
    std::cout<<"排序之前....."<<std::endl;
    print_arr(arr);

    BubbleSort b;
    b(arr);

    std::cout<<"排序之后....."<<std::endl;
    print_arr(arr);
    return 0;
}
