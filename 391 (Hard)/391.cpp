#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int size = rectangles.size();

        for(int i = 0; i < size; i++)
        {
            
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v{{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4}}; 
    cout << s.isRectangleCover(v);
}