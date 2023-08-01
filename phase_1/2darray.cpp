#include<iostream>
using namespace std;

bool ispresent(int ar[][4], int target, int row, int col)
{
    for(int i=0;i<3;i++)
    {
    for(int j=0;j<3;j++)
    {
        if(ar[i][j]==target)
        return 1;
    }

    }
    return 0;
}
int main()
{
    int ar2[3][4]={{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};
    // int i=0;
    // while(i<4)
    // {
    //     int j=0;
    //     while(j<3)
    //     {
    //         cout<<ar1[j][i]<<" ";
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }
    // i=0;
    // cout<<endl;
    // while(i<3)
    // {
    //     int j=0;
    //     while(j<4)
    //     {
    //         cout<<ar2[i][j]<<" ";
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }
    // cout<<endl;
    int ar1[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<ar1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<ar2[i][j]<<" ";
        }
        cout<<endl;
    }
    int target;
    cout<<"Enter number to be searched: ";    
    cin>>target;
    cout<<"present or not "<<ispresent(ar1,target,3,4);
    cout<<endl;
    return 0;
}