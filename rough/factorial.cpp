#include<iostream>
using namespace std;

int factorial(int n){
    if(n==1)
        return 1;
    
    return n*factorial(n-1);
}

void factorialLoop(int n){
    int answer=1;
    for(int i=1;i<=n;i++){
        answer=i*answer;
    }
    cout<<answer<<endl;
}
int main()
{
    cout<<factorial(5)<<endl;
    factorialLoop(6);
    return 0;
}