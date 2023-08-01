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
    int count = 1;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    // cout<<count<<endl;
    return count;
}

node* divide(node*&head)
{
    int length=get_length(head);
    node*temp=head;
    node*head2;
    node*end1;
    int count;
    // cout<<"hi";
    if(length%2==0)
    {
        count=length/2;
    }
    else{
        count=(length/2)+1;
    }
    while(count--)
    {
        // cout<<"hi";
        end1=temp;
        temp=temp->next;
        head2=temp;
    }
    end1->next=NULL;
    node*temp2=head2;
    while(temp2->next!=head)
    {
        // cout<<"hi";
        temp2=temp2->next;
    }
    temp2->next=NULL;
    // print(head);
    // print(head2);
    return head2;
}

int main()
{
    node*head=NULL;
    node*tail=NULL;

    insert(5,head,tail);
    insert(15,head,tail);
    insert(25,head,tail);
    insert(35,head,tail);
    insert(45,head,tail);
    insert(55,head,tail);
    insert(65,head,tail);
    print(head);
    tail->next=head;
    node*head2=divide(head);
    print(head);
    print(head2);

    return 0;

}