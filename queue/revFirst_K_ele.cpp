#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void revFirstKelement(queue<int> &q, int k)
{
    stack<int> temp;

    // step1 detch first k element
    for (int i = 0; i < k; i++)
    {
        temp.push(q.front());
        q.pop();
    }

    // reverse first k element and pushback in the same queue
    while (!temp.empty())
    {
        q.push(temp.top());
        temp.pop();
    }

    // fetch first n-k element and pushback in the queue
    int t = q.size() - k; //(n-k)
    while (t--)
    {
        q.push(q.front());
        q.pop();
    }
}

void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    print(q);
    revFirstKelement(q, 4);
    print(q);
    return 0;
}