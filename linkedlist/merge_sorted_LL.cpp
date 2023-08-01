#include <iostream>
#include <map>
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
        }
        delete next;
        cout << "Dummy node with value " << value << " is deleted " << endl;
    }
};

void insert(int data, node *&head, node *&tail)
{
    node *temp = new node(data);
    if (head == NULL)
    {
        head = temp;
        tail = head;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *merge_two(node *&head1, node *&head2)
{

    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    if(head1==NULL && head2==NULL)
    {
        return NULL;
    }
    node *curr1 = head1;
    node *curr2 = head2;
    node *head = new node(-1);
    node *tail = head;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data <= curr2->data)
        {
            tail->next = curr1;
            tail = curr1;
            curr1 = curr1->next;
        }
        else
        {
            tail->next = curr2;
            tail = curr2;
            curr2 = curr2->next;
        }
    }
    while (curr1 != NULL)
    {
        tail->next = curr1;
        tail = curr1;
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        tail->next = curr2;
        tail = curr2;
        curr2 = curr2->next;
    }
    head = head->next;
    return head;
}

int main()
{
    node *head1 = NULL, *head2 = NULL;
    node *tail1 = NULL, *tail2 = NULL;

    insert(1, head1, tail1);
    insert(3, head1, tail1);
    insert(5, head1, tail1);
    insert(8, head1, tail1);

    insert(2, head2, tail2);
    insert(4, head2, tail2);
    insert(5, head2, tail2);
    insert(8, head2, tail2);
    insert(10, head2, tail2);

    print(head1);
    print(head2);

    node *ans = merge_two(head1, head2);
    print(ans);
}