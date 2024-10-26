#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b)
            return -1;
        else
            return max(a.length(), b.length());
    }
};

int main()
{
    Solution *s;
    string a = "abc";
    string b = "cdc";
    cout<<s->findLUSlength(a, b);
}