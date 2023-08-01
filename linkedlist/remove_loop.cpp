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

bool detect_loop(node *head)
{
    if (head == NULL)
        return false;

    map<node *, bool> visited;//S.C->O(n)

    node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

node* start_Node_of_loop(node *head)
{
    if (head == NULL)
        return NULL;

    map<node *, bool> visited;//S.C->O(n)

    node *temp = head;
    while (temp != NULL )
    {
        if (visited[temp] == true)
        {
            return temp;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return NULL;
}

void insert_circ(node *&tail, int element, int data)
{

    // if list is empty
    if (tail == NULL)
    {
        node *newnode = new node(data);
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        //  non-empty list
        // assuming that element is already present in the list
        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        node *temp = new node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

node *floyd_algo(node *head)//S.C->O(1)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *slow = head, *fast = head;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow = slow->next;
        if (fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}

node*starting_node(node*head)
{

    if(head==NULL)
    {
        return NULL;
    }

    node*fast=head;
    node*slow=head;
    while(fast!=NULL && slow!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if(fast==slow)
        {
            slow=head;
            break;
        }
    }
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;

}

node*remove_loop(node*&head)
{

    node*startofloop=starting_node(head);
    node*temp=startofloop;

    while(temp->next!=startofloop)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    cout<<"Loop is removed "<<endl;
    return temp;

}

int main()
{
    node *head = NULL, *tail = NULL;
    node *tailC = NULL;
    insert(10, head, tail);
    insert(20, head, tail);
    insert(30, head, tail);
    insert(40, head, tail);
    insert(50, head, tail);
    
    tail->next=head->next->next;
    // print(head);
    
    /*
    if (floyd_algo(head) == NULL)
    {
        cout << "Loop not present "<<endl;
    }
    else
    {
        // returns the part of the loop but not the starting of the loop
        cout << "Loop present at: " << floyd_algo(head)->data << endl;
    }
    */
    /*
    if (start_Node_of_loop(head) == NULL)
    {
        cout << "Loop not present "<<endl;
    }
    else
    {
        // returns the part of the loop but not the starting of the loop
        cout << "Loop starts at: " << start_Node_of_loop(head)->data << endl;
    }
    */
    // cout << detect_loop(head) << endl;

    if (starting_node(head) == NULL)
    {
        cout << "Loop not present "<<endl;
    }
    else
    {
        // returns the part of the loop but not the starting of the loop
        cout << "Loop starts at: " << starting_node(head)->data << endl;
    }
    

    insert_circ(tailC, 0, 5);
    insert_circ(tailC, 5, 15);
    insert_circ(tailC, 15, 8);
    insert_circ(tailC, 5, 30);
    insert_circ(tailC, 8, 10);
    // tailC->next=NULL;
    
    /*
    if (floyd_algo(tailC) == NULL)
    {
        cout << "Loop not present "<<endl;
    }
    else
    {
        cout << "Loop present and element " << floyd_algo(tailC)->data <<" lies inside loop " <<endl;
    }
    */
    
    if (start_Node_of_loop(tailC) == NULL)
    {
        cout << "Loop not present "<<endl;
    }
    else
    {
        cout << "Loop starts at " << start_Node_of_loop(tailC)->data<<endl;
    }

    remove_loop(head);
    // ans->next=NULL;
    

    print(head);
 
    // cout << detect_loop(tailC) << endl;
    return 0;
}