#include<iostream>
using namespace std;

bool binary_search(int ar[],int start,int end ,int key)
{
    if(start>end)
    return false;
 
    int mid=start+(end-start)/2;
 
    if(ar[mid]==key)
    return true;

    if(key<ar[mid])
    return binary_search(ar,start,mid-1,key);
    else
    return binary_search(ar,mid+1,end,key);

}
int main()
{
    int n;
    cin >> n;
    int *ar = new int[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    int key;
    cin>>key; 
    int start=0;
    int end=n-1;
    cout<<binary_search(ar,start,end,key)<<endl;
    return 0;
}