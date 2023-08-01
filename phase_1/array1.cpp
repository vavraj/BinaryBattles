#include <iostream>
#include<math.h>
using namespace std;

int maxe(int ar[], int size)
{
    int maxi = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        // if(ar[i]>max)
        // {
        //     max=ar[i];
        // }
        int maxi = max(maxi, ar[i]);
    }
    return maxi;
}

int min(int ar[], int size)
{
    int mini = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        // if (ar[i] < min)
        // {
        //     min = ar[i];
        // }
        mini=min(mini,ar[i]);
    }
    return mini;
}
int main()
{
    int ar[10];
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> ar[i];
    }
    int min_ele = min(ar, size);
    cout << "Minimum Element: " << min_ele << endl;
    int max_ele = maxe(ar, size);
    cout << "Maximum Element: " << max_ele << endl;
    return 0;
}