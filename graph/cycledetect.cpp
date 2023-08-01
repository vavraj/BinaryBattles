#include <unordered_map>
#include <vector>
#include <list>
#include <string>
#include <queue>
using namespace std;

//using  BFS
bool detectCycle(int sourceNode, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    queue<int> q;
    unordered_map<int, int> parent;
    parent[sourceNode] = -1;
    visited[sourceNode] = 1;
    q.push(sourceNode);
    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();
        for (auto neighbour : adj[currNode])
        {
            if (visited[neighbour] == 1 && parent[currNode] != neighbour)
                // if neighbour is visited it means it must be parent of curr node
                return true;
            else if (!visited[neighbour])
            {
                visited[neighbour] = 1;
                q.push(neighbour);
                parent[neighbour] = currNode;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (detectCycle(i, visited, adj))
            {
                return "Yes";
            }
        }
    }
    return "No";
}




// using dfs

bool isCyclicDfs(int sourceNode, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[sourceNode] = 1;
    for (auto neighbour : adj[sourceNode])
    {
        // only one condition will get checked
        if (!visited[neighbour])
        {
            bool cycleDetect = isCyclicDfs(neighbour, sourceNode, visited, adj);
            if (cycleDetect)
                return true;
        }
        else if (parent != neighbour)
        {
            return true;
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCyclicDfs(i, -1, visited, adj))
            {
                return "Yes";
            }
        }
    }
    return "No";
}


