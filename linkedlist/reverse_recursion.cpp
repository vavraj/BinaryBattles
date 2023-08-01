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

void reverse(node *&head, node *curr, node *prev)
{

    // base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    // relative recursion

    /*

    node*forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
    reverse(head,curr,prev);

    */

    node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

// it will return head of the reversed list
node *reverse1(node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *chotahead = reverse1(head->next);
    // cout<<chotahead->data<<endl; proof that chotahead remains same
    head->next->next = head;//actual reversing is happening with this two statement 
    head->next = NULL;

    // this only return the final head position 
    return chotahead;//the value of this will remain same as it returns the head that is last node of original linked list
}


int main()
{
    node *head = NULL;
    node *tail = NULL;
    int i = 0;
    while (i++ < 5)
    {
        insert(head, tail);
    }

    print(head);

    node *prev = NULL;
    node *curr = head;
    // reverse(head,curr,prev);
    head=reverse1(head);

    print(head);
    return 0;
}