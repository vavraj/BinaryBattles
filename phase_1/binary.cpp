#include <iostream>
#include <vector>
using namespace std;

void binary_search(vector<int> &arr, int key)
{
    int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            cout << "found at " << mid + 1 << " position!" << endl;
            exit(1);
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
    }
    if (start > end)
    {
        cout << "not found! " << endl;
    }
}
int main()
{
    vector<int> vt = {10, 20, 30, 40, 50, 60, 65, 70, 90};
    int n;
    cout << "Enter a number to be searched:: ";
    cin >> n;
    binary_search(vt, n);
    return 0;
}