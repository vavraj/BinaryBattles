#include<unordered_map>
#include<stack>
#include<set>
#include<vector>

using namespace std;

void topsort(int node,unordered_map<int,bool>&visited,stack<int>&stk,unordered_map<int,set<int> >&adj)
{
	visited[node]=1;
	for(auto neighbour:adj[node])
	{
		if(!visited[neighbour])
		{
			topsort(neighbour, visited, stk, adj);
		}
	}
	stk.push(node);
	// last in first out(LIFO)
}
vector<int> topologicalSort(vector<pair<int,int>>& edges, int N, int M)
{
	unordered_map<int ,set<int> >adj;
	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i].first;
		int v=edges[i].second;

		adj[u].insert(v);
	}
	unordered_map<int,bool>visited;
	stack<int>stk;
	for(int i=1;i<=N;i++)
	{
		if(!visited[i])
		{
			topsort(i,visited,stk,adj);
		}
	}
	
	vector<int>ans;
	while(!stk.empty())
	{
		ans.push_back(stk.top());
		stk.pop();
	}
	return ans;
}  
