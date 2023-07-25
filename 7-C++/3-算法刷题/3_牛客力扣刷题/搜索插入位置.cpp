#include <iostream>
#include <vector>
#include <algorithm>


// class Solution
// {
// public:
//     int searchInsert(std::vector<int> &nums, int target)
//     {
//         if (target < nums[0])
//             return 0;
//         if (target > nums[nums.size() - 1])
//             return nums.size();
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (target == nums[i])
//                 return i;
//             if (target > nums[i] && target < nums[i + 1])
//                 return i + 1;
//         }
//     }
// };

//二分查找法解题
class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int r = nums.size() - 1;    //数组最后一个元素的位置
        int l = 0;                  //数组第一个元素的位置
        if (target < nums[0])
            return 0;
        if (target > nums[r])
            return r + 1;
        int m;
        while(r > l)
        {
            int m = (l + r) / 2;
            if(nums[m] == target)
                break;
            else if(nums[m] < target)
            {
                if(nums[m+1] >= target)
                    return m+1;
                l = m + 1;
            }
            else
            {
                if(nums[m - 1] <= target)
                    return m - 1;
                r = m - 1;
            }
        }
        return m;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
