#include<iostream>
using namespace std;


class Solution {
    int timer=1;
    void dfs(int node,int parent, vector<int>adj[],vector<int>&discovery,vector<int>&low,
    vector<bool>&visited,vector<vector<int> >&bridges)
    {
        visited[node]=true;
        low[node]=discovery[node]=timer;
        timer++;

        for(auto neighbour: adj[node])
        {
            if(neighbour==parent)
            {
                // if child is parent then ignore
                continue;
            }
            if(!visited[neighbour])
            {
                dfs(neighbour,node,adj,discovery,low,visited,bridges);
                
                // update the low after returning from the recursive call
                low[node]=min(low[neighbour],low[node]);

                // check whether its a bridge
                if(low[neighbour]>discovery[node])
                {
                    bridges.push_back({node,neighbour});
                }
            }
            else{
                //visited but not parent i.e. backedge condition
                low[node]=min(low[node],low[neighbour]);
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>discovery(n,-1);
        vector<int>low(n,-1);
        vector<bool>visited(n,false);
        vector<vector<int> >bridges;
        dfs(1,-1,adj,discovery,low,visited,bridges);
        return bridges;
    }
};