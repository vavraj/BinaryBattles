#include <iostream>
using namespace std;
void row_sum(int ar[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += ar[i][j];
        }
        cout << "Sum of row " << i + 1 << " is " << sum << endl;
    }
    cout << endl;
}
void col_sum(int ar[][4], int row, int col)
{
    if ((row==0 && col==0))
    {
        return;
    }
    
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += ar[j][i];
        }
        cout << "Sum of col " << i + 1 << " is " << sum << endl;
    }
    cout << endl;
}
void total_sum(int ar[][4], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            sum += ar[j][i];
        }
    }
    cout << "Total sum is " << sum << endl;
    cout << endl;
}
void largest_row_sum(int ar[][4], int row, int col)
{
    int largest_sum = INT16_MIN;
    int maxi = -1;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += ar[i][j];
        }
        if (sum > largest_sum)
        {
            largest_sum = sum;
            maxi = i;
        }
    }
    cout << "Largest sum is " << largest_sum << " of index " << maxi << endl;
    cout << endl;
}

// column-wise wave order
void print_wave_order1(int ar[][4], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < row; j++)
            {
                cout << ar[j][i] << " ";
            }
        }
        else
        {
            for (int j = row - 1; j >= 0; j--)
            {
                cout << ar[j][i] << " ";
            }
        }
    }
    cout << endl;
}

// row-wise wave order
void print_wave_order2(int ar[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < col; j++)
            {
                cout << ar[i][j] << " ";
            }
        }
        else
        {
            for (int j = col - 1; j >= 0; j--)
            {
                cout << ar[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int main()
{
    int ar1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ar1[i][j] << " ";
        }
        cout << endl;
    }
    row_sum(ar1, 3, 4);
    largest_row_sum(ar1, 3, 4);
    col_sum(ar1, 3, 4);
    total_sum(ar1, 3, 4);
    print_wave_order1(ar1, 3, 4);
    print_wave_order2(ar1, 3, 4);
    return 0;
}