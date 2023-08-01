#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        if (this->next != NULL)
        {
            next = NULL;
        }
        delete next;
    }
};
void push(int data, node *&top, node *&bottom)
{
    node *newnode = new node(data);
    if (top == NULL)
    {
        top = newnode;
        bottom = top;
        return;
    }
    top->next = newnode;
    top = newnode;
}

void print_stack(node *top, node *bottom)
{
    if (top == NULL)
    {
        cout << "empty stack" << endl;
        return;
    }
    if (bottom == NULL)
    {
        return;
    }
    print_stack(top, bottom->next);
    cout << bottom->data << endl;
    
}

void pop(node *&top, node *&bottom)
{
    if (top == NULL)
    {
        cout << "stack underflow:";
        return;
    }
    if(bottom->next==NULL)
    {
        node*temp=top;
        top=NULL;
        bottom=top;
        delete temp;
        return;
    }
    node *temp = bottom;
    while (temp->next != top)
    {
        temp = temp->next;
    }
    node *elem_to_delete = top;
    top = temp;
    top->next=NULL;
    delete elem_to_delete;
}
void peek(node *top)
{
    if (top == NULL)
    {
        cout << "empty list"<<endl;
        return;
    }
    cout << top->data<<endl;
}

void empty(node *top)
{
    if (top == NULL)
    {
        cout << "yes list is empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }
}
int main()
{
    node *top = NULL;
    node *bottom = NULL;
    push(5, top, bottom);
    push(15, top, bottom);
    push(25, top, bottom);
    push(35, top, bottom);

    print_stack(top, bottom);

    pop(top, bottom);
    pop(top, bottom);
    peek(top);
    empty(top);
    print_stack(top, bottom);

    return 0;
}