#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    int a;
    cout << "Enter money: ";
    cin >> n;
    while (n != 0)
    {
        if(n>=1000)
        {
            m=1;
        }
        else if(n>=500)
        {
            m=2;
        }
        else if(n>=100)
        {
            m=3;
        }
        else if(n>=50)
        {
            m=4;
        }
        else if(n>=20)
        {
            m=5;
        }
        else if(n>=10)
        {
            m=6;
        }
        else if(n>=5)
        {
            m=7;
        }
        else if(n>=1)
        {
            m=8;
        }
        switch (m)
        {
        case  1:
        {
            a = n / 1000;
            n = n % 1000;
            cout << "1000- " << a<<endl;
            break;
        }
        case 2:
        {
            a = n / 500;
            n = n % 500;
            cout << "500- " << a<<endl;
            break;
        }
        case 3:
        {
            a = n / 100;
            n = n % 100;
            cout << "100- " << a<<endl;
            break;
        }
        case 4:
        {
            a = n / 50;
            n = n % 50;
            cout << "50- " << a<<endl;
            break;
        }
        case 5:
        {
            a = n / 20;
            n = n % 20;
            cout << "20- " << a<<endl;
            break;
        }
        case 6:
        {
            a = n / 10;
            n = n % 10;
            cout << "10- " << a<<endl;
            break;
        }
        case 7:
        {
            a = n / 5;
            n = n % 5;
            cout << "10- " << a<<endl;
            break;
        }
        case 8:
        {
            a = n / 1;
            n = n % 1;
            cout << "1- " << a<<endl;
            break;
        }
        }
    }
    return 0;
}