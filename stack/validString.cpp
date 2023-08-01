#include <iostream>
#include <stack>
using namespace std;

int validString(string str)
{
    if (str.length() % 2 != 0)
        return -1;
    stack<char> temp;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
        {
            temp.push(str[i]);
        }
        else
        {
            if (!temp.empty() && temp.top() == '{' )
            {
                temp.pop();
            }
            else
            {
                temp.push(str[i]);
            }
        }
    }
    int a=0,b=0;
    while(!temp.empty())
    {
        if(temp.top()=='{')   
        a++;
        else
        b++;

        temp.pop();
    }
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << validString(s) << endl;

    return 0;
}