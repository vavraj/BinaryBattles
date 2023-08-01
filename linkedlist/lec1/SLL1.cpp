#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

// starting node ke pehle new node add krega
void insert_at_head(node *&head, int data)
{
    // creating new node
    node *temp = new node(data);

    temp->next = head;
    head = temp;
}

// ending node ke aage new node add krega
void insert_at_tail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void insert_between_nodes(node *&head, node *&tail, int position, int data)
{
    // insert at start
    if (position == 1)
    {
        insert_at_head(head, data);
        return;
    }
    node *temp = head;
    int count = 1;
    while (count++ < position - 1)
    {
        temp = temp->next;
    }

    // insert at last
    if (temp->next == NULL)
    {
        insert_at_tail(tail, data);
        return;
    }

    node *nodeTOinsert = new node(data);
    nodeTOinsert->next = temp->next;
    temp->next = nodeTOinsert;
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

void delete_by_pos(node *&head, int pos)
{

    // if head is to be deleted
    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        // deleting any middle or last node
        node *curr = head;
        node *prev = NULL;
        int count = 1;

        while (count++ < pos)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        // curr->next=NULL;
        delete curr;
    }
}


/*
void delete_by_value(node *&head, node *&tail, int value)
{
    int flag = 0;
    node *temp = head;
    node *prev;
    int count = 1;

    // if head is to be deleted-->update head
    if (head->data == value)
    {
        head = head->next;
        delete temp;
        return;
    }
    while (temp->next != NULL)
    {
        if (temp->data == value)
        {
            flag = 1;
            break;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    // if last element to be deleted --> update tail
    if (temp->next == NULL && temp->data == value)
    {
        tail = prev;
        tail->next = NULL;
        delete temp;
        return;
    }

    // suppose element to be deleted is not in the linked list then it will do nothing
    if (flag)
    {
        prev->next = temp->next;
        delete temp;
    }
}
*/


int main()
{
    // creating new node
    node *node1 = new node(10);
    cout << node1->data << endl;
    // cout << node1->next << endl;

    // pointing head to node1
    node *head = node1;
    node *tail = node1;

    // insert_at_head(head,12);
    // insert_at_head(head,15);
    // print(head);

    insert_at_tail(tail, 12);
    insert_at_tail(tail, 15);
    insert_at_tail(tail, 17);
    insert_at_tail(tail, 20);
    print(head); // isme tail nii pass hoga head hi pass hoga becs traverse wo starting se hi hoga

    insert_between_nodes(head, tail, 3, 25);
    insert_between_nodes(head, tail, 1, 45); // inserting at head
    insert_between_nodes(head, tail, 8, 54); // inserting at tail
    print(head);

    // cout << "Head " << head->data << endl;
    // cout << "Tail " << tail->data << endl;

    cout << "\ndeleting by position" << endl;
    delete_by_pos(head,5);
    print(head);


    // cout << "deleting by value" << endl;
    // delete_by_value(head, tail, 99);
    // print(head);

    // cout << "Head " << head->data << endl;
    // cout << "Tail " << tail->data << endl;

    return 0;
}
