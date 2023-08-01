#include <list>
#include <unordered_map>
#include <vector>
#include<queue>

using namespace std;

// using dfs
bool solve(int node, unordered_map<int, bool> &visited,unordered_map<int, list<int>> &adj,
           unordered_map<int, bool> &dfscall)
{
    visited[node] = 1;
    dfscall[node] = 1;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (solve(neighbour, visited, adj, dfscall))
            {
                return true;
            }
        }
        else if (dfscall[neighbour] == 1)
        {
            return true;
        }
    }
    dfscall[node] = 0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfscall;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool detectCycle = solve(i, visited, adj, dfscall);
            if (detectCycle)
                return 1;
        }
    }
    return 0;
}




// cycle detection of directed graph using bfs (with the help of topological sort)

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
vector<int>adj[n + 1];
vector<int>indegree(n+1);

// create adjacency list
for(int i=0;i<edges.size();i++)
{
  int u=edges[i].first;
  int v=edges[i].second;
  adj[u].push_back(v);  
  // simultaneously stores the indegree of the node
  indegree[edges[i].second]++;
}


// storing nodes with zero indegree
queue<int>q;
for(int i=1;i<=n;i++)
{
  if(indegree[i]==0)
  {
    q.push(i);
  }
}

int cnt=0;
while(!q.empty())
{
  int front=q.front();
  q.pop();
  cnt++;
  for(auto neighbour:adj[front])
  { 
    indegree[neighbour]--;
    if(indegree[neighbour]==0)
    {
      q.push(neighbour);
    }
  }
}

if(cnt==n)
{
  return 0;
}
else
  return 1;
}