#include <iostream>
#include <vector>
using namespace std;

void binary_search(vector<int> &arr, int key, int start, int end)
{
    // int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            cout << "found at " << mid << " index!" << endl;
            break;
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
int pivot_search(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}
void find_pos(vector<int> &ar, int key)
{
    int pivot = pivot_search(ar);
    if (key > ar[pivot] && key <= ar[ar.size() - 1])
    {
        binary_search(ar, key, pivot, ar.size() - 1);
    }
    else if (key == ar[pivot])
    {
        cout << "found at " << pivot << " index!" << endl;
    }
    else
    {
        binary_search(ar, key, 0, pivot - 1);
    }
}

int main()
{
    vector<int> ar = {3, 8, 10, 17, 18, 1};
    // pivot_search(ar);
    find_pos(ar, 8);
    find_pos(ar, 1);
    find_pos(ar, 17);

    return 0;
}
