#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    maxi.push(1);
    maxi.push(3);
    maxi.push(5);
    maxi.push(10);
    int n=maxi.size();
    for(int i=0;i<n;i++)
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;
    mini.push(1);
    mini.push(3);
    mini.push(5);
    mini.push(10);
    int m=mini.size();
    for(int i=0;i<m;i++)
    {
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;
    return 0;
}