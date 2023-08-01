#include<iostream>
using namespace std;
int factorial(int a)
{
    if(a==0)
    {
        return 1;
    }
    return a*factorial(a-1);
}
int ncr(int n,int r)
{
    int ans=factorial(n)/(factorial(n-r)*factorial(r));
    return ans;
}
int main()
{
    int a,b;
    cout<<"Enter two nos: ";
    cin>>a>>b;
    int ans=ncr(a,b);
    cout<<ans<<endl;
    return 0;
}