#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        const char *plate = licensePlate.c_str();
        for(int i = 0; i < sizeof(words); i++)
        {
            
        }
        return "";
    }
};

int main(int argv, char **argc)
{
    string plate = "1s3 PSt";
    vector<string> words{"step","steps","stripe","stepple"};
    Solution *s;
    cout<<s->shortestCompletingWord(plate, words);
}