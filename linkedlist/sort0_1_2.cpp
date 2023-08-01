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

node *sort_012(node *&head)
{
    node *temp = head;
    int ar[3] = {0};
    while (temp != NULL)
    {
        ar[temp->data]++;
        temp = temp->next;
    }

    temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (ar[0] != 0)
        {
            temp->data = 0;
            ar[0]--;
        }
        else if (ar[1] != 0)
        {
            temp->data = 1;
            ar[1]--;
        }
        else if (ar[2] != 0)
        {
            temp->data = 2;
            ar[2]--;
        }
        temp = temp->next;
    }
    return head;
}

node *change_links(node *&head)
{
    node *head0 = NULL, *head1 = NULL, *head2 = NULL;
    node *tail0 = NULL, *tail1 = NULL, *tail2 = NULL;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0 && head0 == NULL)
        {
            head0 = temp;
            tail0 = head0;
        }
        else if (temp->data == 0)
        {
            tail0->next = temp;
            tail0 = temp;
        }
        if (temp->data == 1 && head1 == NULL)
        {
            head1 = temp;
            tail1 = head1;
        }
        else if (temp->data == 1)
        {
            tail1->next = temp;
            tail1 = temp;
        }
        if (temp->data == 2 && head2 == NULL)
        {
            head2 = temp;
            tail2 = head2;
        }
        else if (temp->data == 2)
        {
            tail2->next = temp;
            tail2 = temp;
        }
        temp = temp->next;
    }
    tail0->next = head1;
    tail1->next = head2;
    tail2->next = NULL;
    // print(head0);
    return head0;
}

void insertATtail(node *&tail, node *curr)
{
    tail->next = curr;
    tail = curr;
}

void sort_using_dummy_node(node *&head)
{
    node *zerohead = new node(-1);
    node *onehead = new node(-1);
    node *twohead = new node(-1);
    node *zerotail = zerohead;
    node *onetail = onehead;
    node *twotail = twohead;

    node *curr = head;
    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            insertATtail(zerotail, curr);
        }
        else if (value == 1)
        {
            insertATtail(onetail, curr);
        }
        else if (value == 2)
        {
            insertATtail(twotail, curr);
        }
        curr = curr->next;
    }

    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }
    onetail->next = twohead->next;
    twotail->next = NULL;

    head= zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    insert(2, head, tail);
    insert(0, head, tail);
    insert(1, head, tail);
    insert(0, head, tail);
    insert(0, head, tail);
    insert(1, head, tail);
    insert(2, head, tail);
    insert(2, head, tail);
    insert(1, head, tail);
    insert(0, head, tail);
    insert(1, head, tail);
    print(head);
    // sort_012(head);
    // head=change_links(head);

    sort_using_dummy_node(head);
    print(head);
    return 0;
}