#include <iostream>
using namespace std;

// using array
class stack
{
public:
    int *arr;
    int top;
    int size;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "stack overflow:" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack underflow:" << endl;
        }
    }
    int peek()
    {
        if(top>=0)
        {
            return arr[top];
        }
        else{
            cout<<"stack empty:";
            return -1;
        }
    }
    bool empty()
    {
        if(top==-1)
        {
            cout<<"stack is empty";
            return true;
        }
        cout<<"stack is not empty:";
        return false;
    }
    void print()
    {
        int i=top;
        while(i>=0)
        {
            cout<<arr[i]<<endl;
            i--;
        }
    }

};
int main()
{
    stack s(5);
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(7);
    s.push(17);
    s.push(77);

    s.print();
    // cout<<s.peek()<<endl;
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // cout<<s.peek()<<endl;
    // cout<<s.empty()<<endl;
    return 0;
}