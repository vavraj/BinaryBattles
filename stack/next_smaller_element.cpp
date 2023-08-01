#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmaller(vector<int> &arr)
{
    stack<int> s;
    vector<int> ans(arr.size());
    s.push(-1);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 6, 4, 5, 9};
    vector<int> ans;
    ans = nextSmaller(arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}