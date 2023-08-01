/*
    to find shortest path to each node from a source node 
    using djiktras algorithm in an undirected graph
*/

#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int> > > adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
 
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;
    set<pair<int, int>> st;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        pair<int, int> top = *st.begin();
        // fetch top record
        int nodeDitance = top.first;
        int topNode = top.second;
        // remove top record
        st.erase(st.begin());

        for (auto neighbour : adj[topNode])
        {
            if (nodeDitance + neighbour.second < distance[neighbour.first])
            {
                auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));
                // if record found then erase it
                if (record != st.end())
                {
                    st.erase(record);
                }
                distance[neighbour.first] = nodeDitance + neighbour.second;
                st.insert(make_pair(distance[neighbour.first], neighbour.first));
            }
        }
    }
    return distance;
}
