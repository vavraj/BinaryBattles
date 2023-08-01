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
    insertAtBottom(s,6);   
    print(s);
    return 0;
}