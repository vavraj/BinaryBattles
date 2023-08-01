// to find the total number of articulation point in a graph

/* 
an articulation point is a point in a graph such that on removing that point from the graph 
the graph divides into two or more components.
*/

#include<iostream>
using namespace std;


class Solution {
    int timer=1;
    void dfs(int node,int parent, vector<int>adj[],vector<int>&discovery,vector<int>&low,
    vector<bool>&visited,vector<int> &A_Points)
    {
        visited[node]=true;
        low[node]=discovery[node]=timer;
        timer++;
        int child=0;
        for(auto neighbour: adj[node])
        {
            
            if(neighbour==parent)
            {
                // if child is parent then ignore
                continue;
            }
            if(!visited[neighbour])
            {
                dfs(neighbour,node,adj,discovery,low,visited,A_Points);
                
                // update the low after returning from the recursive call
                low[node]=min(low[neighbour],low[node]);

                // check whether its an AP
                if(low[neighbour]>=discovery[node] && parent!=-1)
                {
                    A_Points[node]=1;
                }
                child++;
            }
            else{
                //visited but not parent i.e. backedge condition
                low[node]=min(low[node],low[neighbour]);
            }
        }
        // use to handle special case
        if(parent==-1 && child>1)
        {
            A_Points[node]=1;
        }

    }
public:
    vector<int> criticalConnections(int n, vector<pair<int,int> >& connections) {
        vector<int>adj[n];
        for(auto it:connections)
        {
            int u=it.first;
            int v=it.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>discovery(n,-1);
        vector<int>low(n,-1);
        vector<bool>visited(n,false);
        vector<int >A_Points(n,0);
        dfs(0,-1,adj,discovery,low,visited,A_Points);

        return A_Points;
    }
};

int main()
{
    vector<pair<int,int> >connection;
    connection.push_back(make_pair(0,1));
    connection.push_back(make_pair(0,3));
    connection.push_back(make_pair(0,4));
    connection.push_back(make_pair(3,4));
    connection.push_back(make_pair(1,2));
    
    Solution graph;
    
    vector<int>ans=graph.criticalConnections(5,connection);
   
   
   for(int i=0;i<5;i++)
    {
        if(ans[i]!=0)
        {
            cout<<i<<" ";
        }

    }

    

    return 0;
}