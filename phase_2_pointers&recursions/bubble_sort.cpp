#include<iostream>
using namespace std;

void bubble_sort(int *ar,int n)
{
    // base condition
    if(n==0 || n==1)
    return ;
    
    // Solving one case--> it puts largest element at the last position
    for(int i=0;i<n-1;i++)
    if(ar[i]>ar[i+1])
    swap(ar[i],ar[i+1]);

    bubble_sort(ar,n-1);

}
int main()
{
    int ar[]={45,12,36,89,42};
    bubble_sort(ar,5);
    for(int i=0;i<5;i++)
    cout<<ar[i]<<" ";
    return 0;
}