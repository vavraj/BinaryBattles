#include <iostream>
#include <vector>
using namespace std;

void solve(string s, vector<char> output, int index, vector<vector<char>> &ans)
{
    if (index >= s.length())
    {
        if (output.size() > 0)
        {
            ans.push_back(output);
        }
        return;
    }

    // exclude
    solve(s, output, index + 1, ans);
    // include
    char ch = s[index];
    output.push_back(ch);
    solve(s, output, index + 1, ans);
}
int main()
{
    vector<vector<char>> ans;
    vector<char> output;
    string s = "abc";
    int index = 0;
    solve(s, output, index, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{";
        vector<char> temp = ans[i];
        for (int j = 0; j < temp.size(); j++)
        {
            cout << temp[j] << " ";
        }
        cout << "} ";
    }
    cout << endl;
    return 0;
}