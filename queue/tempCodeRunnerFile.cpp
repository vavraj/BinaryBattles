#include <iostream>
#include <queue>
using namespace std;

int FindSum(int *ar, int n, int k)
{
    deque<int> maxi;
    deque<int> mini;

    int sum = 0;
    // for first window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && ar[maxi.back()] <= ar[i])
            maxi.pop_back();
        while (!mini.empty() && ar[mini.back()] >= ar[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    sum += ar[maxi.front()] + ar[mini.front()];

    //for remaining windows
    for (int i = k; i < n; i++)
    {
        // removal
        while (!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        while (!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        // addition
        while (!maxi.empty() && ar[maxi.back()] <= ar[i])
            maxi.pop_back();
        while (!mini.empty() && ar[mini.back()] >= ar[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        // find sum and add it to previous ans
        sum += ar[maxi.front()] + ar[mini.front()];
    }
    
    return sum;
}
int main()
{
    int ar[] = {2, 5, -1, 7, -3, -1, -2};
    cout << FindSum(ar, 7, 4) << endl;
    return 0;
}