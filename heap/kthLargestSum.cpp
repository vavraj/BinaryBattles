#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int kthLargest(vector<int> &Arr, int N, int K)
    {
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i; j < N; j++)
            {
                sum += Arr[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());
        return v[v.size() - K];
    }

    // using minheap
    int kthLargest(vector<int> &Arr, int N, int K)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i; j < N; j++)
            {
                sum += Arr[j];
                if (count < K)
                {
                    pq.push(sum);
                    count++;
                }
                else if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        return pq.top();
    }
};