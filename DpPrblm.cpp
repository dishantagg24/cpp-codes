//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

//*Variations of knapSack Prblm
// Check SubSet available with given Sum
// No of subsets with given sum
// Print min diff b/w sum of 2 sets
// Count subset's pairs whose sum's diff == given diff

//*Q1.Check if there is any subset {a,b,c} exist whose sum is equal to given sum
// using recursion
// Time Complexity:- O(2^n)
// Space Complexity:- O(n)
bool subSetSum1(int arr[], int n, int sum)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (arr[n - 1] > sum)
    {
        return subSetSum1(arr, n - 1, sum);
    }
    return subSetSum1(arr, n - 1, sum) || subSetSum1(arr, n - 1, sum - arr[n - 1]);
}

// using bottom up approach (2D matrix)
// Time Complexity:- O(n*sum)
// Space Complexity:- O(n*sum)
bool subSetSum(int arr[], int n, int sum)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - (arr[i - 1])] || dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

// using bottom up approach with space optimisation
// Time Complexity:- O(n*sum)
// Space Complexity:- O(sum)
bool subSetSum2(int arr[], int n, int sum)
{
    vector<bool> prev(sum + 1, 0), curr(sum + 1, 0);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i] > j)
            {
                curr[j] = prev[j];
            }
            else
            {
                curr[j] = prev[j - (arr[i])] || prev[j];
            }
        }
        prev = curr;
    }
    return prev[sum];
}

//*Q2.Count the no of subsets exist whose sum is equal to given sum (0 is not included in arr in constraint)
// using recursion
// Time Complexity:- O(2^n)
// Space Complexity:- O(n)
int countSubset1(int arr[], int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (arr[n - 1] > sum)
    {
        return countSubset1(arr, n - 1, sum);
    }
    return countSubset1(arr, n - 1, sum) + countSubset1(arr, n - 1, sum - arr[n - 1]);
}

// for test case arr = [0,0,1] & sum=1 then output will be 4 not 1
int countSubset1withZero(int arr[], int n, int sum)
{
    if (n == 0)
    {
        if (sum == 0 && arr[0] == 0)
            return 2;
        if (sum == 0)
            return 1;
        return 0;
    }
    if (arr[n - 1] > sum)
    {
        return countSubset1(arr, n - 1, sum);
    }
    return countSubset1(arr, n - 1, sum) + countSubset1(arr, n - 1, sum - arr[n - 1]);
}

// using bottom up approach (2D matrix + iterative)
// Time Complexity:- O(n*sum)
// Space Complexity:- O(n*sum)
int countSubset(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - (arr[i - 1])] + dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

// using bottom up approach with space optimisation
// Time Complexity:- O(n*sum)
// Space Complexity:- O(sum)
int countSubset2(int arr[], int n, int sum)
{
    vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
    prev[0] = curr[0] = 1;
    if (arr[0] <= sum)
    {
        prev[arr[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            int notTake = prev[j];
            int take = 0;
            if (arr[i] <= j)
            {
                take = prev[j - arr[i]];
            }
            curr[j] = take + notTake;
        }
        prev = curr;
    }
    return prev[sum];
}

//*Q3.Divide the given arr in two sets whose sum's difference is minimum
int MinSubsetDiff(int arr[], int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
    {
        range += arr[i];
    }
    int S1 = 0;
    int mn = INT_MAX;
    for (int i = 0; i < range / 2; i++)
    {
        if (subSetSum(arr, n, i)) // here we are calling subSetSum again & again and bcoz of that we created dp array many times unneccesarily
        // instead of this we can declare a global dp array and modified it using subSetSum method(we don't return anything) and use the nth row for further calculations
        {
            int s1 = i;
            int s2 = range - i;
            mn = min(mn, abs(s2 - s1));
        }
    }
    return mn;
}

//*Q4.Count the pair of subsets exist whose sum's diff is equal to given diff
int countSubSetWithDiff(int arr[], int n, int diff)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }

    int sum = (total + diff) / 2;
    return countSubset(arr, n, sum);
}

//*Variations of UnboundedKnapsack Prblm
// Rod Cutting Problem
// Coin Change Problem
// Coin Change Problem2

//*Q1. Rod Cutting Prblm (Print the max profit by cutting nth size rod in different lengths)
int rodCuttPrblm(int length[], int price[], int N, int n)
{
    int dp2[n + 1][N + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp2[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (length[i - 1] > j)
            {
                dp2[i][j] = dp2[i - 1][j];
            }
            else
            {
                dp2[i][j] = max(dp2[i][j - length[i - 1]] + price[i - 1], dp2[i - 1][j]);
            }
        }
    }
    return dp2[n][N];
}

//*Q2.Coin Change Prblm(Print the max no. of ways to choose coins to get the given sum)
int CoinChangePrblm(int coins[], int sum, int n)
{
    int dp2[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
            {
                dp2[i][j] = 1;
            }
            else if (i == 0)
            {
                dp2[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] > j)
            {
                dp2[i][j] = dp2[i - 1][j];
            }
            else
            {
                dp2[i][j] = dp2[i][j - (coins[i - 1])] + dp2[i - 1][j];
            }
        }
    }
    return dp2[n][sum];
}

//*Q3.Coin Change Prblm2 (Print the min no. of coins to get the given sum)
int CoinChangePrblm1(int coins[], int amount, int n)
{
    int dp[n + 1][amount + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < amount + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
            else if (i == 1)
            {
                if (coins[0] == j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = INT_MAX - 1;
                }
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - (coins[i - 1])]);
            }
        }
    }
    if (dp[n][amount] == INT_MAX - 1)
    {
        return -1;
    }
    return dp[n][amount];
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 11;
    cout << subSetSum(arr, 5, sum);
    cout << subSetSum1(arr, 5, sum);
    cout << subSetSum2(arr, 5, sum);
    return 0;
}