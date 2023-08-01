#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

double function1()
{
    int N,K;
    cin>>N>>K;
    vector<int> ar;
    for(int i=0;i<N;i++)
    {
        int n;
        cin>>n;
        ar.push_back(n);
    }
    while(K!=0)
    {
        int maxi=-pow(2,31);
        int mini=pow(2,31)-1;
        vector<int>::iterator it1,it2;
        int n=ar.size();
        for(int i=0;i<n;i++)
        {
            if(maxi<ar[i])
            {
                maxi=ar[i];
                *it1=ar[i];
            }
            if(mini>ar[i])
            {
                mini=ar[i];
                *it2=ar[i];
            }
        }
        ar.erase(it1);
        ar.erase(it2);
        K--;
    }
    double sum=0.000;
    int n=ar.size();
    for(int i=0;i<n;i++)
    {
        sum=sum+ar[i];
    }
    double s=ar.size();
    sum=sum/s;
    
    return sum;
    
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        cout<<function1()<<endl;
    }
    return 0;
}
