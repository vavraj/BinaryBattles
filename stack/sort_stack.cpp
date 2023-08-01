#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &s, int num)
{
    // cout << "hi";
    // base condition
    if ( s.empty() || (s.top() < num && !s.empty()) )
    {
        // cout << "AA";
        s.push(num);
        return;
    }
    // cout << "aa";

    int n = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(n);
}

void sortStack(stack<int> &s)
{
    // cout << "H ";
    // base condition
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, num);
}

void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    print(s);
    sortStack(s);
    print(s);
    return 0;
}