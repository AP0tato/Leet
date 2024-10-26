#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int i=n-1;
        unordered_map<char,int>m;
        m['I']=1,m['V']=5,m['X']=10,m['L']=50,m['C']=100,m['D']=500,m['M']=1000;
        int ans=0;char last=' ';
        while(i>=0){
            if(m.count(last) && m[last]>m[s[i]]){
                ans-=m[s[i]];
                last=s[i];
            }
            else{
            ans+=m[s[i]];
                last=s[i];
            }
            
            i--;
        }
        return ans;
    }
};

int main() {
    string a = "IV";
    Solution s;
    cout<<s.romanToInt(a);
}