#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(2);
    dq.push_front(1);
    dq.push_front(10);
    dq.push_front(12);
    for(int i:dq)
    {
        cout<<i<<" ";
    }
    cout<<"\nEmpty or not: "<<dq.empty()<<endl;
    dq.erase(dq.begin(),dq.begin()+1);
    for(int i:dq)
    {
        cout<<i<<" ";
    }

    cout<<endl;
    return 0;
}