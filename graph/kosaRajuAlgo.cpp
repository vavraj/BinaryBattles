// this algorithm is used to find the total number of strongly connected components in a graph

#include<unordered_map>
#include<stack>
#include<list>
#include<vector>
using namespace std;

void dfs(int node,vector<int>adj[],vector<bool>&visited,stack<int>&st)
{
	visited[node]=true;
	for(auto neighbour:adj[node])
	{
		if(!visited[neighbour])
		{
			dfs(neighbour,adj,visited,st);
		}
	}
	st.push(node);
}

void revDfs(int node,vector<bool>&visited,vector<int>transpose[])
{
	visited[node]=true;
	for(auto neighbour:transpose[node])
	{
		if(!visited[neighbour])
		{
			revDfs(neighbour, visited, transpose);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// creating adjacency list
	vector<int>adj[v];
	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i][0];
		int v=edges[i][1];

		adj[u].push_back(v);
	}

	// storing topological order in the stack
	vector<bool>visited(v,false);
	stack<int>st;
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			dfs(i,adj,visited,st);
		}
	}
	// transposing the graph that is reversing the each directed path
	vector<int>transpose[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		for(auto neighbour:adj[i])
		{
			transpose[neighbour].push_back(i);
		}
	}
	// counting the SCC in the graph
	int count=0;
	while(!st.empty())
	{
		int topNode=st.top();
		st.pop();
		if(!visited[topNode])
		{
			count++;
			revDfs(topNode,visited,transpose);
		}
	}
	return count;
}
