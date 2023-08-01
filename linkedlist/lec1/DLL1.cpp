#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_head(node *&head, int data)
{
    // if empty list
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        return;
    }
    node *temp = new node(data);
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insert_at_tail(node *&tail, int data)
{
    // if empty list
    if (tail == NULL)
    {
        node *temp = new node(data);
        tail = temp;
        return;
    }
    node *temp = new node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insert_at_pos(node *&head, node *&tail, int data, int pos)
{
    // inserting at head
    if (pos == 1)
    {
        insert_at_head(head, data);
        return;
    }
    node *temp = head;
    int count = 1;
    while (count++ < pos - 1)
    {
        temp = temp->next;
    }
    // inserting at last
    if (temp->next == NULL)
    {
        insert_at_tail(tail, data);
        return;
    }

    node *nodeTOinsert = new node(data);
    nodeTOinsert->next = temp->next;
    temp->next->prev = nodeTOinsert;
    temp->next = nodeTOinsert;
    nodeTOinsert->prev = temp;
}
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    print(head);

    insert_at_head(head, 15);
    insert_at_head(head, 17);
    insert_at_head(head, 20);

    print(head);
    // cout<<"Head: "<<head->data<<endl;
    // cout<<"Tail: "<<tail->data<<endl;

    // insert_at_tail(tail, 100);
    // insert_at_tail(tail, 170);
    // insert_at_tail(tail, 200);

    // print(head);
    // // cout<<"Head: "<<head->data<<endl;
    // // cout<<"Tail: "<<tail->data<<endl;

    // insert_at_pos(head, tail, 1000, 5);
    // insert_at_pos(head, tail, 5000, 3);

    // print(head);

    return 0;
}