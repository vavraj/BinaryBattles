#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
unordered_map<int,vector<pair<int,int> > >adj;
for(int i=0;i<m;i++)
{
    int u=g[i].first.first;
    int v=g[i].first.second;
    int w=g[i].second;

    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

vector<int>key(n+1,INT_MAX);
vector<bool>mst(n+1,false);
vector<int>parent(n+1,-1);

key[1]=0;
parent[1]=-1;

for(int i=1;i<n;i++)
{
    int mini=INT_MAX;
    int u;
    // finding the node with minimum weight and is not present in mst
    for(int v=1;v<=n;v++)
    {
        if(mst[v]==false && key[v]<mini)
        {
            mini=key[v];
            u=v;
        }
    }
    // adding the node in the mst
    mst[u]=true;

    // check its adjacent nodes
    for(auto neighbour:adj[u])
    {
        int v=neighbour.first;
        int w=neighbour.second;

        if(mst[v]==false && w<key[v])
        {
            key[v]=w;
            parent[v]=u;
        }
    }
}

vector<pair<pair<int, int>, int>>result;
for(int i=2;i<=n;i++)
{
    result.push_back({{parent[i],i},key[i]});
}
return result;

}
