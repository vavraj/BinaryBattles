#include<queue>
#include <vector>
using namespace std;
class node{
    public:
    int data;
    int i;
    int j;
    node(int data,int row ,int col)
    {
        this->data=data;
        i=row;
        j=col;
    }
};
class compare{
    public:
    bool operator()(node*a,node*b)
    {
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int>ans;
    priority_queue<node*,vector<node*>,compare> pq;
    // step1: insert first element of each array in the minheap
    for(int i=0;i<k;i++)//  TC=O(K*log(K)  
    {
        node*temp=new node(kArrays[i][0],i,0);
        pq.push(temp);
    }
    // step2 insert minimum elem̦ent in the ans and add the next element of same array into the heap
    while(pq.size()>0)// TC = O(N*k)  Total TC=)((n*k)*log(K)) Total SC = O(N*K)
    {
        node*top=pq.top();
        ans.push_back(top->data);
        pq.pop();
        int i=top->i;
        int j=top->j;
        if(j+1<kArrays[i].size())
        {
            node*temp=new node(kArrays[i][j+1],i,j+1);
            pq.push(temp);
        }
    }
    return ans;
}
