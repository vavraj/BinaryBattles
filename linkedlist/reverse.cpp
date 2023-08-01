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
};

void insert(node *&head, node *&tail)
{
    int d;
    cout << "Enter number: ";
    cin >> d;
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

void reverse(node *&head)
{
    // empty list
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    node *prev = NULL;
    node *curr = head;
    node *forward;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev; //we have to update head also
}

void print(node *head)
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
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
    char ans = 'y';
    do
    {
        insert(head, tail);
        cout << "Do u want to enter another element(y/n): ";
        cin >> ans;
    } while (ans == 'y');

    print(head);

    reverse(head);

    print(head);
    return 0;
}