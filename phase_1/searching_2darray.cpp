#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>> ar1, int target)
{
    int row = ar1.size();
    int col = ar1[0].size();

    int rowindex = 0;
    int colindex = col - 1;

    while (rowindex < row && colindex >= 0)
    {
        if (ar1[rowindex][colindex] == target)
        {
            return 1;
        }
        else if (ar1[rowindex][colindex] < target)
        {
            rowindex++;
        }
        else
        {
            colindex--;
        }
    }
    return 0;
}

bool search1(vector<vector<int>> ar1, int target)
{
    int row = ar1.size();
    int col = ar1[0].size();

    int rowindex = row - 1;
    int colindex = 0;

    while (rowindex >= 0 && colindex < col)
    {
        if (ar1[rowindex][colindex] == target)
        {
            return 1;
        }
        else if (ar1[rowindex][colindex] < target)
        {
            colindex++;
        }
        else
        {
            rowindex--;
        }
    }
    return 0;
}

// sorted in row wise(left to right) and in column wise(top to bottom)
int main()
{
    vector<vector<int>> ar1;
    for (int i = 0; i < 3; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 4; j++)
        {
            int n;
            cout << "enter number: ";
            cin >> n;
            temp.push_back(n);
        }
        ar1.push_back(temp);
    }
    int target;
    cout << "Enter no to be searched: ";
    cin >> target;
    cout << endl;
    cout << "Element found status: " << search(ar1, target) << endl;
    cout << "Element found status: " << search1(ar1, target) << endl;
    return 0;
}