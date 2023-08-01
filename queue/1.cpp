#include <iostream>
using namespace std;

class Queue
{
    int size;
    int *arr;
    int front, rear;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    int isEmpty()
    {
        if(front==rear)
        {
            return 1;
        }
        return -1;
    }

    int Front()
    {
        if(front==rear)
        {
            return -1;
        }
        return arr[front];
    }
    void push(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear] = data;
        rear++;
    }
    void pop()
    {
        if (front==rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        arr[front]=-1;
        front++;
        if(front==rear)
        {
            front=0;
            rear=0;
        }
    }
    void print()
    {
        if (rear == 0 || front == size)
        {
            cout << "Empty" << endl;
            return;
        }
        for (int i = front; i < rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q(5);
    q.print();
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(25);
    q.push(45);
    q.push(65);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    cout<<q.Front()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}