//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

//*Matrix Chain Multiplication
// recursive code
int MCM(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempans = arr[i - 1] * arr[k] * arr[j] + MCM(arr, i, k) + MCM(arr, k + 1, j);
        ans = min(ans, tempans);
    }
    return ans;
}
// using recursion + memoization
int dp[1001][1001];
int MCM1(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempans = arr[i - 1] * arr[k] * arr[j] + MCM1(arr, i, k) + MCM1(arr, k + 1, j);
        ans = min(ans, tempans);
    }
    return dp[i][j] = ans;
}
// using bottom up
int MCM2(int arr[], int n)
{
    int dp2[n][n];
    for (int i = 1; i < n; i++)
    {
        dp2[i][i] = 0;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int ans = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int tempans = arr[i - 1] * arr[k] * arr[j] + dp2[i][k] + dp2[k + 1][j];
                ans = min(ans, tempans);
            }
            dp2[i][j] = ans;
        }
    }
    return dp2[1][n - 1];
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    cout << MCM(arr, 1, 4) << " ";
    cout << MCM2(arr, 5);
    return 0;
}