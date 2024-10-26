#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged = nums1;
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        if(merged.size()==0)
            return 0;
        sort(merged.begin(), merged.end());
        if(merged.size()%2==0)
        {
            return (double)(merged[(merged.size()/2)-1]+merged[merged.size()/2])/2;
        }
        else
        {
            return (double)merged[merged.size()/2];
        }
    }
};