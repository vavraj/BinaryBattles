#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    int n;
    int a;
    cout<<"Enter money: ";
    cin>>n;
    while(n!=0)
    {
    switch(n){
    case (n>=1000):
    {
        a=n/1000;
        n=n%1000;
        cout<<"1000- "<<a;
        break;
    }
    case(n>=500):
    {
        a=n/500;
        n=n%500;
        cout<<"500- "<<a;
        break;
    }
    case (n>=100):
    {
        a=n/100;
        n=n%100;
        cout<<"100- "<<a;
        break;
    }
    case (n>=50):
    {
        a=n/50;
        n=n%50;
        cout<<"50- "<<a;
        break;
    }
    case (n>=20):
    {
        a=n/20;
        n=n%20;
        cout<<"20- "<<a;
        break;
    }
    case (n>=10):
    {
        a=n/10;
        n=n%10;
        cout<<"10- "<<a;    
        break;
    }
    case (n>=5):
    {
        a=n/5;
        n=n%5;
        cout<<"10- "<<a;
        break;    
    }
    case (n>=1):
    {
        a=n/1;
        n=n%1;
        cout<<"1- "<<a;
        break;    
    }
    
    }}
    return 0;
}