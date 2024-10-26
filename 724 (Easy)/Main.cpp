#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lSum = 0;
        int rSum = 0;
        int tSum = 0;

        for(int i : nums)
            tSum += i;

        rSum = tSum - nums[0];

        for(int i = 0; i < nums.size();i++)
        {
            if(rSum==lSum)
                return i;
            lSum += nums[i];
            if(i+1<nums.size())
                rSum = tSum - lSum - nums[i+1];
            else
                break;
        }

        return -1;
    }
};

int main()
{
    Solution *s;
    vector<int> nums = {2, 5};
    cout<<s->pivotIndex(nums);
}