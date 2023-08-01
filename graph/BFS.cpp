#include <iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<queue>

using namespace std;

void createAdjset(int u, int v, unordered_map<int, set<int>> &adjset)
{
    adjset[u].insert(v);
    adjset[v].insert(u);
}
void bfs(unordered_map<int, set<int>> adjset, vector<int> &ans, unordered_map<int, bool> &visited, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        ans.push_back(temp);
        q.pop();
        for (auto j : adjset[temp])
        {
            if (!visited[j])
            {//checking if the node is visited
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int, set<int>> adjset;
    vector<int> ans;
    unordered_map<int, bool> visited;

    // creating adjacent list 
    for (int i = 0; i < edges.size(); i++)
    {
        createAdjset(edges[i].first, edges[i].second, adjset);
    }

    // traversing each of the node so that disconnected node can also be covered
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjset, ans, visited, i);
        }
    }
    return ans;
} 