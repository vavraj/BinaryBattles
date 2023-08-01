#include<iostream>
using namespace std;

void tail_rec_print(int n)
{
    if(n==0)
    return;

    cout<<n<<endl;
    tail_rec_print(n-1); 
}

void head_rec_print(int n)
{
    if(n==0)
    return;

    head_rec_print(n-1); 
    cout<<n<<endl;
}
int main()
{
    int n;
    cin>>n;
    cout<<"Tail rec: "<<endl;
    tail_rec_print(n);
    cout<<"Head rec: "<<endl;
    head_rec_print(n);
    return 0;
}