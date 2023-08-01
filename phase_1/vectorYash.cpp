#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    int n;
    cin>>n;
    // int ar[n];

    int*ar;
    ar=new int[n];
    cout<<ar;
    return 0;
}