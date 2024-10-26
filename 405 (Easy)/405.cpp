#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        vector<char> hex = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string answer;
        unsigned int bin;
        if (num == 0) return "0";
        if (num < 0) bin = ~(-num) + 1;
        else bin = num;
        while (bin != 0){
            answer = hex[bin % 16] + answer;
            bin /= 16;
        }
        return answer;
    }
};

int main() 
{
    Solution s;
    int num = -2147483648;
    cout<<s.toHex(num);
}

//  0  = 00000000000000000000000000000000 = 0
//  26 = 00000000000000000000000000011010 = 1A
//  7  = 00000000000000000000000000000111 = 7
//  -1 = 11111111111111111111111111111111 = FFFFFFFF
//  20 = 00000000000000000000000000010100 = 14
//  93 = 00000000000000000000000001011101 = 005D
// -93 = 11111111111111111111111110100011 = FFA3