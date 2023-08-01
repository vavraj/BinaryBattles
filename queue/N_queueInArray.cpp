#include <iostream>
using namespace std;

class Nqueue
{
private:
    int N,K;
    int *ar;
    int *front;
    int *rear;
    int *next;
    int freespot;

public:
    Nqueue(int N, int K)
    {
        this->N=N;
        this->K=K;
        ar = new int[N];
        next = new int[N];
        front = new int[K];
        rear = new int[K];

        for (int i = 0; i < K; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < N; i++)
        {
            next[i] = i+1;
        }

        next[N - 1] = -1;

        freespot = 0;
    }

    void push(int Data, int Q)
    {
        // check for overflow
        if (freespot == -1)
        {
            cout << "Stack Overflow";
            return;
        }
        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        if (front[Q - 1] == -1)
        {
            // entering first element
            front[Q - 1] = index;
        }
        else
        {
            // link new element to previous element
            next[rear[Q - 1]] = index;
        }

        // update next
        next[index] = -1;

        // point rear to index
        rear[Q - 1] = index;

        // inserting element
        ar[index] = Data;
    }

    int pop(int Q)
    {
        if (front[Q - 1] == -1)
        {
            cout << "Queue Underflow ";
            return -1;
        }
        // pop front se hoga
        int index = front[Q - 1];
        // update front
        front[Q - 1] = next[index];
        // update freespot
        next[index] = freespot;
        freespot = index;

        return ar[index];
    }
};

int main()
{
    Nqueue Q(10,3);
    Q.push(10,1);
    Q.push(-10,2);
    Q.push(20,1);
    Q.push(-20,2);
    
    cout<<Q.pop(1)<<endl;
    cout<<Q.pop(2)<<endl;
    cout<<Q.pop(1)<<endl;
    cout<<Q.pop(2)<<endl;
    cout<<Q.pop(1)<<endl;
    return 0;
}