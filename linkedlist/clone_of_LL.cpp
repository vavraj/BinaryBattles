#include <iostream>
#include <map>
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

void print_random(node *head)
{
    int len = get_length(head);
    while (len--)
    {
        cout << head->data << " ";
        head = head->random;
    }
    cout << endl;
}

void assign_random(node *&head, int data1, int data2)
{
    node *temp1 = head;
    node *temp2 = head;
    while (temp1->data != data1)
    {
        temp1 = temp1->next;
    }
    while (temp2->data != data2)
    {
        temp2 = temp2->next;
    }
    temp1->random = temp2;
}

node *create_clone(node *head) //  TC = O(N) | SC = O(N)
{
    node *original_node = head;
    node *head_clone = NULL;
    node *tail_clone = NULL;
    map<node *, node *> ran_val;

    while (original_node != NULL)
    {
        insert(original_node->data, head_clone, tail_clone);
        original_node = original_node->next;
    }
    original_node = head;
    node *clone_node = head_clone;
    while (original_node != NULL)
    {
        ran_val[original_node] = clone_node; // ye map me clone node ko store krega
        original_node = original_node->next;
        clone_node = clone_node->next;
    }
    clone_node = head_clone;
    original_node = head;
    while (original_node != NULL)
    {
        clone_node->random = ran_val[original_node->random]; // ab yaha clone_node ka random pointer clone_node ka node ko hi point krega
        original_node = original_node->next;
        clone_node = clone_node->next;
    }

    return head_clone;
}

node *optimize_sol(node *head) //   TC = O(n)  |  SC = O(1)
{
    // step 1 create a clone list
    node *clonehead = NULL;
    node *clonetail = NULL;

    node *temp = head;
    while (temp != NULL)
    {
        insert(temp->data, clonehead, clonetail);
        temp = temp->next;
    }

    // step 2 add clonelist node in original list
    node *originalnode = head;
    node *clonenode = clonehead;
    while (originalnode != NULL)
    {
        node *forward = originalnode->next;
        originalnode->next = clonenode;
        originalnode = forward;

        forward = clonenode->next;
        clonenode->next = originalnode;
        clonenode = forward;
    }

    // step 3 point random pointer of clones
    temp = head;
    while (temp != NULL)
    {
        // if (temp->next != NULL)
        // {
        //     if (temp->random != NULL)
        //     {
                temp->next->random = temp->random->next;
        //     }
        //     else
        //     {
        //         temp->next = temp->random;
        //     }
        // }
        temp = temp->next->next;
    }

    // step 4 revert changes done in step 2
    originalnode = head;
    clonenode = clonehead;
    while (originalnode != NULL && clonenode != NULL)
    {
        originalnode->next = clonenode->next;
        originalnode = originalnode->next;

        if (originalnode != NULL)
        {
            clonenode->next = originalnode->next;
        }
        clonenode = clonenode->next;
    }

    // step 5 return ans
    return clonehead;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;

    insert(1, head, tail);
    insert(2, head, tail);
    insert(3, head, tail);
    insert(4, head, tail);
    insert(5, head, tail);

    assign_random(head, 1, 3);
    assign_random(head, 2, 1);
    assign_random(head, 3, 5);
    assign_random(head, 4, 2);
    assign_random(head, 5, 4);

    print(head);
    print_random(head);

    node *clone = optimize_sol(head);

    print(clone);
    print_random(clone);
    return 0;
}