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
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        // if empty
        if (rear == size - 1 && front == 0 || rear == (front - 1) % (size - 1))
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (front == -1)//inserting first elment
        {
            front = rear = 0;
        }
        else if (rear = size - 1 && front != 0)//to maintain cyclic nature
        {
            rear = 0;
        }
        else//normal flow
        {
            rear++;
        }
        arr[rear] = data;
    }
    void pop()
    {
        if (front == -1)//if empty
        {
            cout << "Queue is empty" << endl;
            return;
        }

        arr[front] = -1;
        
        if (front == rear)//if single element
        {
            front = rear = -1;
        }
        else if(front==size-1)//to maintain cyclic nature
        {
            front=0;
        }
        else//normal flow
        {
            front++;
        }
    }
};
int main()
{
    Queue q(5);
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(25);
    q.push(45);
    q.push(65);
    return 0;
}