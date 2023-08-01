#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> InterleaveBothHalfs(queue<int>&q)
{
    stack<int>s;
    int n=q.size()/2;
    int m=q.size()-n;
    int count=m;
    while(n--)
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    while(m--)
    {
        q.push(q.front());
        q.pop();
    }
    n=q.size()/2;
    while(n--)
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        q.push(q.front());
        s.pop();
        q.pop();
        count--;
    }
    if(count>0)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}

void print(queue<int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main()
{
    queue<int>q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    print(q);
    InterleaveBothHalfs(q);
    print(q);
    return 0;
}