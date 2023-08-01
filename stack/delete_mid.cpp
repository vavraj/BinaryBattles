#include <iostream>
#include <stack>
using namespace std;

void delete_mid(stack<int> &s)
{
    int size = s.size();
    int mid = size / 2 ;

    stack<int>temp;
    int i=size;
    while(i!=mid)
    {
        temp.push(s.top());
        s.pop();
        i--;
    }
    s.pop();
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

void using_recursion(stack<int> &s,int count,int size)
{
    // base case
    if(count==size/2)
    {
        s.pop();
        return ;
    }

    int temp=s.top();
    s.pop();
    using_recursion(s,count+1,size);
    s.push(temp);

}

void print(stack<int>s)
{
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);

    print(s);
    // delete_mid(s);

    int count=0; 
    using_recursion(s,count,s.size());
    print(s);

    return 0;
}