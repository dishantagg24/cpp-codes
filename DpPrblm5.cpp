//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

//*Questions
// Nth Fibonacci Nummber
// Min numbers required whose sum of their sqaures equal to given n
// Maximum difference of zeros and ones in binary string (Kadane's Algorithm)
// Frog Jump Prblm
// House Robber Prblm (max. sum of non adjacent elements)

//*Nth Fibonacci Number
// recursive
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

// bottom up approach
int fib2(int n)
{
    int dp[n + 1];

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

//*Count min. nos required whose sum of their squares equal to given n
// recursive
int minSquare(int n)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
    {
        return n;
    }
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + minSquare(n - i * i));
    }
    return ans;
}
// bottom up appproach
// dry run for n=10
//[0,1,2,3,4,5,6,7,8,9,10]  for i=1
//[0,1,2,3,1,2,3,4,2,3,4]   for i=2
//[0,1,2,3,1,2,3,4,2,1,2]   for i=3
int minSquare2(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 1; i * i <= n; i++)
    {
        for (int j = 0; i * i + j <= n; j++)
        {
            dp[i * i + j] = min(dp[i * i + j], 1 + dp[j]);
        }
    }
    return dp[n];
}

//* Maximum difference of zeros and ones in binary string (Kadane's Algorithm)
int maxSubstring(string S)
{
    vector<int> arr(S.length(), 0);
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '1')
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = 1;
        }
    }
    int ans = 0, curr = 0;
    for (int i = 0; i < S.length(); i++)
    {
        curr += arr[i];
        ans = max(ans, curr);
        if (curr < 0)
        {
            curr = 0;
        }
    }
    if (ans == 0)
    {
        return -1;
    }
    return ans;
}

//* Frog Jump Prblm :- frog can only jump from i to i+1,i+2. Find min energy required to reach from first to last stair.
// recursive
int frogJump(vector<int> &heights, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int left = frogJump(heights, n - 1) + abs(heights[n] - heights[n - 1]);
    int right = INT_MAX;
    if (n > 1)
    {
        right = frogJump(heights, n - 2) + abs(heights[n] - heights[n - 2]);
    }
    return min(left, right);
}

// bottom up
int frogJump2(vector<int> &heights, int n)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n];
}

// bottom up with space optimisation
int frogJump3(vector<int> &heights, int n)
{
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int left = prev + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = prev2 + abs(heights[i] - heights[i - 2]);
        }
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

// Time Complexity :- O(N*K)
// Space Complexity :- O(N) + O(N)
int frogJumpSec(vector<int> &heights, int n, int k)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n >= i)
        {
            ans = min(ans, frogJumpSec(heights, n - i, k) + abs(heights[n] - heights[n - i]));
        }
    }
    return ans;
}

// Time Complexity :- O(N*K)
// Space Complexity :- O(N) (since there is no recursion stack)
int frogJumpSec2(vector<int> &heights, int n, int k)
{
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int ans = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i >= j)
            {
                ans = min(ans, dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
        dp[i] = ans;
    }

    return dp[n];
}

//*House Robber Prblm :- Print Maximum sum of non-adjacent elements
// recursive
// Time Complexity:- O(2^n)
int HouseRob(vector<int> &arr, int n)
{
    if (n == 0)
    {
        return arr[n];
    }
    if (n < 0)
    {
        return 0;
    }
    int pick = HouseRob(arr, n - 2) + arr[n];
    int not_pick = HouseRob(arr, n - 1);
    return max(pick, not_pick);
}
// Bottom Up
// Time Complexity:- O(N)
// Space COmplexity:- O(N); //we can reduce it to O(1) by using prev,prev2,curr variable instead of dp array
int HouseRob2(vector<int> &arr, int n)
{
    int dp[n + 1];
    dp[0] = arr[0];

    for (int i = 1; i <= n; i++)
    {
        int pick = arr[i];
        int not_pick = dp[i - 1];
        if (i - 2 >= 0)
        {
            pick += dp[i - 2];
        }
        dp[i] = max(pick, not_pick);
    }
    return dp[n];
}

int main()
{
    // cout << fib(8);
    // cout << fib2(8);
    // cout << minSquare(26);
    // cout << minSquare2(26);
    cout << maxSubstring("11000010001");
    vector<int> heights = {40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    // cout << frogJump(heights, 9);
    // cout << frogJump2(heights, 9);
    // cout << frogJump3(heights, 2);
    // cout << frogJumpSec(heights, 9, 4);
    cout << frogJumpSec2(heights, 9, 4);
    vector<int> arr = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    cout << HouseRob(arr, 8);
    return 0;
}