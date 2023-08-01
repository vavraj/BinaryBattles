#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *ar1=new int[n];
        int *ar2=new int[n];
        for(int i=0;i<n;i++)
        cin>>ar1[i];
        for(int i=0;i<n;i++)
        cin>>ar2[i];
        sort(ar1,ar1+n);
        sort(ar2,ar2+n);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(ar2[i]<ar1[j])
                {
                    swap(ar1[j],ar2[i]);
                    i=n;
                    break;
                }
                else{
                    continue;
                }
            }
        }
        sort(ar1,ar1+n);
        for(int i=0;i<n;i++)
        cout<<ar1[i]<<" ";
        cout<<ar1[n-1]-ar1[0]<<endl;
    }
    return 0;
}
