#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution 
{
    public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<string> s;
        for(vector<char> i : board)
        {
            string t(i.begin(), i.end());
            string::difference_type n1 = count(t.begin(), t.end(), '1');
            string::difference_type n2 = count(t.begin(), t.end(), '2');
            string::difference_type n3 = count(t.begin(), t.end(), '3');
            string::difference_type n4 = count(t.begin(), t.end(), '4');
            string::difference_type n5 = count(t.begin(), t.end(), '5');
            string::difference_type n6 = count(t.begin(), t.end(), '6');
            string::difference_type n7 = count(t.begin(), t.end(), '7');
            string::difference_type n8 = count(t.begin(), t.end(), '8');
            string::difference_type n9 = count(t.begin(), t.end(), '9');

            int c1 = static_cast<int>(n1);
            int c2 = static_cast<int>(n2);
            int c3 = static_cast<int>(n3);
            int c4 = static_cast<int>(n4);
            int c5 = static_cast<int>(n5);
            int c6 = static_cast<int>(n6);
            int c7 = static_cast<int>(n7);
            int c8 = static_cast<int>(n8);
            int c9 = static_cast<int>(n9);

            if(c1>1||c2>1||c3>1||c4>1||c5>1||c6>1||c7>1||c8>1||c9>1)
                return false;

            s.push_back(t);
        }

        for(int i = 0; i < 9; i++)
        {
            string t; 
            t.push_back(s[0][i]);
            t.push_back(s[1][i]);
            t.push_back(s[2][i]);
            t.push_back(s[3][i]);
            t.push_back(s[4][i]);
            t.push_back(s[5][i]);
            t.push_back(s[6][i]);
            t.push_back(s[7][i]);
            t.push_back(s[8][i]);

            string::difference_type n1 = count(t.begin(), t.end(), '1');
            string::difference_type n2 = count(t.begin(), t.end(), '2');
            string::difference_type n3 = count(t.begin(), t.end(), '3');
            string::difference_type n4 = count(t.begin(), t.end(), '4');
            string::difference_type n5 = count(t.begin(), t.end(), '5');
            string::difference_type n6 = count(t.begin(), t.end(), '6');
            string::difference_type n7 = count(t.begin(), t.end(), '7');
            string::difference_type n8 = count(t.begin(), t.end(), '8');
            string::difference_type n9 = count(t.begin(), t.end(), '9');

            int c1 = static_cast<int>(n1);
            int c2 = static_cast<int>(n2);
            int c3 = static_cast<int>(n3);
            int c4 = static_cast<int>(n4);
            int c5 = static_cast<int>(n5);
            int c6 = static_cast<int>(n6);
            int c7 = static_cast<int>(n7);
            int c8 = static_cast<int>(n8);
            int c9 = static_cast<int>(n9);

            if(c1>1||c2>1||c3>1||c4>1||c5>1||c6>1||c7>1||c8>1||c9>1)
                return false;
        }

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                string t;
                for(int k = 0; k < 3; k++)
                {
                    t.push_back(s[i*3][j*3+k]);
                    t.push_back(s[i*3+1][j*3+k]);
                    t.push_back(s[i*3+2][j*3+k]);
                }
                string::difference_type n1 = count(t.begin(), t.end(), '1');
                string::difference_type n2 = count(t.begin(), t.end(), '2');
                string::difference_type n3 = count(t.begin(), t.end(), '3');
                string::difference_type n4 = count(t.begin(), t.end(), '4');
                string::difference_type n5 = count(t.begin(), t.end(), '5');
                string::difference_type n6 = count(t.begin(), t.end(), '6');
                string::difference_type n7 = count(t.begin(), t.end(), '7');
                string::difference_type n8 = count(t.begin(), t.end(), '8');
                string::difference_type n9 = count(t.begin(), t.end(), '9');

                int c1 = static_cast<int>(n1);
                int c2 = static_cast<int>(n2);
                int c3 = static_cast<int>(n3);
                int c4 = static_cast<int>(n4);
                int c5 = static_cast<int>(n5);
                int c6 = static_cast<int>(n6);
                int c7 = static_cast<int>(n7);
                int c8 = static_cast<int>(n8);
                int c9 = static_cast<int>(n9);

                if(c1>1||c2>1||c3>1||c4>1||c5>1||c6>1||c7>1||c8>1||c9>1)
                    return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> v{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution s;

    return 0;
}
