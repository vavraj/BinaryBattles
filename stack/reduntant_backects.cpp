#include <iostream>
#include <stack>
using namespace std;

bool check_brackets(string s)
{
    stack<char> stack;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            stack.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isReduntant = true;
                while (stack.top() != '(')
                {
                    char top = stack.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isReduntant = false;
                    }
                    stack.pop();
                }
                if (isReduntant == true)
                {
                    return true;
                }
                stack.pop();
            }
        }
    }
    return false;
}
int main()
{
    string s;
    cin >> s;
    if (check_brackets(s))
    {
        cout << "Contains pair of reduntant brackets" << endl;
    }
    else
    {
        cout << "No reduntant brackets present" << endl;
    }
    return 0;
}