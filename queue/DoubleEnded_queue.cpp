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

    void push_rear(int data)
    {
        if (rear == size - 1 && front == 0 || rear == (front - 1) % (size - 1))
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }
    void push_front(int data)
    {
        // check if queue is full
        if (rear == size - 1 && front == 0 || rear == (front - 1) % (size - 1))
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (front = -1) // inserting first element
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1) // maintain cyclic nature
        {
            front = size - 1;
        }
        else // normal flow
        {
            front--;
        }
        arr[front] = data;
    }

    void pop_rear()
    {
        // check if queue is empty
        if (rear = -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        arr[rear] = -1;
        if (front == rear) // if single element
        {
            front = rear = -1;
        }
        else if (rear == 0) // to maintain cyclic nature
        {
            rear = size - 1;
        }
        else // normal flow
        {
            rear--;
        }
    }

    void pop_front()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
};
int main()
{
    Queue q(5);
    return 0;
}