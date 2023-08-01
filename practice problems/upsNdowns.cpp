#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void print_result()
{
    int n;
    cin>>n;
    int *ar=new int[n];
    for(int i=0;i<n;i++)
    cin>>ar[i];
    
    sort(ar,ar+n);
    
    if(n>2)
    {
        if(n%2!=0)
        {
        for(int i=1;i<n;i=i+2)
        swap(ar[i],ar[i+1]);
        }
        else{
        for(int i=1;i<n-1;i=i+2)
        swap(ar[i],ar[i+1]);
        }
    }
    for(int i=0;i<n;i++)
    cout<<ar[i]<<" ";
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
    print_result();
    cout<<endl;
    }
    return 0;
}
