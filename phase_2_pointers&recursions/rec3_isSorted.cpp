#include <iostream>
using namespace std;

bool isSorted(int ar[], int size)
{
    // if(size<2 && ar[0]<=ar[1])
    // {
    //     return true;
    // }
    // if(ar[size-2]<=ar[size-1])
    // {
    //     return isSorted(ar,size-1);
    // }
    // return false;

    if (size == 0 || size == 1)
    {
        return true;
    }
    if (ar[0] > ar[1])
    {
        return false;
    }
    else
    {
        return isSorted(ar + 1, size - 1);
    }
    
}
int sum(int ar[],int size)
{
    if(size==0)
    return 0;
    if(size==1)
    return ar[0];

    return ar[0]+sum(ar+1,size-1);
}
bool linear_search(int ar[],int size,int key)
{
    if(size==0)
    return false;
    
    if(key==ar[0])
    return true;
    else
    return linear_search(ar+1,size-1,key);
    
}

int main()
{
    int n;
    cin >> n;
    int *ar = new int[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    // cout << isSorted(ar, n) << endl;
    // cout<<sum(ar,n)<<endl;
    int key;
    cin>>key; 
    cout<<linear_search(ar,n,key)<<endl;
    return 0;
}