#include<iostream>
using namespace std;


int found(int ar[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(ar[i]==key)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int ar[]={10,56,96,-56,54,-96,1,63,-100};
    int size=sizeof(ar)/sizeof(int);
    cout<<size;
    int n;
    cout<<"Enter a number to be searched: ";
    cin>>n;
    int ans=found(ar,size,n);
    if(ans){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    return 0;
}