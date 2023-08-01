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

int getlength(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

node *reverseINgroups(node *&head, int n)
{

    // base cond
    if (head == NULL)
    {
        return NULL;
    }

    // Step 1- reverse first n nodes
    node *prev = NULL;
    node *curr = head;
    int count = 0;
    node *forward = NULL;
    while (curr != NULL || count < n)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    // Step 2- baaki ka recursion dekh lega
    if (forward != NULL)
    {
        head->next = reverseINgroups(forward, n); // yaha pe reverse hue LL ka head aayega
    }
    // Step 3- return head of reversed list
    return prev;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int i;
    cin >> i;
    while (i--)
    {
        insert(head, tail);
    }

    print(head);
    cout << "ENTER GROUP: ";
    int n;
    cin >> n;

    node*ans = reverseINgroups(head, n);

    print(ans);

    return 0;
}