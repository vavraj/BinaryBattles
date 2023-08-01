#include<iostream>
#include<stack>
using namespace std;

class Stack{
    private:
    stack<int>stack1;
    stack<int>stack2;
    int mini=INT_MAX;
    public:
    void push(int n)
    {
        stack1.push(n);
        mini=min(mini,n);
        stack2.push(mini);
    }
    void pop()
    {
        stack1.pop();
        stack2.pop();
    }
    int get_min()
    {
        return stack2.top();
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
    cout<<st.get_min()<<endl;
    st.pop();
    st.pop();
    cout<<st.get_min()<<endl;
    st.pop();
    cout<<st.get_min()<<endl;
    return 0;
}