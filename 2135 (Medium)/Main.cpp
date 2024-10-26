#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int count = 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution *s;
    vector<string> st = {"ant","act","tack"};
    vector<string> v = {"tack","act","acti"};
    cout << s->wordCount(st, v);
}
