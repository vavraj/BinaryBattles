#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int>&q)// TC= O(N)   SC=O(N)
{
    stack<int>temp;
    while(!q.empty())
    {
        temp.push(q.front());
        q.pop();
    }
    while(!temp.empty())
    {
        q.push(temp.top());
        temp.pop();
    }
}

// using recursion
void recReverse(queue<int>&q)//TC=O(N)   SC=O(1)
{
    // base condition
    if(q.empty())
    {
        return;
    }
    int front=q.front();
    q.pop();
    recReverse(q);
    q.push(front);
}

int main()
{
    queue<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.front()<<" "<<s.back()<<endl;
    recReverse(s);
    cout<<s.front()<<" "<<s.back()<<endl;
    return 0;
}