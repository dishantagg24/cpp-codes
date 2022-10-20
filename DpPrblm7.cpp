//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

//*Solving 2D grid Dp Questions (Part 2)
// Triangle (fixed starting point but variable ending point)
// Max Falling Path sum (variable st point & variable end point)
// 2 Start points

//*Minimum path sum from top to bottom in a triangle.
// recursive
// Time Complexity:- O(2^(sum of m natural nos))
// Space Complexity:- O(m)
int Triangle(int i, int j, int m, vector<vector<int>> &triangle)
{
    if (i == m - 1)
    {
        return triangle[i][j];
    }
    int left = Triangle(i + 1, j, m, triangle) + triangle[i][j];
    int right = Triangle(i + 1, j + 1, m, triangle) + triangle[i][j];
    return min(left, right);
}

// bottom up
// Time Complexity:- O(m*m)
// Space Complexity:- O(m*m)
int Triangle2(int i, int j, int m, vector<vector<int>> &triangle)
{
    int dp[m][m];
    for (int j = 0; j < m; j++)
    {
        dp[m - 1][j] = triangle[m - 1][j];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int left = dp[i + 1][j] + triangle[i][j];
            int right = dp[i + 1][j + 1] + triangle[i][j];
            dp[i][j] = min(left, right);
        }
    }
    return dp[0][0];
}

// bottom up with space optimisation
// Time Complexity:- O(m*m)
// Space Complexity:- O(m)
int Triangle3(int i, int j, int m, vector<vector<int>> &triangle)
{
    vector<int> dp(m);
    for (int j = 0; j < m; j++)
    {
        dp[j] = triangle[m - 1][j];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        vector<int> temp(m);
        for (int j = i; j >= 0; j--)
        {
            int left = dp[j] + triangle[i][j];
            int right = dp[j + 1] + triangle[i][j];
            temp[j] = min(left, right);
        }
        dp = temp;
    }
    return dp[0];
}

//*Min Falling Path Sum
// recursive
// Time Complexity:- O(3^n)
// Space Complexity:- O(n)
int fallingSum(int i, int j, vector<vector<int>> &grid, int n)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
    {
        return 9999;
    }

    if (i == n - 1)
    {
        return grid[i][j];
    }

    int ans = INT_MAX;
    for (int k = -1; k <= 1; k++)
    {
        ans = min(ans, fallingSum(i + 1, j + k, grid, n) + grid[i][j]);
    }
    return ans;
}
// bottom up
// Time Complexity:- O(n*n) + O(n)
// Space Complexity:- O(n*n)
int fallingSum2(vector<vector<int>> &grid, int n)
{
    int dp[n][n];
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = grid[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int first = grid[i][j] + dp[i - 1][j];
            int second = INT_MAX;
            if (j - 1 >= 0)
            {
                second = grid[i][j] + dp[i - 1][j - 1];
            }
            int third = INT_MAX;
            if (j + 1 < n)
            {
                third = grid[i][j] + dp[i - 1][j + 1];
            }
            dp[i][j] = min(first, min(second, third));
        }
    }

    int maxi = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        maxi = min(maxi, dp[n - 1][j]);
    }
    return maxi;
}

// bottom up with space optimisation
// Time Complexity:- O(n*n) + O(n)
// Space Complexity:- O(n)
int fallingSum3(vector<vector<int>> &grid, int n)
{
    vector<int> dp(n);
    vector<int> curr(n);
    for (int j = 0; j < n; j++)
    {
        dp[j] = grid[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int first = grid[i][j] + dp[j];
            int second = INT_MAX;
            if (j - 1 >= 0)
            {
                second = grid[i][j] + dp[j - 1];
            }
            int third = INT_MAX;
            if (j + 1 < n)
            {
                third = grid[i][j] + dp[j + 1];
            }
            curr[j] = min(first, min(second, third));
        }
        dp = curr;
    }

    int maxi = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        maxi = min(maxi, dp[j]);
    }
    return maxi;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 3},
                                {6, 5, 4},
                                {7, 8, 9}};
    int n = grid.size();
    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        ans = min(ans, fallingSum(0, j, grid, n));
    }
    // cout << ans;
    cout << fallingSum2(grid, n);
    cout << fallingSum3(grid, n);
    return 0;
}