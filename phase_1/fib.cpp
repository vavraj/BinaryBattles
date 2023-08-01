#include<iostream>
using namespace std;

int fibbonaci(int n)
{
    if(n==1)
    {
        return 0;
    }
    else if(n<4)
    {
        return 1;
    }
    return fibbonaci(n-1)+fibbonaci(n-2);

}
int main()
{
    int a;
    cin>>a;
    int ans=fibbonaci(a);
    cout<<ans;
    return 0;
}