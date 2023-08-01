// finding shortest path in a undirected acyclic graph from given sourcenode and destination node

#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
#include<stack>

using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int,list<int> >adj;
	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i].first;
		int v=edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int>q;
	vector<int>visited(n+1);
	vector<int>parent(n+1);
	q.push(s);
	visited[s]=1;
	parent[s]=-1;
	while(!q.empty())
	{
		int frontnode=q.front();
		q.pop();
		for(auto neighbour:adj[frontnode])
		{
			if(!visited[neighbour])
			{
				parent[neighbour]=frontnode;
				q.push(neighbour);
				visited[neighbour]=1;
			}
		}
	}
	vector<int>ans;
	int i=t;
	while(i!=-1)
	{
		ans.push_back(i);
		i=parent[i];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
