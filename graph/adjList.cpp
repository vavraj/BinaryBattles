#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
template<typename T>
class graph{
    public:
    unordered_map<T,list<T> >adj;
    void addedge(T u,T v,bool direction)
    {
        // direction=0->unoredered list
        // direction=1->ordered list

        // create an edge between two nodes
        if(direction==0)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

    }
    void printGraph()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"-> ";
            for(auto j:i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph<char> g;
    int n,m;
    cout<<"enter number of nodes and edges ";
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        char u,v;
        cin>>u>>v;
        g.addedge(u,v,0);
    }
    g.printGraph();
    return 0;
}