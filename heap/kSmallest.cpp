#include<iostream>
#include<queue>

using namespace std;
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
      
        priority_queue<int>heap;
        for(int i=0;i<k;i++)
        {
            heap.push(arr[i]);
        }
        for(int i=k;i<=r;i++)
        {
            if(arr[i]<heap.top())
            {
                heap.pop();
                heap.push(arr[i]);
            }
        }
        return heap.top();
    }
};