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

bool check_pal(node *head) //    TC = SC = O(n)
{
    if (head == NULL)
    {
        return false;
    }
    int size = get_length(head);
    int *arr = new int[size];
    node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    i = 0;
    int e = size - 1;
    while (i <= e)
    {
        if (arr[i] != arr[e])
        {
            return false;
        }
        else
        {
            i++;
            e--;
        }
    }
    return true;
}

node*reverse_LL(node*&head)// TC = O(n) ||  SC = O(1)
{
    node *prev = NULL;
    node *curr =head;
    while (curr != NULL)
    {
        // cout<<"H";
        node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head=prev;
    return head;
}
bool check_palindrome(node *head)
{
    if (head == NULL)
    {
        return true;
    }
    int length = get_length(head);

    int mid = length / 2;
    if (length % 2 != 0)
    {
        mid = mid + 1;
    }
    node *head1 = head, *head2 = head;
    while (mid--)
    {
        head2 = head2->next;
    }
    head2=reverse_LL(head2);
    node*temp1=head1;
    node*temp2=head2;
    while(temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
        {
            head2=reverse_LL(head2);
            return false;
        }
        temp2=temp2->next;
        temp1=temp1->next;
    }
    head2=reverse_LL(head2);
    print(head1);
    return true;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    insert(1, head, tail);
    insert(2, head, tail);
    insert(3, head, tail);
    insert(4, head, tail);
    insert(3, head, tail);
    insert(2, head, tail);
    insert(1, head, tail);
    print(head);

    if (check_palindrome(head))
    {
        cout << "LL is palindrome " << endl;
    }
    else
    {
        cout << "LL is not palindrome " << endl;
    }
    return 0;
}