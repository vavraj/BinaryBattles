#include <iostream>
#include <vector>
using namespace std;
void pivot_search(int arr[],int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + ((end - start) / 2);
    while (start < end)
    {
        if (arr[mid] >= arr[mid+1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + ((end - start) / 2);
    }
    cout<<"Pivot at "<<start;
    
}
int main()
{
    int ar[] = {3, 8, 10, 17, 1};
    pivot_search(ar,5);
    return 0;
}
