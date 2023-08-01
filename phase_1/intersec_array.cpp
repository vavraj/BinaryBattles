#include<iostream>
#include<vector>
using namespace std;
vector<int> find_array_intersection(vector<int> &arr1,vector<int> &arr2)
{
    vector<int> ans;
    for(int i=0;i<arr1.size();i++)
    {
        int element=arr1[i];
        for(int j=0;j<arr2.size();j++)
        {
            if(element==arr2[j])
            {
                ans.push_back(element);//insert the element in vector
                arr2[j]=INT_MIN;//update the value so that it 
    //            will not get mapped with same element
                break;
            }
        }
    }
    return ans;
}
// optimized solution
vector<int> find_intersection(vector<int> &arr1,vector<int> &arr2)
{
    int i=0.,j=0;
    vector<int> ans;
    while(i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]==arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else{
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> vt1={1,2,2,2,3,4};
    vector<int> vt2={2,2,3,3};
    // vector<int> a=find_array_intersection(vt1,vt2);
    vector<int> b=find_intersection(vt1,vt2);
    
    // for(int i=0;i<a.size();i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    
    for(int i=0;i<b.size();i++)
    {
        cout<<b[i]<<" ";
    }
    
    return 0;
}