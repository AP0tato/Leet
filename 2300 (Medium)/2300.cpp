#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int spellSize = spells.size(), potionSize = potions.size();
        vector<int> r(spellSize);
        sort(potions.begin(), potions.end());

        int i = 0, j = 0;
        while(i<spellSize)
        {
            long long a = spells[i];
            long long b = potions[j];
            while(j<potionSize&&(a*b<success))
            {
                j++;
                b = potions[j];
            }
            if((a*b>=success)) 
                r[i]=potionSize-j;
            i++;
            j = 0;
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<int> spells{38, 11};
    vector<int> potions{3, 20};
    long long success = 1065;
    vector<int> r = s.successfulPairs(spells, potions, success);

    for(int i : r) cout<<i<<' ';
}

//5 1 3
//1 2 3 4 5
//i = 1
//j = 2