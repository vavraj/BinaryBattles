#include<iostream>
using namespace std;

void stair(int n)
{
    if(n==0)
    return;
    string ar[10]={"zero ","one ","two ","three ","four ","five ","six ","seven ","eight ","nine "};
    int temp=n%10; 
    n=n/10;
    stair(n);
    cout<<ar[temp];
    // switch (temp)
    // {
    // case 1:cout<<"one ";break;
    // case 2:cout<<"two ";break;
    // case 3:cout<<"three ";break;
    // case 4:cout<<"four ";break;
    // case 5:cout<<"five ";break;
    // case 6:cout<<"six ";break;
    // case 7:cout<<"seven ";break;
    // case 8:cout<<"eight ";break;
    // case 9:cout<<"nine ";break;
    // default:cout<<"zero ";break;
    // }
}
int main()
{
    int n;
    cin>>n;
    stair(n);
    cout<<endl;
    return 0;
}