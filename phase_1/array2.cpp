#include<iostream>
using namespace std;


void reverse(int ar[],int size)
{
    for(int i=0;i<size/2;i++)
    {
        int j=size-1-i;
        int temp=ar[i];
        ar[i]=ar[j];
        ar[j]=temp;
        
    }
    for(int i=0;i<size;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    
}

void alternate(int ar[],int size)
{
    for(int i=0;i<size-1;i=i+2)
    {
        // int j=i+1;
        // int temp=ar[i];
        // ar[i]=ar[j];
        // ar[j]=temp;
        if(i+1<size)
        swap(ar[i],ar[i+1]);
        
    }
    for(int i=0;i<size;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    
}
int main()
{
    int ar[]={10,56,96,-56,54,-96,1,63,-100};
    int size=sizeof(ar)/sizeof(int);
    int n;
    alternate(ar,size);
    reverse(ar,size);
    return 0;
}