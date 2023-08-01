#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~node()
    {
        int value=this->data;
        // free memory
        if(this->next!=NULL || this->prev!=NULL)
        {
            cout<<"Hi"<<endl;
            this->next=NULL;
            this->prev=NULL;
            delete next;
            delete prev;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};
void insert(int data,node*&head,node*&tail)
{
    if(tail==NULL)
    {
        node*temp=new node(data);
        tail=temp;
        head=tail;
    }
    else{
        node*temp=new node(data);
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
}

void print(node*&head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void delete_value(int value,node*&head,node*&tail)
{
    // if head deleted
    if(head->data==value)
    {
        node*temp=head;
        head=head->next;
        // head->prev=NULL;
        // temp->next=NULL;
        delete temp;
    }
    else{
        node*temp=head;
        node*previous;
        while(temp->data!=value)
        {
            previous=temp;
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            previous->next=NULL;
            temp->prev=NULL;// temp->next is already NULL
            delete temp;
            tail=previous;
            return;
        }
        previous->next=temp->next;
        temp->next->prev=previous;
        // temp->next=NULL;
        // temp->prev=NULL;
        delete temp;
    }
}
int main()
{
    node*head=NULL;
    node*tail=NULL;
    insert(2,head,tail);
    insert(4,head,tail);
    insert(6,head,tail);
    insert(8,head,tail);
    insert(10,head,tail);
    print(head);

    delete_value(10,head,tail);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
    return 0;
}