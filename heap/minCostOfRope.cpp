#include <queue>
using namespace std;

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>>minheap;
        for(long long i=0;i<n;i++)
        {
            minheap.push(arr[i]);
        }
        long long ans=0;
        while(minheap.size()>1)
        {
            long long a=minheap.top();
            minheap.pop();
            long long b=minheap.top();
            minheap.pop();
            long long sum=a+b;
            ans=ans+sum;
            minheap.push(sum);
        }
        return ans;
    }
};