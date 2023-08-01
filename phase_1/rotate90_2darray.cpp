#include<iostream>
#include<vector>
using namespace std;

void rotate_90(int ar[][5],int row, int col)
{
    vector<vector<int>> ans;
    for(int i=0;i<col;i++)
    {
        vector<int> temp;
        for(int j=row-1;j>=0;j--)
        {
            temp.push_back(ar[j][i]);
        }
        ans.push_back(temp);
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int ar1[4][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,17,18,19,20};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << ar1[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    rotate_90(ar1,4,5);
    return 0;
}