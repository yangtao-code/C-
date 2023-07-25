#include <iostream>
#include <vector>

void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void print_arr(std::vector<int> &arr)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// 题目1:给定一个数组arr,和一个数num,请把小于等于num的数放在数 组的左边,大于num的
// 数放在数组的右边.要求额外空间复杂度O(1),时间复杂度O(N)
class Solution1
{
public:
    void operator()(std::vector<int> &arr, int num)
    {
        if (arr.size() <= 1)
            return;

        int l = 0;
        int r = arr.size() - 1;
        int less = 0;
        int more = r;
        while (l < more)
        {
            if (arr[l] <= num)
            {
                Swap(arr[l++], arr[less++]);
            }
            else if (arr[l] > num)
            {
                Swap(arr[l], arr[more--]);
            }
        }
    }
};

// 问题二(荷兰国旗问题)
// 给定一个数组arr,和一个数num,请把小于num的数放在数组的 左边,等于num的数放
// 在数组的中间,大于num的数放在数组的 右边.要求额外空间复杂度O(1),时间复杂度O(N)
class Solution2
{
public:
    void operator()(std::vector<int> &arr, int num)
    {
        if (arr.size() <= 1)
            return;

        int l = 0;
        int r = arr.size() - 1;
        int less = 0;
        int more = r;
        while (l <= more)
        {
            if (arr[l] < num)
            {
                Swap(arr[l++], arr[less++]);
            }
            else if (arr[l] > num)
            {
                Swap(arr[l], arr[more--]);
            }
            else
            {
                l++;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(nullptr));

    std::vector<int> arr;
    for (int i = 0; i < 20; i++)
    {
        arr.push_back(rand() % 49 + 1);
    }
    std::cout << "排序之前....." << std::endl;
    print_arr(arr);

    int randnum = arr[rand() % arr.size()];
    std::cout << "随机数: " << randnum << std::endl;
    Solution2 b;
    b(arr, randnum);

    std::cout << "排序之后....." << std::endl;
    print_arr(arr);
    return 0;
}
