#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findSol(vector<int> v, int k)
{
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        if (v[i] < 0)
        {
            dq.push_back(i);
        }
    }

    if (dq.size() > 0)
    {
        ans.push_back(v[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    for (int i = k; i < v.size(); i++)
    {
        // removal
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // addition
        if (v[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.size() > 0)
        {
            ans.push_back(v[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}

int main()
{
    vector<int> v;
    v.push_back(-8);
    v.push_back(2);
    v.push_back(3);
    v.push_back(-6);
    v.push_back(10);
    vector<int> ans = findSol(v, 2);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}