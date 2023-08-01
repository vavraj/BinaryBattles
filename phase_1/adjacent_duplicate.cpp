#include <iostream>
using namespace std;

// in this approach loops always starts from zero which increases its time complexity
string remove_duplicate(string s)
{
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == s[i + 1])
        {
            s.erase(i, 2);
            // s = temp;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    return s;
}

// different approach
string diff_approach(string s)
{
    string ans;
    int i = 1;
    ans.push_back(s[0]);
    while (i < s.length())
    {
        if (ans.empty() == 0)
        {
            if (ans.back() == s[i])
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        else
        {
            ans.push_back(s[i]);
        }
        i++;
    }
    return ans;
}
int main()
{
    string s;
    getline(cin, s);
    cout << remove_duplicate(s) << endl;
    cout << diff_approach(s) << endl;
    return 0;
}
