#include <unordered_map>
#include <vector>
#include <list>
#include <string>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
	// creating adjacent list
	unordered_map<int ,list<int> >adj;
	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i][0];
		int v=edges[i][1];

		adj[u].push_back(v);
	}
	// storing indegree
	vector<int>indegree(v);
	for(auto i:adj)
	{
		for(auto j:i.second)
		{
			indegree[j]++;
		}
	}
	queue<int>q;
	// storing node with zero indegree in queue
	for(int i=0;i<v;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	vector<int>ans;
	while(!q.empty())
	{
		int frontnode=q.front();
		q.pop();
		ans.push_back(frontnode);
		for(auto neighbour:adj[frontnode])
		{
			indegree[neighbour]--;
			if(indegree[neighbour]==0)
			{
				q.push(neighbour);
			}
		}
	}
return ans;
}  

