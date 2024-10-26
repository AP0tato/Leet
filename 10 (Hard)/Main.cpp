#include <string>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        deque<string> parsed {string(1, p[0])};
        string str = s;
        int index = 0;
        for(int i = 1; i < p.size(); i++)
        {
            if(p[i]!='*'&&p[i]!='.')
                parsed[index] = parsed[index]+string(1, p[i]);
            else
            {
                parsed.push_back(string(1, p[i]));
                parsed.push_back("");
                index += 2;
            }
        }

        if(parsed[parsed.size()-1]=="")
            parsed.pop_back();
        
        for(int i = 0; i < str.size(); i++)
        {
            if(parsed.size()==0)
                break;
            string substr = parsed[0];
            parsed.pop_front();
            if(parsed.size()==0)
                return substr==s;
            string modifier = parsed[0];
            parsed.pop_front();

            if(modifier=="*") 
            {
                if(substr!=".") 
                {
                    int first_found = str.find(substr);
                }
            }
            else
            {
                if(substr==".") 
                {
                    substr = str[i];
                }
                return str.find(substr, i)!=-1;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    /*
    aa a -> y
    aa a* -> y
    ab .* -> y
    aab c*a*b -> y
    */
    bool e = s.isMatch("aab", "c*a*b");
    cout<<e;
}
