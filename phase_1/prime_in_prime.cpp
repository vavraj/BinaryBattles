#include<iostream>
using namespace std;

int count_prime(int n)
{
    int count =0;
    for(int i=2;i<n;i++)
    {
        int temp=0;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                temp++;
            }
        }
        if(temp==0)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<count_prime(n)<<endl;
    
    return 0;
}