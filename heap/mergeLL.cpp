#include <queue>
#include<vector>

using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

class compare
{
public:
    bool operator()(Node<int> *a, Node<int> *b)
    {
        return a->data > b->data;
    }
};
Node<int> *mergeKLists(vector<Node<int> *> &listArray)
{
    priority_queue<Node<int> *, vector<Node<int> *>, compare> minHeap;
    for (int i = 0; i < listArray.size(); i++)
    {
        if (listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    while (!minHeap.empty())
    {
        if (head == NULL)
        {
            head = tail = minHeap.top();
            minHeap.pop();
            if (head->next != NULL)
            {
                minHeap.push(head->next);
            }
        }
        else
        {
            tail->next = minHeap.top();
            minHeap.pop();
            tail = tail->next;
            if (tail->next != NULL)
            {
                minHeap.push(tail->next);
            }
        }
    }
    return head;
}
