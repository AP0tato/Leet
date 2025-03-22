#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <time.h>

using namespace std;

void print(vector<vector<char>> &v);

class Solution 
{
    public:
    set<char> valid;

    void solveSudoku(vector<vector<char>>& board) 
    {
        vector<pair<int, int>> dots_list;

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    dots_list.push_back({i, j});
                }
            }
        }

        sort(dots_list.begin(), dots_list.end(), [&](pair<int, int> a, pair<int, int> b) {
            return countValidNumbers(board, a.first, a.second) < 
                countValidNumbers(board, b.first, b.second);
        });

        solve(board, dots_list, 0);
    }

    int countValidNumbers(vector<vector<char>>& board, int i, int j) {
        bool available[10] = {true};
        getValidNumbers(board, i, j, available);
        return count(begin(available) + 1, end(available), true);
    }

    bool solve(vector<vector<char>> &board, vector<pair<int, int>> &dots, int index)
    {
        if(index == dots.size())
            return true;

        int i = dots[index].first;
        int j = dots[index].second;
        bool available[10] = {true};
        getValidNumbers(board, i, j, available);

        for(char n = '1'; n <= '9'; ++n)
        {
            if(available[n-'0'])
            {
                board[i][j] = n;
                if(solve(board, dots, index+1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    void getValidNumbers(vector<vector<char>>& board, int i, int j, bool available[])
    {
        fill(available, available + 10, true);

        for (int k = 0; k < 9; k++) {
            if (board[i][k] != '.') available[board[i][k] - '0'] = false;
            if (board[k][j] != '.') available[board[k][j] - '0'] = false;
        }

        int row_start = (i / 3) * 3, col_start = (j / 3) * 3;
        for (int r = row_start; r < row_start + 3; r++) {
            for (int c = col_start; c < col_start + 3; c++) {
                if (board[r][c] != '.') available[board[r][c] - '0'] = false;
            }
        }
    }
};

void print(vector<vector<char>> &v)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> v;
    v = {{'.','.','.','.','.','.','.','.','.'},{'.','9','.','.','1','.','.','3','.'},{'.','.','6','.','2','.','7','.','.'},{'.','.','.','3','.','4','.','.','.'},{'2','1','.','.','.','.','.','9','8'},{'.','.','.','.','.','.','.','.','.'},{'.','.','2','5','.','6','4','.','.'},{'.','8','.','.','.','.','.','1','.'},{'.','.','.','.','.','.','.','.','.'}};
    v = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution s;

    clock_t tStart = clock();
    s.solveSudoku(v);

    print(v);
    printf("Time taken: %.2f s\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}