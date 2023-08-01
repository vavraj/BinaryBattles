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

void insert(node *&tail, int element, int data)
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
    if(tail==NULL)
    {
        cout<<"List is empty "<<endl;
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

void delete_node(node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }

    
    node *prev = tail;
    node *curr = prev->next;


    do
    {
        prev = curr;
        curr = curr->next;
    } while (curr->data != value);

    prev->next = curr->next;

    // single-node linkedf list
    if(curr==prev)
    {
        tail=NULL;
    }
    // linked list>=2 nodes
    else if (tail == curr)
    {
        tail = prev;
    }
    delete curr;
}
int main()
{

    node *tail = NULL;
    insert(tail, 5, 3);
    print(tail);
    // insert(tail, 3, 5);
    // insert(tail, 5, 7);
    // insert(tail, 5, 8);
    // print(tail);

    delete_node(tail, 3);
    print(tail);
    return 0;
}