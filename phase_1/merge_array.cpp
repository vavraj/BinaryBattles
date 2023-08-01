#include<iostream>
#include<algorithm>
using namespace std;

void merge_array(int ar1[],int n1,int ar2[],int n2)
{
int n3=n1+n2;

for(int i=n1;i<n3;i++)
{
    ar1[i]=ar2[i+n2-n3];
}
sort(ar1,ar1+n1);

for(int i=0;i<n3;i++)
{
    cout<<ar1[i]<<" ";
}
}
int main()
{
    int ar1[]={1,2,3,4,5,45,21};
    int ar2[]={6,7,8,9,56,41};
    int n1=sizeof(ar1)/sizeof(int);
    int n2=sizeof(ar2)/sizeof(int);
    merge_array(ar1,n1,ar2,n2);
    return 0;
}