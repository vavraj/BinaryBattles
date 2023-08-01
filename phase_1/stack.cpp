#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<string> st;
    st.push("Vaibhav");
    st.push("Raj");
    st.push("is");
    st.push("Asshole");
    cout<<"Top element: "<<st.top();
    cout<<"Size : "<<st.size();
    st.pop();
    st.pop();
    st.pop();
    cout<<"Top element: "<<st.top();
    st.pop();
    cout<<"Size : "<<st.size();
    cout<<"Empty or not: "<<st.empty();
    return 0;
}