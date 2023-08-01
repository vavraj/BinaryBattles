#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    class Node
    {
    public:
        int data;
        int row;
        int col;
        Node(int data, int row, int col)
        {
            this->data = data;
            this->row = row;
            this->col = col;
        }
    };
    class compare
    {
    public:
        bool operator()(Node *a, Node *b)
        {
            return a->data > b->data;
        }
    };

    
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<Node *, vector<Node *>, compare> minheap;

        int mini = INT_MAX;
        int maxi = INT_MIN;
        // create minheap for first element of each lists
        for (int i = 0; i < nums.size(); i++)
        {
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            minheap.push(new Node(nums[i][0], i, 0));
        }
        int start = mini, end = maxi;

        while (!minheap.empty())
        {
            Node *temp = minheap.top();
            minheap.pop();
            mini = temp->data;

            // updating answer
            if (maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }

            // updating max and push new value if exists
            if (temp->col + 1 < nums[temp->row].size())
            {
                maxi = max(nums[temp->row][temp->col + 1], maxi);
                minheap.push(new Node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));
            }
            else
            {//next element does not exists
                break;
            }
        }
        vector<int> v;
        v.push_back(start);
        v.push_back(end);
        return v;
        // or return end-start+1;
    }
};