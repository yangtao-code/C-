#include <iostream>
using namespace std;
#include <vector>
#include <map>

//枚举法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        for(int i = 0;i < size - 1; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int size = nums.size();
//         map<int,int>dir;
//         for(int i = 0; i < size; i++)
//         {
//             if(dir.count(target - nums[i]) >= 0)
//             {
//                 return {dir[target - nums[i]],i};
//             }
//             dir.insert(nums[i],i);
//         }
//         return {};
//     }
// };

int main(int argc, char const *argv[])
{
    
    return 0;
}

//两数相加
