#include<iostream>
using namespace std;

int main()
{
    int i,j,n,temp=1;
    cout<<"Enter no of rows: ";
    cin>>n;
    i=1;
    while(i<=n)
    {
        j=temp;
        while(j<=(n*i))
        {
            cout<<j<<" ";
            j=j+1;
            temp = j;
        }
        cout<<endl;
        i=i+1;
    }   
    return 0;
}