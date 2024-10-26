#include <iostream>
#include <vector>

//Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
    }
};

int main() {
    vector<vector<int>> matrix{{9,9,4},{6,6,8},{2,1,1}};
    Solution s;
    cout<<s.longestIncreasingPath(matrix);
}