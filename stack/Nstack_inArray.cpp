#include <iostream>
using namespace std;

class nStacks
{
private:
    int *arr;
    int *next;
    int *top;
    int n, s, freespot;

public:
    nStacks(int N, int S)
    {
        n = N;
        s = S;
        // create array arr of size S
        arr = new int[s];
        // create array next of size S
        next = new int[s];
        // create array top of size N
        top = new int[n];
        // initialise top with -1
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        // initialise next
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        // update last next
        next[s - 1] = -1;
        // initialise first free space
        freespot = 0;
    }
    bool push(int x, int m)
    {
        // check stacks overflows condition
        if (freespot == -1)
            return false;

        // find index
        int index = freespot;

        // update free spot
        freespot = next[index];

        // Insert element in array
        arr[index] = x;

        // update next
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }
    int pop(int m)
    {
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
    // void print()
    // {
    //     for(int i=0;i<10;i++)
    //     {
    //         cout<<arr[i]<<" ";
    //     }
    // }
    void print(int m)
    {
        while(top[m-1]!=-1)
        {
            int i=top[m-1];
            cout<<arr[i]<<endl;
            pop(m);
        }
    }
};

int main()
{
    nStacks Stack(3, 10);
    Stack.push(-20, 2);
    Stack.push(10, 1);
    Stack.push(300, 3);
    Stack.push(20, 1);
    Stack.push(200, 3);
    Stack.push(-1, 2);
    Stack.push(-10, 2);
    Stack.push(1, 1);
    Stack.push(100, 3);
    // Stack.pop(3);
    // Stack.pop(3);
    Stack.print(3);
    Stack.print(2);
    Stack.print(1);
    return 0;
}