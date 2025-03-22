#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        std::map<char, int> map = {
            {'a', 2},{'b', 3},{'c', 3},{'d', 2},{'e', 1},{'f', 2},{'g', 2},{'h', 2},{'i', 1},{'j', 2},{'k', 2},{'l', 2},{'m', 3},{'n', 3},{'o', 1},{'p', 1},{'q', 1},{'r', 1},{'s', 2},{'t', 1},{'u', 1},{'v', 3},{'w', 1},{'x', 3},{'y', 1},{'z', 3}
        };
        std::vector<string> ans;
        for(int i = 0; i < words.size(); i++)
        {
            int prev = map[(char)tolower(words[i][0])];
            bool yes = true;
            for(int j = 0; j < words[i].size(); j++)
            {
                if(map[(char)tolower(words[i][j])]!=prev)
                {
                    yes = false;
                    break;
                }
                prev = map[(char)tolower(words[i][j])];
            }
            if(yes)
                ans.push_back(words[i]);
        }
        return ans;
    }
};