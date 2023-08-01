#include <iostream>
#include<vector>
using namespace std;

vector<int> print_spiral(int ar[][4], int row, int col)
{
    vector<int> ans;
    int count = 0;
    int i = 0;
    int m = row;
    int l = col;
    int startingrow = 0;
    int startingcol = 0;
    int endingrow = row - 1;
    int endingcol = col - 1;

    while (count <= row * col)
    {
        for(int i=startingcol;i<=endingcol;i++)
        {
            ans.push_back(ar[startingrow][i]);
            count++;
            if(count==row*col)
            {
                return ans;
            }
        }
        startingrow++;
        for(int i=startingrow;i<=endingrow;i++)
        {
            ans.push_back(ar[i][endingcol]);
            count++;
            if(count==row*col)
            {
                return ans;
            }
        }
        endingcol--;
        for(int i=endingcol;i>=startingcol;i--)
        {
            ans.push_back(ar[endingrow][i]);
            count++;
            if(count==row*col)
            {
                return ans;
            }
        }
        endingrow--;
        for(int i=endingrow;i>=startingrow;i--)
        {
            ans.push_back(ar[i][startingcol]);
            count++;
            if(count==row*col)
            {
                return ans;
            }
        }
        startingcol++;
    }
    return ans;
}
int main()
{
    int ar1[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ar1[i][j] << " ";
        }
        cout << endl;
    }
    vector<int>ans = print_spiral(ar1, 4, 4);
    for(auto i:ans)
    {
        cout<<i<<" "; 
    }
    return 0;
}