#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int right = obstacleGrid[0].size(), down = obstacleGrid.size();
        int ans = paths(right,down), rem = 1;
        vector<vector<int>> ones;
        vector<int> prev{0,0};

        for(int i = 0; i < obstacleGrid.size(); i++)
        {
            for(int j = 0; j < obstacleGrid[i].size(); j++)
            {
                int tmp = obstacleGrid[i][j];
                if(tmp==1) ones.push_back({i,j});
            }
        }

        if(ones.size()==0) return ans;

        for(vector<int> i : ones)
        {
            cout << i[0] << " " << i[1]<<endl;
            rem *= paths(i[0]-prev[0]+1,i[1]-prev[1]+1);
            prev=i;
        }

        rem*=paths(right-prev[0],down-prev[1]);

        ans-=rem;

        return ans;
    }

    int paths(int x, int y) {return ( fact(x+y-2) )/( fact(x-1)*fact(y-1) );}

    int fact(int x) {
        int ret = x;
        while((--x)>0)
        {
            ret *= x;
        }
        return ret;
    }
};

// Old Approach (Works but slow)
/*
for(int i = 0; i < obstacleGrid[0].size(); i++)
        {
            if(obstacleGrid[0][i]!=1) 
                obstacleGrid[0][i]=1;
            else 
            {
                obstacleGrid[0][i]=0;
                while((i++)<obstacleGrid[0].size())
                    obstacleGrid[0][i]=0;
                break;
            }
        }

        for(int i = 1; i < obstacleGrid.size(); i++)
        {
            if(obstacleGrid[i][0]!=1) 
                obstacleGrid[i][0]=1;
            else
            {
                obstacleGrid[i][0]=0;
                while((i++)<obstacleGrid.size()-1)
                    obstacleGrid[i][0]=0;
                break;
            }
        }

        for(int i = 1; i < obstacleGrid.size(); i++)
        {
            for(int j = 1; j < obstacleGrid[i].size(); j++)
            {
                if(obstacleGrid[i][j]!=1)
                    obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                else
                    obstacleGrid[i][j]=0;
            }
        }

        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[obstacleGrid.size()-1].size()-1];

        // Main

        for(vector<int> i : v)
        {
            for(int j : i)
            {
                cout<<j<<" ";
            }
            cout<<"\n";
        }
*/

int main() {
    Solution s;
    vector<vector<int>> v{{0,1},{0,0}};
    cout<<s.uniquePathsWithObstacles(v);
}