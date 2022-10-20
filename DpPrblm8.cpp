//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

//*Chocolate Pickup Problem
// recursive
// Time Complexity:- O(3^r * 3^r)
// Space Complexity:- O(r)
int maxChocolate(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
{
    if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
    {
        return -1e8;
    }
    if (i == r - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }
    int dj[3] = {-1, 0, 1};
    int ans = 0;
    for (int dj1 = 0; dj1 < 3; dj1++)
    {
        for (int dj2 = 0; dj2 < 3; dj2++)
        {
            if (j1 == j2)
            {
                ans = max(ans, grid[i][j1] + maxChocolate(i + 1, j1 + dj[dj1], j2 + dj[dj2], r, c, grid));
            }
            else
            {
                ans = max(ans, grid[i][j1] + grid[i][j2] + maxChocolate(i + 1, j1 + dj[dj1], j2 + dj[dj2], r, c, grid));
            }
        }
    }
    return ans;
}

// bottom up
// Time Complexity:- O(r * c * c)*9
// Space Complexity:- O(r * c * c)
int maxChocolate2(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
            {
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            }
            else
            {
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int dj[3] = {-1, 0, 1};
                int ans = 0;
                for (int dj1 = 0; dj1 < 3; dj1++)
                {
                    for (int dj2 = 0; dj2 < 3; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                        {
                            value = grid[i][j1];
                        }
                        else
                        {
                            value = grid[i][j1] + grid[i][j2];
                        }
                        if (j1 + dj[dj1] >= 0 && j1 + dj[dj1] < c && j2 + dj[dj2] >= 0 && j2 + dj[dj2] < c)
                        {
                            value += dp[i + 1][j1 + dj[dj1]][j2 + dj[dj2]];
                        }
                        else
                        {
                            value = -1e8;
                        }
                        ans = max(ans, value);
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }
    return dp[0][0][c - 1];
}

// bottom up with space optimisation
// Time Complexity:- O(r * c * c)*9
// Space Complexity:- O(c * c)
int maxChocolate3(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<int>> front(c, vector<int>(c, 0));
    vector<vector<int>> cur(c, vector<int>(c, 0));
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
            {
                front[j1][j2] = grid[r - 1][j1];
            }
            else
            {
                front[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int dj[3] = {-1, 0, 1};
                int ans = 0;
                for (int dj1 = 0; dj1 < 3; dj1++)
                {
                    for (int dj2 = 0; dj2 < 3; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                        {
                            value = grid[i][j1];
                        }
                        else
                        {
                            value = grid[i][j1] + grid[i][j2];
                        }
                        if (j1 + dj[dj1] >= 0 && j1 + dj[dj1] < c && j2 + dj[dj2] >= 0 && j2 + dj[dj2] < c)
                        {
                            value += front[j1 + dj[dj1]][j2 + dj[dj2]];
                        }
                        else
                        {
                            value = -1e8;
                        }
                        ans = max(ans, value);
                    }
                }
                cur[j1][j2] = ans;
            }
        }
        front = cur;
    }
    return front[0][c - 1];
}

int main()
{
    vector<vector<int>> grid = {{2, 3, 1, 2},
                                {3, 4, 2, 2},
                                {5, 6, 3, 5}};
    cout << maxChocolate(0, 0, 3, 3, 4, grid);
    return 0;
}