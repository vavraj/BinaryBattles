#include<iostream>
using namespace std;

void rev_array(int ar[],int n,int m)
{
    int s=m-1;
    int e=n-1;
    while(s<e)
    {
        // swap(ar[s],ar[e]);
        int temp=ar[s];
        ar[s]=ar[e];
        ar[e]=temp;
        s++;
        e--;
    }
}
void display(int ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int ar[100];
    cout<<"enter no of elements u want tos tore: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter no. "<<i+1<<": ";
        cin>>ar[i];
    }
    cout<<"enter the pos from which u want to reverse the array: ";
    int m;
    cin>>m;
    display(ar,n);
    rev_array(ar,n,m);
    display(ar,n);
    return 0;
}