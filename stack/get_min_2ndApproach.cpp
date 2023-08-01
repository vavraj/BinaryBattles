#include <iostream>
#include <stack>
using namespace std;

class Stack
{
private:
    stack<int> stack1;
    int mini;

public:
    void push(int n)
    {
        if (stack1.empty())
        {
            stack1.push(n);
            mini = n;
            return;
        }
        int curr = n;
        if (curr < mini)
        {
            int value = 2 * curr - mini;
            stack1.push(value);
            mini = curr;
        }
        else
        {
            stack1.push(curr);
        }
    }
    void pop()
    {
        if (stack1.empty())
        {
            cout << "Stack underflow" << endl;
            return;
        }
        int curr = stack1.top();
        if (curr > mini)
        {
            stack1.pop();
        }
        else
        {
            int value = 2 * mini - curr;
            mini = value;
            stack1.pop();
        }
    }
    int top()
    {
        if(stack1.empty())
        {
            return -1;
        }

        int curr=stack1.top();
        if(curr<mini)
        {
            return mini;
        }
        else{
            return curr;
        }
    }
    int get_min()
    {
        if (stack1.empty())
            return -1;

        return mini;
    }
};
int main()
{
    Stack st;
    st.push(5);
    st.push(3);
    st.push(8);
    st.push(2);
    st.push(4);
    cout << st.get_min() << endl;
    st.pop();
    st.pop();
    cout << st.get_min() << endl;
    st.pop();
    cout << st.get_min() << endl;
    st.pop();
    cout << st.get_min() << endl;
    return 0;
}