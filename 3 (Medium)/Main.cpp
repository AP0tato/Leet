#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution 
{
    public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<string> substr;
        string str = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(str.find(s[i]) != string::npos)
            {
                substr.push_back(str);
                s.erase(0, 1);
                i = -1;
                str = "";
            }
            else
            {
                str += s[i];
            }
        }
        substr.push_back(str);
        int largest = 0;
        for(string i : substr)
        {
            largest = i.length() > largest ? i.length() : largest;
        }
        return largest;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> s {"abcabcbb", "pwwkew", "aab", "dvdf"};
    Solution sol;
    for(string i : s)
    {
        cout << i << ": " << sol.lengthOfLongestSubstring(i) << endl;
    }
    return 0;
}
