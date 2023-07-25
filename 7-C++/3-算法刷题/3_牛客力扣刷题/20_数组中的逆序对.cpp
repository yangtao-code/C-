#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定,请勿修改,直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int InversePairs(vector<int> &nums)
    {
        //std::cout<<"nums.size() = "<<nums.size()<<std::endl;
        return process(nums, 0, nums.size() - 1);
    }

    int process(vector<int> &nums, int L, int R)
    {
        if (L == R)
            return 0;

        int Mid = R + ((L - R) >> 1);

        return process(nums, L, Mid) + process(nums, Mid + 1, R) + merge(nums, L, Mid, R);
    }

    int merge(vector<int> &nums, int L, int M, int R)
    {
        int ret = 0;
        vector<int> help;
        int p1 = L;
        int p2 = M + 1;

        while (p1 <= M && p2 <= R)
        {
            ret += nums[p1] > nums[p2] ? 1 : 0;
            help.push_back(nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++]);
        }

        while (p1 <= M)
        {
            help.push_back(nums[p1++]);
        }

        while (p2 <= R)
        {
            help.push_back(nums[p2++]);
        }
        for (int i = 0; i < R - L + 1; i++)
        {
            nums[L + i] = help[i];
        }

        return ret;
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

    Solution b;
    //b.InversePairs(arr);
    std::cout<<"ret = "<<b.InversePairs(arr)<<std::endl;

    std::cout << "排序之后....." << std::endl;
    print_arr(arr);

    return 0;
}
