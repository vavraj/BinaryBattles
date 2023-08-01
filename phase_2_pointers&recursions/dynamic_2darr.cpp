#include <iostream>
using namespace std;

int main()
{
    int row, col;
    cout << "enter row and columns: ";
    cin >> row >> col;
    int **arr = new int *[row];

// creating 2D-array using dynamic memorry allocation
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }


// taking input

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j] ;
        }
    }
// printing array

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] <<" ";
        }
        cout<<endl;
    }

// deleting the memory

    // deleting columns
    for (int i = 0; i < row; i++)
    {
        delete []arr[i];
    }
    // deleting rows
    delete []arr;

    return 0;
}