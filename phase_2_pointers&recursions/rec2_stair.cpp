#include<iostream>
using namespace std;
int ways(long long n)
{
    if(n<0)
    return 0;
    if(n==0)
    return 1;

    return ways(n-1)+ways(n-2);
}
int main()
{
    long long n;
    cin>>n;
    cout<<ways(n)<<endl;
    return 0;
}