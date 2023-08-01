#include<iostream>
#include<stack>
using namespace std;


int main()
{
    string s;
    cout<<"Enter a string to be reversed:";
    cin>>s;
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        st.push(s[i]);
    }
    string ans="";
    while (!st.empty())
    {
        char ch=st.top();
        ans.push_back(ch);
        st.pop();
    }
    cout<<"Reversed string is: "<<ans<<endl;
    
    return 0;
}