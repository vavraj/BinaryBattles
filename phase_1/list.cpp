#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> li;
    li.push_back(2);
    li.push_front(1);
    li.push_front(10);
    li.push_front(12);
    for(int i:li)
    {
        cout<<i<<" ";
    }
    cout<<"\nEmpty or not: "<<li.empty()<<endl;
    li.erase(li.begin());
    for(int i:li)
    {
        cout<<i<<" ";
    }
    // direct access of element is not possible !
    cout<<endl;
    return 0;
}