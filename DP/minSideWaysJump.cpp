#include <vector>
#include <iostream>

using namespace std;
/*
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.


*/

// using recursion

class Solution
{
public:
    int solve(vector<int> &obstacles, int Currpos, int Currlane)
    {
        int n = obstacles.size() - 1;
        if (Currpos == n)
            return 0;

        if (obstacles[Currpos + 1] != Currlane)
        {
            return solve(obstacles, Currpos + 1, Currlane);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (Currlane != i && obstacles[Currpos] != i)
                {
                    ans = min(ans, 1 + solve(obstacles, Currpos, i));
                }
            }
            return ans;
        }
    }
    int minSideJumps(vector<int> &obstacles)
    {
        return solve(obstacles, 0, 2);
    }
};

// top-down
class Solution
{
public:
    int solveMem(vector<int> &obstacles, int Currpos, int Currlane, vector<vector<int>> &dp)
    {
        int n = obstacles.size() - 1;
        if (Currpos == n)
            return 0;
        if (dp[Currlane][Currpos] != -1)
            return dp[Currlane][Currpos];

        if (obstacles[Currpos + 1] != Currlane)
        {
            return solveMem(obstacles, Currpos + 1, Currlane, dp);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (Currlane != i && obstacles[Currpos] != i)
                {
                    ans = min(ans, 1 + solveMem(obstacles, Currpos, i, dp));
                }
            }
            dp[Currlane][Currpos] = ans;
            return dp[Currlane][Currpos];
        }
    }
    int minSideJumps(vector<int> &obstacles)
    {
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));

        return solveMem(obstacles, 0, 2, dp);
    }
};

// bottom up approach

class Solution
{
public:
    int solveTab(vector<int> &obstacles, vector<vector<int>> &dp)
    {

        int n = obstacles.size() - 1;
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int Currpos = n - 1; Currpos >= 0; Currpos--)
        {
            for (int Currlane = 1; Currlane <= 3; Currlane++)
            {
                if (obstacles[Currpos + 1] != Currlane)
                {
                    dp[Currlane][Currpos] = dp[Currlane][Currpos + 1];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (Currlane != i && obstacles[Currpos] != i)
                        {
                            ans = min(ans, 1 + dp[i][Currpos + 1]);
                        }
                    }
                    dp[Currlane][Currpos] = ans;
                }
            }
        }
        return min(dp[2][0], min(dp[1][0] + 1, dp[3][0] + 1));
    }
    int minSideJumps(vector<int> &obstacles)
    {
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), INT_MAX));

        return solveTab(obstacles, dp);
    }
};


// Space optimization

class Solution
{
public:
    int solveTab(vector<int> &obstacles)
    {
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, 0);
        int n = obstacles.size() - 1;
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for (int Currpos = n - 1; Currpos >= 0; Currpos--)
        {
            for (int Currlane = 1; Currlane <= 3; Currlane++)
            {
                if (obstacles[Currpos + 1] != Currlane)
                {
                    curr[Currlane] = next[Currlane];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (Currlane != i && obstacles[Currpos] != i)
                        {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[Currlane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(next[1] + 1, next[3] + 1));
    }
    int minSideJumps(vector<int> &obstacles)
    {

        return solveTab(obstacles);
    }
};