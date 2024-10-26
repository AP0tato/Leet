#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<char> letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int getLucky(string s, int k) {
        int sum;
        string sSum = "";
        for(int i = 0; i < s.size(); i++)
            sSum+=to_string(find(letters, s[i])+1);

        while((k--)>0)
        {
            sum = 0;
            for(char i : sSum)
                sum=sum+i-48;
            sSum = to_string(sum);
        }

        return sum;
    }

    int find(vector<char> v, char c)
    {
        for(int i = 0; i < v.size(); i++)
            if(v[i]==c) return i;
        return -1;
    }
};

int main() {
    Solution s;
    string st = "zbax";
    cout << s.getLucky(st, 2);
}