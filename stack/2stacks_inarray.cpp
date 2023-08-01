#include<iostream>
using namespace std;

class twostack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;    
    twostack(int size)
    {
        this->size=size;
        arr=new int[size];
        top1=-1;
        top2=size;
    }
    void push1(int data)
    {
        if(top1<top2-1)// or top2-top1>1
        {
            top1++;
            arr[top1]=data;
        }
        else{
            cout<<"Stack1 overflow"<<endl;
        }
    }
    void push2(int data)
    {
        if(top2>top1+1)
        {
            top2--;
            arr[top2]=data;
        }
        else{
            cout<<"Stack2 overflow"<<endl;
        }
    }
    void pop1()
    {
        if(top1>=0)
        {
            top1--;
        }
        else{
            cout<<"stack underflow for stack1"<<endl;
        }
    }
    void pop2()
    {
        if(top2<size)
        {
            top2++;
        }
        else{
            cout<<"stack underflow for stack2"<<endl;
        }
    }
    void print() 
    {
        int i=top1;
        int j=top2;
        cout<<"stack 1"<<endl;
        while(i>=0)
        {
            cout<<arr[i--]<<endl;
        }
        cout<<"stack 2"<<endl;
        while(j<size)
        {
            cout<<arr[j++]<<endl;
        }
    }

};

int main()
{
    twostack s(10);

    s.push1(10);
    s.push2(-10);
    s.push2(-30);
    s.push1(40);
    s.push1(80);
    s.push2(-20);
    s.push2(-40);
    s.push1(20);
    s.push2(-50);
    s.push1(30);

    s.print();   

    s.pop1();
    s.pop2();
    s.pop1();
    s.pop2();
    s.pop2();
    s.print();   
    return 0;
}