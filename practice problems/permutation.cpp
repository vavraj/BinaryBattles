#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int permutation()
{
    int N;
    cin>>N;
    int *ar=new int[N];
    for(int i=0;i<N;i++)
    cin>>ar[i];
    sort(ar,ar+N);
    for(int i=0;i<N;i++)
    cout<<ar[i]<<" ";
    int count=0;
    for(int i=0;i<N;i++)
    {
        if(ar[i]<i+1)
        {
            int temp=(i+1)-ar[i];
            ar[i]=temp+ar[i];
            count=count+temp;
        }
        else if(ar[i]==i+1){
        continue;
        }
        else
        return -1;
    }
    return count;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    cout<<permutation()<<endl;
    return 0;
}
