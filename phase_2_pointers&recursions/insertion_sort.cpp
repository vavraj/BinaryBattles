#include <iostream>
using namespace std;

void ins_sort(int *ar, int n)
{
    // base condition
    if (n == 0 || n == 1)
        return;

    ins_sort(ar, n - 1);

    int last = ar[n - 1];
    int j = n - 2;
    while (j >= 0 && ar[j] > last)
    {
        ar[j + 1] = ar[j];
        j--;
    }
    ar[j + 1] = last;
    
}

int main()
{
    int ar[] = {45, 5, 82, 14, 03};
    ins_sort(ar, 5);
    for (int i = 0; i < 5; i++)
        cout << ar[i] << " ";
    cout << endl;

    return 0;
}