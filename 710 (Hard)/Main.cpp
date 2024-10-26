#include <vector>
#include <iostream>

using namespace std;

class Solution {
    vector<int> valid;
public:
    Solution(int n, vector<int>& blacklist) {
        for(int i = 0; i < n; i++)
        {
            auto it = find(blacklist.begin(), blacklist.end(), i);
            if(it==blacklist.end())
                valid.push_back(i);
        }
    }
    
    int pick() {
        srand(time(NULL));
        int index = rand()%valid.size();
        return valid[index];
    }
};

void main()
{
    int n = 7;
    vector<int> blacklist = {2, 3, 5};
    Solution* obj = new Solution(n, blacklist);
    int param_1 = obj->pick();
    cout<<param_1;
}