#include <iostream>
using namespace std;

void get_sum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    cout << "Sum: " << sum << endl;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; //*(arr+i)
    }
    get_sum(arr, n);
    return 0;
}