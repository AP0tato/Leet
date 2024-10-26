#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        return changed;    
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 3, 4, 2, 6, 8};
    v = s.findOriginalArray(v);

    for(int i : v) cout << i << " ";
}