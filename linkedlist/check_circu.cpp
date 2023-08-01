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
        int value = this->data;
        if (this->next != NULL)
        {
            next = NULL;
            delete next;
        }
        cout << "Node deleted with value " << value << endl;
    }
};

void insert_circular(node *&tail, int element, int data)
{

    // if list is empty
    if (tail == NULL)
    {
        node *newnode = new node(data);
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        //  non-empty list
        // assuming that element is already present in the list
        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        node *temp = new node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
void insert_linear(node *&head, node *&tail,int d)
{
    node *temp = new node(d);

    if (head == NULL)
    {
        head = temp;
        tail = head;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

bool check(node *head)
{
    // empty list
    if (head == NULL)
    {
        cout << "Empty List: ";
        return true;
    }
    
    // if single node

    if (head->next == NULL)
    {
        return false;
    }
    if (head->next == head)
    {
        return true;
    }

    // for multiple nodes
    node*temp=head->next;//we point to next otherwise the condition will be false in first iteration
    while(temp!=NULL && temp!=head)
    {
        temp=temp->next;
    }

    if(temp==head)
    {
        return true;
    }
    return false; 

}

int main()
{
    node *tailc = NULL;
    node *head= NULL;
    node *tail = NULL;
    insert_circular(tailc, 5, 3);
    insert_circular(tailc, 3, 5);
    insert_circular(tailc, 5, 7);
    insert_circular(tailc, 5, 8);
    print(tailc);
    cout<<check(tailc)<<endl;

    insert_linear(head,tail,5);
    insert_linear(head,tail,10);
    insert_linear(head,tail,15);
    insert_linear(head,tail,25);
    // print(head);
    cout<<check(head)<<endl;
    return 0;
}