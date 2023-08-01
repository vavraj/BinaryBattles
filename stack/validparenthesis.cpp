#include <iostream>
#include <stack>
using namespace std;

bool validParenthesis(string s)
{
    stack<char> temp;
    for(int i=0;i < s.length();i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            temp.push(s[i]);
        }
        else
        {
            if (!temp.empty())
            {
                if (s[i] == ')' && temp.top() == '(' || s[i] == '}' && temp.top() == '{' || s[i] == ']' && temp.top() == '[')
                {
                    temp.pop();
                }
            }
        }
    }
    if (temp.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string s;
    cin >> s;
    if (validParenthesis(s)==1)
    {
        cout << "Valid expression" << endl;
    }
    else
    {
        cout << "Not valid expression" << endl;
    }

    return 0;
}