#include <iostream>
#include <vector>
using namespace std;

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        int left = 0, right = sum;
        for (int i = 0; i < nums.size(); i++)
        {
            right = right - nums[i];
            if (left == right)
                return i;
            left += nums[i];
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr = {1, 2, 3, 3};
    cout << s.pivotIndex(arr) << endl;
    return 0;
}
