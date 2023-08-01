#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int mid)
{
    int student_count = 1;
    int page_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (page_sum + arr[i] <= mid)
        {
            page_sum = page_sum + arr[i];
        }
        else
        {
            student_count++;
            if (student_count > m || arr[i] > mid)
            {
                return false;
            }
            page_sum=arr[i];
        }
    }
    return true;
}
int allocatebooks(vector<int> &arr, int n, int m)
{
    int s = 0;
    int sum = 0;
    int ans = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return mid;
}

int main()
{
    vector<int> vt={10,20,30,40};
    cout<< allocatebooks(vt,4,2)<<endl;   
    return 0;
}