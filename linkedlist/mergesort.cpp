#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *random;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *find_mid(node *head)
{
    node *fast = head->next;
    node *slow = head;

    while (fast != NULL )
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

node *merge(node *left, node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    node *ans = new node(-1);
    node *tail = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data >= right->data)
        {
            tail->next = right;
            tail = right;
            right = right->next;
        }
        else
        {
            tail->next = left;
            tail = left;
            left = left->next;
        }
    }
    while (left != NULL)
    {
        tail->next = left;
        tail = left;
        left = left->next;
    }
    while (right != NULL)
    {
        tail->next = right;
        tail = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

node *mergesort(node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // break link list into two halves after finding mid
    node *mid = find_mid(head);

    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    // recursive call to sort both halves
    left = mergesort(left);
    right = mergesort(right);

    // return answer
    node *result = merge(left, right);
    return result;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    insert(25, head, tail);
    insert(15, head, tail);
    insert(75, head, tail);
    insert(55, head, tail);
    insert(35, head, tail);

    print(head);
    node *ans = mergesort(head);
    print(ans);
    return 0;
}