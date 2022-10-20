//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

//*Dp is mainly used for reducing time complexity like:- finding the fibonacci number, time complexity is O(2^n) when solved by recursion and it reduces to O(n) when solved by top down approach of dp

//*0/1 KnapSack Problem
// solved using recursion
int knapSack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] > W)
    {
        return knapSack(wt, val, W, n - 1);
    }
    return max(knapSack(wt, val, W - wt[n - 1], n - 1) + val[n - 1], knapSack(wt, val, W, n - 1));
}

// solved using recursion + memoization
int dp[1000][1000];
// memset(dp, -1, sizeof(dp));
int knapSack1(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] > W)
    {
        return dp[n][W] = knapSack1(wt, val, W, n - 1);
    }
    return dp[n][W] = max(knapSack1(wt, val, W - wt[n - 1], n - 1) + val[n - 1], knapSack1(wt, val, W, n - 1));
}

// solved using bottom up approach
// in this approach we change the original recursion code into matrix format
// we reduce the time complexity by using just little extra memory
int knapSack3(int wt[], int val[], int W, int n)
{
    int dp2[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp2[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] > j)
            {
                dp2[i][j] = dp2[i - 1][j];
            }
            else
            {
                dp2[i][j] = max(dp2[i - 1][j - wt[i - 1]] + val[i - 1], dp2[i - 1][j]);
            }
        }
    }
    return dp2[n][W];
}

//*Unbounded KnapSack Problem(we can choose one item multiple times)
// solved using recursion
int UnboundedknapSack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] > W)
    {
        return UnboundedknapSack(wt, val, W, n - 1);
    }
    return max(UnboundedknapSack(wt, val, W - wt[n - 1], n) + val[n - 1], UnboundedknapSack(wt, val, W, n - 1));
}

// solved using top down approach
// in this approach we change the original recursion code into matrix format
// we reduce the time complexity by using just little extra memory
int UnboundedknapSack1(int wt[], int val[], int W, int n)
{
    int dp2[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp2[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] > j)
            {
                dp2[i][j] = dp2[i - 1][j];
            }
            else
            {
                dp2[i][j] = max(dp2[i][j - wt[i - 1]] + val[i - 1], dp2[i - 1][j]);
            }
        }
    }
    return dp2[n][W];
}
int main()
{
    int wt[] = {10, 20, 30};
    int val[] = {100, 50, 150};
    cout << knapSack3(wt, val, 50, 3);
    return 0;
}