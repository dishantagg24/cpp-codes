//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

//*Solving 2D grid Dp Questions (Part 1)
// Ninja Training Problem
// Count All unique Paths
// Count All unique Paths with obstacles
// Min path sum (done in aditya verma playlist)
//? Time Complexity:- O(N *M) //recursive + memoization , bottom up
//? Space Complexity:-
// O((M - 1) + (N - 1)) + O(N *M) // recursive + memoization
// O(N *M) // bottom up

//*Ninja Training Problem
// recursive
// Time Complexity:- O((N*4)*3)
// Space Complexity:- O(4)
int NinjaTraining(int day, int last, vector<vector<int>> &task)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int m = 0; m < 3; m++)
        {
            if (m != last)
            {
                maxi = max(maxi, task[day][m]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for (int m = 0; m < 3; m++)
    {
        if (m != last)
        {
            maxi = max(maxi, NinjaTraining(day - 1, m, task) + task[day][m]);
        }
    }
    return maxi;
}

// bottom up
// Time Complexity:- O((N*4)*3)
// Space Complexity:- O(N*4)
int NinjaTraining2(vector<vector<int>> &task)
{
    int n = task.size();
    int dp[n][4];
    dp[0][0] = max(task[0][1], task[0][2]);
    dp[0][1] = max(task[0][0], task[0][2]);
    dp[0][2] = max(task[0][0], task[0][1]);
    dp[0][3] = max(task[0][0], max(task[0][1], task[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int m = 0; m < 3; m++)
            {
                if (m != last)
                {
                    dp[day][last] = max(dp[day][last], dp[day - 1][m] + task[day][m]);
                }
            }
        }
    }

    return dp[n - 1][3];
}

// bottom up with space Optimisation
// Time Complexity:- O((N*4)*3)
// Space Complexity:- O(N*4)
int NinjaTraining3(vector<vector<int>> &task)
{
    int n = task.size();
    vector<int> dp(4, 0);
    dp[0] = max(task[0][1], task[0][2]);
    dp[1] = max(task[0][0], task[0][2]);
    dp[2] = max(task[0][0], task[0][1]);
    dp[3] = max(task[0][0], max(task[0][1], task[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int m = 0; m < 3; m++)
            {
                if (m != last)
                {
                    temp[last] = max(temp[last], dp[m] + task[day][m]);
                }
            }
        }
        dp = temp;
    }

    return dp[3];
}

//*Count all unique paths
// recursive
// Time Complexity :- O(2^(m*n))
// Space Complexity :- O(m-1 + n-1) i.e. path length
int countPaths(int m, int n)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (m < 0 || n < 0)
    {
        return 0;
    }
    return countPaths(m - 1, n) + countPaths(m, n - 1);
}

// bottom up
// Time Complexity :- O(m*n)
// Space Complexity :- O(m*n)
int countPaths2(int m, int n)
{
    int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int left = 0, right = 0;
                if (i > 0)
                {
                    left = dp[i - 1][j];
                }
                if (j > 0)
                {
                    right = dp[i][j - 1];
                }
                dp[i][j] = left + right;
            }
        }
    }
    return dp[m - 1][n - 1];
}

// bottom up with space optimisation (giving W.A. on leetcode)
// Time Complexity :- O(m*n)
// Space Complexity :- O(n)
int countPaths3(int m, int n)
{
    vector<int> dp(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
            }
            else if (j > 0)
            {
                temp[j] = dp[j] + temp[j - 1];
            }
        }
        dp = temp;
    }
    return dp[n - 1];
}

//*Count all unique paths with obstacles
// recursive
// Time Complexity :- O(2^(m*n))
// Space Complexity :- O(m-1 + n-1) i.e. path length
int countPathsWithObst(int m, int n, vector<vector<int>> &grid)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (m < 0 || n < 0 || grid[m][n] == 1)
    {
        return 0;
    }
    return countPathsWithObst(m - 1, n, grid) + countPathsWithObst(m, n - 1, grid);
}

// bottom up
// Time Complexity :- O(m*n)
// Space Complexity :- O(m*n)
int countPathsWithObst2(int m, int n, vector<vector<int>> &grid)
{
    int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int left = 0, right = 0;
                    if (i > 0)
                    {
                        left = dp[i - 1][j];
                    }
                    if (j > 0)
                    {
                        right = dp[i][j - 1];
                    }
                    dp[i][j] = left + right;
                }
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> task = {{10, 40, 70},
                                {20, 50, 80},
                                {30, 60, 90}};
    cout << NinjaTraining(2, 3, task);
    cout << NinjaTraining2(task);
    cout << NinjaTraining3(task);
    return 0;
}