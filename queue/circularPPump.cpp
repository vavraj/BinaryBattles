#include<iostream>
using namespace std;

struct circularPPump
{
    int petrol;
    int distance;
};

int FindStart(circularPPump p[],int n)
{
    int balance=0;
    int defecit=0;
    int start=0;
    for(int i=0;i<n;i++)
    {
        balance+=p[i].petrol-p[i].distance;
        if(balance<0)
        {
            defecit+=balance;
            start=i+1;
            balance=0;
        }
    }
    if(balance-defecit>=0)
    {
        return start;
    }
    else{
        return -1;
    }
}
int main()
{
    circularPPump p[6]={{6,5},{7,6},{4,7},{10,8},{6,6},{5,4}};
    cout<<FindStart(p,6)<<endl;
    return 0;
}