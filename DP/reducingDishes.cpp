#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// using recursion
class Solution
{
public:
    int solve(vector<int> &satisfaction, int i, int time)
    {
        if (i == satisfaction.size())
        {
            return 0;
        }

        int include = ((time + 1) * satisfaction[i]) + solve(satisfaction, i + 1, time + 1);
        int exclude = 0 + solve(satisfaction, i + 1, time);

        int ans = max(include, exclude);
        return ans;
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 0);
    }
};

// recursion+memoization
class Solution
{
public:
    int solve(vector<int> &satisfaction, int i, int time, vector<vector<int>> &dp)
    {
        if (i == satisfaction.size())
        {
            return 0;
        }
        if (dp[i][time] != -1)
            return dp[i][time];

        int include = ((time + 1) * satisfaction[i]) + solve(satisfaction, i + 1, time + 1, dp);
        int exclude = 0 + solve(satisfaction, i + 1, time, dp);

        dp[i][time] = max(include, exclude);
        return dp[i][time];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {

        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> dp(satisfaction.size() + 1, vector<int>(satisfaction.size() + 1, -1));
        return solve(satisfaction, 0, 0, dp);
    }
};

// tabulation
class Solution
{
public:
    int solveTab(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = ((time + 1) * satisfaction[index]) + dp[index + 1][time + 1];
                int exclude = 0 + dp[index + 1][time];

                dp[index][time] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {

        sort(satisfaction.begin(), satisfaction.end());

        return solveTab(satisfaction);
    }
};

// space optimization

class Solution
{
public:
    int solveTab(vector<int> &satisfaction)
    {
        int n = satisfaction.size();

        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = ((time + 1) * satisfaction[index]) + next[time + 1];
                int exclude = 0 + next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }

        return curr[0];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {

        sort(satisfaction.begin(), satisfaction.end());

        return solveTab(satisfaction);
    }
};
int main()
{

    Solution s1;
    vector<int> v;
    v.push_back(-1);
    v.push_back(-8);
    v.push_back(0);
    v.push_back(5);
    v.push_back(-7);
    cout << s1.maxSatisfaction(v);
    return 0;
}