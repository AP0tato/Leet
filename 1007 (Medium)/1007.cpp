#include <iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotationsT = 0, prevT = tops[0], rotationsB = 0, prevB = bottoms[0];
        if(tops==bottoms) return 0;
        for(int i = 0; i < sizeof(tops)/sizeof(int32_t); i++)
        {
            if(tops[i]!=prevT) 
            {
                rotationsT--;
                if(bottoms[i]==prevT)
                {
                    rotationsT+=2;
                    prevT=bottoms[i];
                } else prevT=tops[i];
            }
            if(bottoms[i]!=prevB) 
            {
                rotationsB--;
                if(tops[i]==prevB)
                {
                    rotationsB+=2;
                    prevB=tops[i];
                } else prevB=bottoms[i];
            }
        }
        cout<<rotationsB<<' '<<rotationsT<<endl;
        return -1;
    }
};

//Previous Approach
/*
int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotations = 0, prev = tops[0];
        if(tops==bottoms) return 0;
        for(int i = 0; i < sizeof(tops)/sizeof(int); i++)
        {
            if(tops[i]!=prev&&bottoms[i]==prev)
            {
                rotations++;
                prev = bottoms[i];
            } else prev=tops[i];
            cout<<i<<": "<<rotations<<endl;
        }
        return rotations==0?-1:rotations;
    }
*/

int main() {
    vector<int> top = {3,5,1,2,3}, bottom = {3,6,3,3,4};
    Solution s;
    cout<<s.minDominoRotations(top, bottom);
}