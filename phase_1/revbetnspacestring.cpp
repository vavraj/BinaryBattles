#include <iostream>

using namespace std;

void rev(string &s)
{
    int start = 0;

    for (int i = 0; i < s.length() + 1; i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            int end = i - 1;
            while (start < end)
            {
                swap(s[start++], s[end--]);
            }
            start = i + 1;
        }
    }

    cout << s << endl;
}
int main()
{
    string s;
    cout << "enter string: ";
    getline(cin, s);
    cout << s << endl;
    rev(s);
    cout<<s<<endl;
    return 0;
}