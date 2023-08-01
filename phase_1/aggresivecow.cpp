#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr, int n, int k, int mid)
{
    int cow_count=1;
    int last_pos=arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(arr[i] - last_pos>=mid);
            {
                cow_count++;
                if(cow_count==k)
                {
                    return true;
                }
                last_pos=arr[i];
            }
            
        }
    }
    return false;
}

int agg_cow(vector<int> &stalls, int n, int k)
{
    sort(stalls.begin(),stalls.end());
    int s = 0;
    int ans = -1;
    // int maxi = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     maxi = max(stalls[i], maxi);
    // }
    int e = stalls[n-1]-stalls[0];
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossible(stalls, n, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> vt = {4, 2, 1, 3, 6};
    cout << agg_cow(vt, 5, 2) << endl;
    return 0;
}
