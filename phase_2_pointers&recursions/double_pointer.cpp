#include<iostream>
using namespace std;

int main()
{
    int i=5;
    int* ptr1=&i;
    int** ptr2=&ptr1;
    
    cout<<ptr1<<endl; // i ka address
    cout<<*ptr2<<endl;// ptr1 pe jo value store hai yaani i ka address
    cout<<&ptr1<<endl;// ptr1 ka address
    cout<<ptr2<<endl;// ptr1 ka address as ptr2 pointing to ptr1
    cout<<*ptr1<<endl;// 5
    cout<<**ptr2<<endl;// 5
    return 0;
 }