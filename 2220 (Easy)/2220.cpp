#include <iostream>
#include <bitset>

using namespace std;

//A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int c = 0, r = start^goal;
        while(r!=0)
        {
            cout<<bitset<4>(r)<<endl;
            r&=(r-1);
            c++;
        }
        return c;
    }
};

int main() 
{
    int a = 10, b = 7;
    Solution s;
    cout << s.minBitFlips(a, b);
}

//10 = 1010
//7 = 111

//&= 10
//|= 1111

//~=
//1010 ~= 101
//111 ~= 000

//^= 1101