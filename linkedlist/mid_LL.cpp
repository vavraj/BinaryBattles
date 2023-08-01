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

node *find_mid(node *head)
{
    node *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    int mid = (len / 2);
    temp = head;
    int count = 1;
    while (mid--)
    {
        temp = temp->next;
    }

    return temp;
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

node *optimizedsoln(node *head)
{

    node *temp1; // covers two node
    node *temp2; // covers one node
    temp1 = temp2 = head;

    //  EMPTY LIST or single element
    if (temp1 == NULL || temp1->next == NULL)
    {

        return head;
    }

    while (temp1 != NULL && temp1->next != NULL)
    {
        temp2 = temp2->next;
        temp1 = temp1->next->next;
    }

    return temp2;
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

    node *mid_node = find_mid(head);
    cout << "Middle element is: " << mid_node->data << endl;
    node *mid_node1 = optimizedsoln(head);
    cout << "Middle element is using optimized soln: " << mid_node1->data << endl;
    return 0;
}