#include <iostream>
using namespace std;

long long int find_sqroot_integer(int n)
{
    int s = 0, e = n;
    long long int mid = s + (e - s) / 2;
    long long int ans;
    while (s <= e)
    {
        if (mid * mid > n)
        {
            e = mid - 1;
        }
        else if (mid * mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (mid * mid == n)
        {
            return mid;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
double more_precision(int n,int precision,int tempsol)
{
    double factor=1;
    double ans=tempsol;
    for(int i=0;i<precision;i++)
    {
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor)
        {
            ans=j;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int tempsol = find_sqroot_integer(n);
    cout<<"Ans is: "<<more_precision(n,2,tempsol)<<endl;
    return 0;
}