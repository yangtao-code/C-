#include <iostream>
#include <vector>

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

class InsertionSort
{
public:
    void operator()(std::vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i; j > 0; j--)
            {
                if (arr[j - 1] > arr[j])
                {
                    Swap(arr[j - 1], arr[j]);
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
    std::cout << "排序之前....." << std::endl;
    print_arr(arr);

    InsertionSort b;
    b(arr);

    std::cout << "排序之后....." << std::endl;
    print_arr(arr);

    return 0;
}
