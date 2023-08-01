#include<iostream>
#include<vector>
using namespace std;


void addSolution(vector<vector<int> > &board, vector<vector<int> > &ans, int n)
{
    vector<int> temp;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            temp.push_back(board[row][col]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int> > &board, int n)
{
    int x = row;
    int y = col;
    while (y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
    }

    x = row;
    y = col;
    while (y >= 0 && x >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
        x--;
    }
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
        x++;
    }
    return true;
}

void solve(int col, vector<vector<int> > &board, vector<vector<int> > &ans,
           int n)
{
    // base case
    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }
    // recursive condition
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // if placing queen is safe
            board[row][col] = 1;
            solve(col + 1, board, ans, n);
            // backtracking
            board[row][col] = 0;
        }
    }
}
vector<vector<int> > solveNQueens(int n)
{
    // Write your code here.
    vector<vector<int> > board(n, vector<int>(n, 0));
    vector<vector<int> > ans;
    solve(0, board, ans, n);
    return ans;
}

int main()
{
    vector<vector<int> >ans=solveNQueens(5);
    for(auto i: ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}