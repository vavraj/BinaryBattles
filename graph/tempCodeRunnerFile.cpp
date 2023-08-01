// to find the shortest path from source node to each node in a directed acyclic graph

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
    }
    void display()
    {
        for (auto i : adj)
        {
            cout << "[" << i.first << "]->";
            for (auto j : i.second)
            {
                cout << "[" << j.first << "," << j.second << "] ";
            }
            cout << endl;
        }
    }
    void dfs(int i, vector<bool> &visited, stack<int> &st)
    {
        visited[i] = true;
        for (auto neighbour : adj[i])
        {
            if (!visited[neighbour.first])
            {
                visited[neighbour.first] = true;
                dfs(neighbour.first, visited, st);
            }
        }
        st.push(i);
    }
    void shortestPath(int srcnode, vector<int> &distance, stack<int> &st)
    {
        distance[srcnode] = 0;
        while (!st.empty())
        {
            int topNode = st.top();
            st.pop();
            if (distance[topNode] != INT_MAX)
            {
                for (auto neighbour : adj[topNode])
                {
                    if (distance[topNode] + neighbour.second < distance[neighbour.first])
                    {
                        distance[neighbour.first] = distance[topNode] + neighbour.second;
                    }
                }
            }
        }
    }
};

int main()
{
    graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.display();
    int n = 6;
    vector<bool> visited(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, st);
        }
    }

    vector<int> distance(n, INT_MAX);
    int srcNode = 1;
    g.shortestPath(srcNode, distance, st);

    for (auto i : distance)
    {
        // if(i==INT_MAX)
        // {
        //     cout<<"~~ ";
        // }
        // else
            cout << i << " ";
    }

    return 0;
}