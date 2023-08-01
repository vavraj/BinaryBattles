#include<iostream>
#include<vector>
using namespace std;

// void single(int ar[],int size)
// {
// for (int i=0;i<size;i++)
// {
//     int count=0;
//     for(int j=0;j<size;j++)
//     {
//         if(ar[i]==ar[j])
//         {
//             count++;
//         }
        
//     }
//     if(count==1){
//             cout<<ar[i]<<" occurs only one time!"<<endl;        
        
//     }
// }
// }


int single(vector<int> &arr)
{
    int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        ans=ans^arr[i];//  0^a=a  &&  a^a=0
    }
    return ans;
}
/*
int unique_occ(int ar[],int size)
{
    int arr_count[10];
for (int i=0;i<size;i++)
{
    int count=0;
    for(int j=0;j<size;j++)
    {
        if(ar[i]==ar[j])
        {
            count++;
        }
        
    }
    arr_count[i]=count;
}
for(int i=0;i<size;i++)
{
    int ans=0;
    ans=ans^arr_count[i];

}
return 0;
}*/
void duplicate(vector<int> &arr)
{
    int ans=0; 
    for(int i=0;i<arr.size();i++)
    {
        ans=ans^arr[i];
    }
    for(int i=1;i<arr.size();i++)
    {
        ans=ans^i;
    }
    cout<<ans;
}
int main()
{
    vector<int> ar={1,8,6,7,9,13,15,23,15,11};
    // int size=sizeof(ar)/sizeof(int);

    // unique_occ(ar,size);
    duplicate(ar);
    // cout<<a<<endl;
    
    return 0;
  }










