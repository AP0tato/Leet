#include <vector>
#include <algorithm>

using namespace std;
class Solution 
{
    public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        int max = -1;
        vector<vector<int>> graph(n);
        for(auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            max = edge[0] > max ? edge[0] : max;
            max = edge[1] > max ? edge[1] : max;
        }
        int c = n-max-1;

        vector<int> connected = graph[0];

        return c;
    }

    int getConnected(vector<vector<int>>& graph, int i, int n)
    {
        for(int j = i+1; j < n; j++)
        {
            auto it = find(graph[j].begin(), graph[j].end(), i);
            if(it != graph[j].end())
            {
                graph[j].erase(it);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    sol.countCompleteComponents(6, edges);
    return 0;
}


