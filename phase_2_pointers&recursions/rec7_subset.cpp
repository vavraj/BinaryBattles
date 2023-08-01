#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base condition
    if (index >= nums.size()) // it will run 8 times
    {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(nums, output, index + 1, ans);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);
}
int main()
{
    vector<vector<int>> ans;
    vector<int> output;
    vector<int> nums = {1, 2, 3};
    int index = 0;
    solve(nums, output, index, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<"{";
        vector<int> temp = ans[i];
        for (int j = 0; j < temp.size(); j++)
        {
            cout << temp[j]<<" " ;
        }
        cout<<"} ";
    }
    cout << endl ;
    return 0;
}