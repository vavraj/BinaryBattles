#include <iostream>
using namespace std;

void moves_zero_left(int ar[], int n)
{
    int nonzero_value = 0;
    for (int j = 0; j < n; j++)
    {
        if (ar[j] != 0)
        {
            swap(ar[nonzero_value], ar[j]);
            nonzero_value++;
        }
    }
}

void moves_zero_right(int ar[], int n)
{
    int zero_value = n - 1;
    for (int j = n - 1; j >= 0; j--)
    {
        if (ar[j] != 0)
        {
            swap(ar[zero_value], ar[j]);
            zero_value--;
        }
    }
}

int main()
{
    int ar[] = {2, 1, 0, 3, 0, 0, 5};
    int n = sizeof(ar) / sizeof(int);
    moves_zero_left(ar, n);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    moves_zero_right(ar, n);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}