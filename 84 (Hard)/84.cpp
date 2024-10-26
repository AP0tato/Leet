#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int smallest=10001, greatest=0;
        int final = 0;
        //int prev=heights[0];
        for(int i = 0; i < heights.size()-1; i++)
        {
            if(heights[i]<smallest) 
                smallest=heights[i];
            else if(heights[i]>greatest)
            {
                greatest=heights[i];
                int least, t;

                if(heights[i-1]<heights[i+1])
                {
                    least=heights[i-1];
                    t=heights[i+1];
                } 
                else
                {
                    least=heights[i+1];
                    t=heights[i-1];
                }

                int tmp = (greatest-least)+(t-least)+least;
                if(tmp>final)
                    final=tmp;
            }
        }
        return final;
    }
};

int main() {
    Solution s;
    vector<int> v{4, 2};
    cout << s.largestRectangleArea(v);
}