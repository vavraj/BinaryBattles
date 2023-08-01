// Replace space with @40

#include <iostream>
using namespace std;

string change(string s)
{
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
        }
        else
        {
            ans.push_back(s[i]);
        }
    }
 s = ans;
    cout << s.length() << endl;
    return s;
}
    /*
        if (s[i] == ' ')
        {
            int start = i + 2;
            int end = s.length()+2;
            while (start < end)
            {
                char temp = s[end-2];
                s[end] = temp;
                end--;
            }
            s[i]='@';
            s[i+1]='4';
            s[i+2]='0';
        }
    */
   

int main()
{
    cout << "Enter a string: ";
    string s;
    getline(cin, s);
    cout << s.length() << endl;
    cout << "After change" << change(s) << endl;
    return 0;
}