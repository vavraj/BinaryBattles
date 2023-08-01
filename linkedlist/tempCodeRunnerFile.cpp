#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *child;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
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
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_whole(node *head)
{
    node *temp = head;
    node *ans = new node(-1);
    while (temp != NULL)
    {
        node *temp1 = temp;
        while (temp1 != NULL)
        {
            cout << temp1->data << " ";
            temp1 = temp1->child;
        }
        temp = temp->next;
    }
    cout << endl;
}

void insert_child(int data1, int data2, node *&head)
{
    node *temp = head;
    while (temp->data != data1)
    {
        temp = temp->next;
    }
    while (temp->child != NULL)
    {
        temp = temp->child;
    }
    node *childnode = new node(data2);
    temp->child = childnode;
}

node *merge(node *a, node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    node *result = new node(-1);
    node *tail = result;
    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        {
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    while (a!=NULL)
    {
        tail->next=a;
        tail=a;
        a=a->next;
    }
    while (b!=NULL)
    {
        tail->next=b;
        tail=b;
        b=b->next;
    }
    

    return result->next;
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
node *sort(node *head)
{
    if(head==NULL || head->next==NULL )
    return head;

    node *mid = find_mid(head);
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    left = sort(left);
    right = sort(right);

    node *ans = merge(left, right);
    return ans;
}

node *flatten(node *head)
{
    node *temp = head;
    node *ans = new node(-1);
    node *tail = ans;
    while (temp != NULL)
    {
        node *temp1 = temp;
        while (temp1 != NULL)
        {
            node*newnode=new node(temp1->data);
            tail->next = newnode;
            tail = newnode;
            temp1 = temp1->child;
        }
        temp = temp->next;
    }
    return ans->next;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    insert(100, head, tail);
    insert(200, head, tail);
    insert(300, head, tail);
    insert(400, head, tail);
    // print(head);
    insert_child(200, 270, head);
    insert_child(300, 350, head);
    insert_child(100, 130, head);
    insert_child(300, 320, head);
    insert_child(200, 210, head);
    insert_child(300, 370, head);
    insert_child(300, 330, head);
    insert_child(100, 110, head);
    insert_child(400, 450, head);
    insert_child(200, 240, head);
    insert_child(100, 160, head);
    insert_child(200, 240, head);
    insert_child(400, 480, head);

    // print_whole(head);

    node *ans = flatten(head);
    print(ans);
    ans=sort(ans);
    print(ans);

    return 0;
}