#include <iostream>
#include <vector>
using namespace std;

/*vector<int> linear_search(vector<int> &arr, int key)
{
    vector<int> ans;
    int i = 0;
    int start = 0;
    while (i < arr.size())
    {
        if (arr[i] == key)
        {
            ans.push_back(i);
            // start = i;
            break;
        }
        else if (i == arr.size() - 1 && arr[i] != key)
        {
            ans.push_back(-1);
        }
        i++;
    }
    while (i < arr.size())
    {
        if (arr[i] != key)
        {
            ans.push_back(i - 1);
            break;
        }
        else if (i == arr.size() - 1 && arr[i] == key)
        {
            ans.push_back(i);
        }
        i++;
    }

    return ans;
}*/

// USING BINARY SEARCH

int first_occ(vector<int> &arr, int key)
{
    int ans = 0, start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
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
    return ans;
}
int last_occ(vector<int> &arr, int key)
{
    int ans = 0, start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
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
    return ans;
}
pair<int, int> first_and_last(vector<int> &arr, int key)
{
    pair<int, int> p;
    p.first = first_occ(arr, key);
    p.second = last_occ(arr, key);
    return p;
}
int count(vector<int> &arr, int key)
{
    pair<int, int> p = first_and_last(arr, key);
    return p.second - p.first + 1;
}
int main()
{
    vector<int> vt = {0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 5, 5, 5, 5};
    int n;
    cout << "Enter number :: ";
    cin >> n;
    // vector<int> ans = linear_search(vt, n);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << "First occurence is at index " << first_occ(vt, n) << endl;
    // cout << "Last occurence is at index " << last_occ(vt, n) << endl;
    pair<int, int> p = first_and_last(vt, n);
    cout << p.first << " " << p.second << endl;
    cout << "total no. of occurunce: " << count(vt, n) << endl;
    return 0;
}