#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<string> st;
    st.push("Vaibhav");
    st.push("Raj");
    st.push("is");
    st.push("Asshole");
    cout<<"first element: "<<st.front();
    cout<<"Size : "<<st.size();
    st.pop();
    st.pop();
    st.pop();
    cout<<"Top element: "<<st.front();
    st.pop();
    cout<<"Size : "<<st.size();
    cout<<"Empty or not: "<<st.empty();
    return 0;
}