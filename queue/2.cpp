#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    ~node()
    {
        if(this->next!=NULL)
        {
            this->next=NULL;
        }
        delete next;
    }
};
class Queue{
    node*front;
    node*rear;
    public:
    Queue()
    {
        front=NULL;
        rear=NULL;
    }
    void push(int data)
    {
        node*temp=new node(data);
        if(rear==NULL)
        {
            front=temp;
            rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
    void pop()
    {
        if(front==NULL)
        {
            cout<<"empty"<<endl;
            return;
        }
        node*temp=front;
        front=front->next;
        delete temp;
    }
    void print()
    {
        node*temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{   
    Queue q;
    q.push(10);      
    q.push(20);      
    q.push(30);      
    q.push(40);      
    q.print();
    q.pop();
    q.pop();
    q.print();
    q.pop();
    q.pop();
    q.pop();
    return 0;
}