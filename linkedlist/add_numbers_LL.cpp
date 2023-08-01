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

int get_length(node *head)
{
    int count = 0;
    while (head != 0)
    {
        count++;
        head = head->next;
    }
    // cout << count << endl;
    return count;
}
node *reverse_LL(node *&head) // TC = O(n) ||  SC = O(1)
{
    node *prev = NULL;
    node *curr = head;
    while (curr != NULL)
    {
        // cout<<"H";
        node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return head;
}

node *add(node *first, node *second)
{
    node *anshead = NULL;
    node *anstail = NULL;
    int carry = 0;

    /*while (first != NULL && second != NULL)
    {
        int sum = first->data + second->data + carry;
        int digit = sum % 10;
        insert(digit, anshead, anstail);
        carry = sum / 10;
        first = first->next;
        second = second->next;
    }

    while (first != NULL)
    {
        int sum = first->data + carry;
        int digit = sum % 10;
        insert(digit, anshead, anstail);
        carry = sum / 10;
        first = first->next;
    }
    while (second != NULL)
    {
        int sum = second->data + carry;
        int digit = sum % 10;
        insert(digit, anshead, anstail);
        carry = sum / 10;
        second = second->next;
    }
    if (carry != 0)
    {
        insert(carry, anshead, anstail);
    }*/
    
    while(first!=NULL || second!=NULL || carry!=0)
    {
        int val1=0;
        if(first!=NULL)
            val1=first->data;

        int val2=0;
        if(second!=NULL)
            val2=second->data;

        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        insert(digit, anshead, anstail);
        carry = sum / 10;
        if(first!=NULL)
            first = first->next;
        if(second!=NULL)
            second = second->next;
    }
    return anshead;
}
node *sum(node *first, node *second)
{

    first = reverse_LL(first);
    second = reverse_LL(second);

    node *ans = add(first, second);

    ans = reverse_LL(ans);

    return ans;
}
int main()
{
    node *head1 = NULL, *head2 = NULL;
    node *tail1 = NULL, *tail2 = NULL;

    insert(9, head1, tail1);
    insert(8, head1, tail1);
    insert(8, head1, tail1);
    insert(9, head1, tail1);

    insert(5, head2, tail2);
    insert(4, head2, tail2);
    insert(9, head2, tail2);
    insert(0, head2, tail2);
    insert(9, head2, tail2);
    insert(1, head2, tail2);

    node *ans = sum(head1, head2);

    print(ans);
    return 0;
}