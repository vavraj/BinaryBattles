#include <iostream>
#include <vector>
using namespace std;
vector<int> add_array(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> ans;
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int sum = arr1[i] + arr2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while (i >= 0)
    {
        int sum = carry + arr1[i];
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while (j >= 0)
    {
        int sum = carry + arr2[j];
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(carry);
    }
    return ans;
}
int main()
{
    vector<int> v1 = {3, 2, 4, 6};
    vector<int> v2 = {1, 2, 4, 9, 9, 9, 6};
    vector<int> ans = add_array(v1, v2);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}