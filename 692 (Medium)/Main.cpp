#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        vector<string> temp;
        vector<string> ans;
        for(string i : words)
            m[i] += 1;
        temp = sort(m);

        reverse(temp.begin(), temp.end());

        for(int i = 0; i < k; i++)
            ans.push_back(temp[i]);
        return ans;
    }

    vector<string> sort(map<string, int> m)
    {
        vector<pair<string, int>> pairs;
        for(auto &it : m)
            pairs.push_back(it);

        ::sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) { 
            return a.second==b.second?a.first>b.first:a.second<b.second;
        });

        vector<string> sorted;

        for(auto &it : pairs)
            sorted.push_back(it.first);
        
        return sorted;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    int k = 4;
    vector<string> temp = s->topKFrequent(words, k);
    for(auto i : temp)
        cout << i << " ";
    cout << endl;

    words = {"i","love"};
    k = 2;
    temp = s->topKFrequent(words, k);
    for(auto i : temp)
        cout << i << " ";
}