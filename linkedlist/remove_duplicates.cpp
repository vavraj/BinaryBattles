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
        cout << "Duplicate with value " << value << " is deleted " << endl;
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
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// if LL is sorted
void remove_duplicates(node *&head) // TC=O(n)  SC=O(1)
{
    if (head == NULL)
        return;

    node *prev = head;
    node *curr = head->next;
    // int length = get_length(head) - 1;
    while (curr != NULL)
    {
        if (prev->data == curr->data)
        {
            node *temp = curr;
            curr = curr->next;
            prev->next = curr;
            delete temp;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    }

    // if (curr!= NULL)
    // {
    //     tail = curr;
    // }
    // else{
    //     tail=prev;
    // }
}

// if LL is not sorted using map
void remove_dupl_UL(node *&head) // TC->O(n) SC->O(n)
{
    if (head == NULL)
        return;

    map<int, bool> visited;
    node *curr = head;
    node *prev;
    while (curr != NULL)
    {
        if (visited[curr->data] == true)
        { // this condition will always be false for first iteration
            node *temp = curr;
            curr = curr->next;
            prev->next = curr;
            delete temp;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}
// using for loop for unsorted list
void remove_usingloop(node *&head)//TC->O(n^2)
{
    for (node *i = head; i != NULL; i = i->next)
    {
        node *prev=i;
        for (node *j = i->next; j != NULL;)
        {
            if (i->data == j->data)
            {
                node *temp = j;
                prev->next = j->next;
                j = j->next;
                delete temp;
            }
            else
            {
                prev=j;
                j = j->next;
            }
        }
    }
}

int main()
{
    node *head = NULL, *tail = NULL;
    insert(2, head, tail);
    insert(2, head, tail);
    insert(10, head, tail);
    insert(5, head, tail);
    insert(9, head, tail);
    insert(7, head, tail);
    insert(10, head, tail);
    insert(2, head, tail);
    insert(7, head, tail);
    insert(9, head, tail);
    insert(9, head, tail);

    print(head);
    // remove_duplicates(head);
    // remove_dupl_UL(head);
    remove_usingloop(head);
    print(head);
    return 0;
}