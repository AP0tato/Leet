#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> out;
        int extra = s.length()%k==0?0:k-(s.length()%k);
        int i = 0;
        string tmp = "";
        for(i = 0; i < s.length(); i++) 
        {
            if((i+1)%k==0) 
            {
                tmp += string(1, s[i]);
                out.push_back(tmp);
                tmp = "";
            }
            else tmp += string(1, s[i]);
        }
        
        if(tmp!="") out.push_back(tmp);

        while((extra--)>0)
        {
            out[out.size()-1] += string(1, fill);
        }

        return out;
    }
};

int main() {
    string a = "abcdefghi";
    Solution s;
    vector<string> v = s.divideString(a, 3, 'x');
    for(string i : v) cout << i << " ";
}