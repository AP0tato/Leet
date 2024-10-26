#include <iostream>
#include <vector>

using namespace std;

//You are given an m x n binary matrix grid.

//A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

//Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

//Return the highest possible score after making any number of moves (including zero moves).

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
    }
    
    vector<vector<int>> toggle(vector<vector<int>> &grid, int x, int y)
    {
        if(grid[x][y]==0) grid[x][y]=1;
        else grid[x][y]=0;
        return grid;
    }

    vector<vector<int>> toggleRow(vector<vector<int>> &grid, int row)
    {
        for(int i = 0; i < sizeof(grid[row]); i++) toggle(grid, row, i);
        return grid;
    }

    vector<vector<int>> toggleColumn(vector<vector<int>> &grid, int column)
    {
        for(int i = 0; i < sizeof(grid); i++) toggle(grid, i, column);
        return grid;
    }
};

int main() {
    vector<vector<int>> grid{{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    Solution s;
    cout<<s.matrixScore(grid);
}