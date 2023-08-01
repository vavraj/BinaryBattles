#include <iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<stack>

using namespace std;

void dfs(unordered_map<int, set<int> > adjset, vector<int> &component, unordered_map<int, bool> &visited, int node)
{
    stack<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int temp = q.top();
        component.push_back(temp);
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
//using recursion
void dfs(int node, unordered_map<int, bool> &visited,unordered_map<int, set<int>> &adj, vector<int> &component) 
{
    component.push_back(node);
    visited[node] = true;
    // hr connected node k live recursive call
    for(auto i : adj[node]) 
    {
        if(!visited[i]) 
        {
             dfs(i, visited, adj, component);
        }
    }
}

void createAdjset(int u, int v, unordered_map<int, set<int> > &adjset)
{
    adjset[u].insert(v);
    adjset[v].insert(u);
}
vector<vector<int> > depthFirstSearch(int V, int E, vector<vector<int> > &edges)
{
    // Write your code here
     // Write your code here
    unordered_map<int, set<int> > adjset;
    vector<vector<int> > ans;
    unordered_map<int, bool> visited;

    // creating adjacent list 
    for (int i = 0; i < E; i++)
    {
        createAdjset(edges[i][0], edges[i][1], adjset);
    }

    // traversing each of the node so that disconnected node can also be covered
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int>component;
            dfs(adjset, component, visited, i);
            ans.push_back(component);
        }
    }
    return ans;
}