#include <iostream>
#include <vector>
using namespace std;


int binary_search(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else // if (arr[mid] > arr[mid + 1])
        {
            end = mid; //- 1;
        }
    }
    return start;
}
int main()
{
    vector<int> vt = {10, 20, 30, 40, 50, 112, 200, 100, 70, 50, 1};
    cout << "Peak at index " << binary_search(vt) << endl;
    return 0;
}