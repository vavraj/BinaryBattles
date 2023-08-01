#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];//returns true if the condition satisfies
}


void makeset(vector<int> &rank, vector<int> &parent, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
    {
        return node;
    }
    // path compression
    return parent[node] = findParent(parent[node], parent);
}

void makeUnion(int u, int v, vector<int> &rank, vector<int> &parent)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        // rank is only increased if both the ranks are same
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    //   sorting edges according to their weight
    sort(edges.begin(), edges.end(), cmp);

    vector<int> rank(n);
    vector<int> parent(n);

    // intializing rank and parent
    makeset(rank, parent, n);

    int minWeight = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        u = findParent(u, parent);
        v = findParent(v, parent);
        if (u != v)
        {
            minWeight += w;
            makeUnion(u, v, rank, parent);//merging two nodes according to their rank
        }
    }
    return minWeight;
}