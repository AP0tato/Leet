#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i = 1; i < arr.size(); i++)
            arr[i] ^= arr[i-1];
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) 
        {
            int a = queries[i][0];
            int b = queries[i][1];

            if(a==0) ans.push_back(arr[b]);
            else ans.push_back(arr[b]^arr[a-1]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v{1,3,4,8};
    vector<vector<int>> q{{0,1},{1,2},{0,3},{3,3}};
    vector<int> a = s.xorQueries(v, q);
    for(int i : a) cout<<i<<" ";
}

// 1 2 6 14

// 2 7 14 8