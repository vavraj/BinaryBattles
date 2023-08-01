#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums,int index,vector<vector<int>>&ans)
{
    // base condition
    if(index>=nums.size())
    {
        ans.push_back(nums);
    }

    for(int j=index;j<nums.size();j++)
    {
        swap(nums[index],nums[j]);
        // 1st iteration-->swap(nums[0],nums[0])
        // 2nd iteration-->swap(nums[0],nums[1])
        // 3rd iteration-->swap(nums[0],nums[2])

        solve(nums,index+1,ans); //isme index ka value change nii ho rha balki wo next function call ke liye increase ho rha hai

        swap(nums[index],nums[j]); // backtracking
    }
}
int main()
{
    vector<vector<int>> ans;
    int index=0;
    vector<int> nums={1,2,3};
    solve(nums,index,ans);
    for(int i=0;i<ans.size();i++)
    {
        cout<<"{";
        vector<int> temp=ans[i];
        for(int j=0;j<temp.size();j++)
        {
            cout<<temp[j]<<" ";
        }
        cout<<"},";
    }
    return 0;
}