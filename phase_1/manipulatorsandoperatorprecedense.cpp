#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    //  CONSTANT IN C++ -->
    // const float pi=3.14; // 'const' does not allow to change the value of pi through the whole program
    // cout<<"the value of a is "<<pi<<endl;
    // pi=5; //Here u will get an eroor bcs pi is an constant
    // cout<<"the value of a is "<<pi<<endl;
    
    // MANIPULATORS IN C++  -->
    // int a=8, b=52, c=105, d=1254;
    // cout<<"the value of a without setw :"<<a<<endl;
    // cout<<"the value of b without setw :"<<b<<endl;
    // cout<<"the value of c without setw :"<<c<<endl;
    // cout<<"the value of d without setw :"<<d<<endl;
    
    // cout<<"the value of a with setw :"<<setw(4)<<a<<endl;
    // cout<<"the value of b with setw :"<<setw(4)<<b<<endl;
    // cout<<"the value of c with setw :"<<setw(4)<<c<<endl;
    // cout<<"the value of d with setw :"<<setw(4)<<d<<endl;


    // OPERATOR PRESEDENCE ---> (* / %)
    //                          (+  -)
    // ASSOCIATIVITY --> FROM LEFT TO RIGHT WHICHEVER OPERATOR COMES FIRST ON THE SAME LEVEL OF PRECEDENCE 
    int a=3, b=4;
    // c=(a*5)+b;
    int c = a*5+b-45+87; // ((((a*5)+b)-45)+87)
    cout<<c<<endl;
    return 0;
}
