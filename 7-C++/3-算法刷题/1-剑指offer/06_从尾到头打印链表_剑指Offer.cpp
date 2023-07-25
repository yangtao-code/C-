#include <iostream>
using namespace std;
#include <vector>
#include <stack>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//递归算法解
// class Solution
// {
// public:
//     vector<int> reversePrint(ListNode *head)
//     {
//         vector<int> ret;
//         if (head == NULL)
//             return ret;
//         ret = reversePrint(head->next);
//         ret.push_back(head->val);
//         return ret;
//     }
// };

//利用栈先人后出的特点
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        stack<int> tmp;
        while(head != NULL)
        {
            tmp.push(head->val);
            head = head->next;
        }

        vector<int> ret;
        while(tmp.empty() != true)
        {
            ret.push_back(tmp.top());
            tmp.pop();
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
