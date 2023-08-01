#include<iostream>
#include<vector>
using namespace std;

// vector<int> swap0_1(vector<int> &arr)
// {
    
//     int i=0,j= arr.size()-1;
//     while(i<j)
//     {
//         if(arr[i]==1 && arr[j]==0)
//         {
//             swap(arr[i],arr[j]);
//             i++;
//             j--;
//         }
//         else if(arr[i]==0)
//         {
//             i++;
//         }
//         else{
//             j--;
//         }
//     }
//     return arr;

// }
vector<int> swap0_1_2(vector<int> &arr)
{
    vector<int> ans;   
    int i=0,j= arr.size()-1;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==2)
        {
            ans.push_back(arr[i]);
            arr[i]=-1;
        }
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==1)
        {
            ans.push_back(arr[i]);
            arr[i]=-1;
        }
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==0)
        {
            ans.push_back(arr[i]);
            arr[i]=-1;
        }
    }
    return ans;
}
int main()
{

    vector<int> vt={0,2,1,0,2,0,1,2,0,1,1,0,2};
    vector<int> vt1=swap0_1_2(vt);
    for(int i=vt.size()-1;i>=0;i--)
    {
        cout<<vt1[i]<<" ";
    }
    return 0;
}