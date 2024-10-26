#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // sum(beans) - (N - i) * beans[i]
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long ans = LLONG_MAX, N = beans.size(), sum = 0;

        for(long long i : beans)
            sum += i;

        for(int i = 0; i < N; i++)
            ans = min(ans, sum - beans[i]*(N-i));

        return ans;
    }
};

int main()
{
    Solution *s;
    vector<int> v = {66,90,47,25,92,90,76,85,22,3};
    cout<<s->minimumRemoval(v);
}