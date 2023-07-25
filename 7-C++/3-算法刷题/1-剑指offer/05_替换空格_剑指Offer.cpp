#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    string replaceSpace(string s) 
    {
        string ret;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                ret += "%20";
                continue;
            }
            ret += s[i];
            
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    s += "hello world                                                                ";
    char* str = new char[32];
    cout<<sizeof(s.c_str())<<endl;
    cout<<sizeof(str)<<endl;
    return 0;
}
