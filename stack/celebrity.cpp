#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
int findCelebrity(int ar[][4])
{
    int r = 4;
    int c = 4;
    bool a = false;
    bool b = false;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i != j)
            {
                if (ar[j][i] == 1)
                {
                    a = true;
                }
                else
                {
                    a = false;
                    break;
                }
            }
        }
        for (int j = 0; j < c; j++)
        {
            if (i != j)
            {
                if (ar[i][j] == 0)
                {
                    b = true;
                }
                else
                {
                    b = false;
                    break;
                }
            }
        }
        if (a == true && b == true)
            return i;
    }
    return -1;
}
*/

// Optimize solution

bool knows(vector<vector<int>> M, int a, int b, int n)
{
    if (M[a][b] == 1)
        return true;
    else
        return false;
}

int using_stack(vector<vector<int>> M, int n) // TC = O(n)
{
    stack<int> s;
    // step1 pushing all elements int the stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    // step2 popping two elements and checking whether who knws who
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (knows(M, a, b, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    // step3 check if the element int the stack is a celebrity element or not
    int ans = s.top();
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 0)
            count1++;
    }
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] == 1)
            count2++;
    }

    if (count1 != n)
        return -1;

    if (count2 != n - 1)
        return -1;

    return ans;
}
int main()
{
    vector<vector<int>> ar = {{0, 1, 1, 1}, {1, 0, 1, 1}, {0, 1, 0, 1}, {0, 0, 0, 0}};
    // cout << findCelebrity(ar) << endl;
    cout << using_stack(ar, 4) << endl;
    return 0;
}