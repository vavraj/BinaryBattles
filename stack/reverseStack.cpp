#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&s,int data)
{
    // base condition
    if(s.empty()==1)
    {
        s.push(data);
        return ;
    }

    int top=s.top();
    s.pop();
    insertAtBottom(s,data);
    s.push(top);

}

void reverseStack(stack<int>&s)
{
    // base condition
    if(s.empty()==1)
    {
        return ;
    }

    int top=s.top();
    s.pop();
    reverseStack(s);
    
    insertAtBottom(s,top);

}

void print(stack<int>s)
{
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int>s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    print(s);
    reverseStack(s);   
    print(s);
    return 0;
}