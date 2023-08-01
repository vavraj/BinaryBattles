#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextIndex(vector<int> arr, int n)
{
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);

    for (int i = n - 1; i >= 0; i--) /*{2, 1, 5, 6, 2, 3}*/
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> previousIndex(vector<int> arr, int n)
{
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestArea(vector<int> heights)
{
    int n = heights.size();
    vector<int> prev(n);
    prev = previousIndex(heights, n);
    vector<int> next(n);
    next = nextIndex(heights, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int maxrRectangleArea(vector<vector<int>> M, int n)
{
    // step1 compute area for first row
    int area = largestArea(M[0]);
    for (int i = 1; i < n; i++)
    {
        // row update by adding previous rows value
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] != 0)
                M[i][j] = M[i][j] + M[i - 1][j];
            else
                M[i][j] == 0;
        }
        // entire row is updated now
        int newArea=largestArea(M[i]);
        area =max(area,newArea);
    }
    return area;
}

int main()
{
    vector<vector<int>> heights = {{0, 1, 1, 1}, 
                                   {1, 1, 1, 1}, 
                                   {1, 1, 1, 1}, 
                                   {1, 1, 1, 0}};
    cout << maxrRectangleArea(heights,4) << endl;
    return 0;
}