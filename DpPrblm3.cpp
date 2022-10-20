//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

bool isPalindrome(string s, int i, int j)
{
    if (i == j)
    {
        return true;
    }
    if (i > j)
    {
        return true;
    }
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

//*Variations of MCM Prblm
// Minimum cost to cut the stick
// Palindrome Partition Problem
// Evaluate Expression to true or false
// Scrambled String
// Egg Dropping Prblm
// Burst Balloons Prblm

//*Q1.Minimum cost to cut the stick of n length
// recursive
int minCost(int i, int j, vector<int> &arr, int n)
{
    if (i > j)
    {
        return 0;
    }
    int cost = INT_MAX;
    for (int idx = i; idx <= j; idx++)
    {
        cost = min(arr[i - 1] + arr[j + 1] + minCost(i, idx - 1, arr, n) + minCost(idx + 1, j, arr, n), cost);
    }
    return cost;
}
// bottom up
// Time Complexity:- O(n^3)
// Space Complexity:- O(n^2)
int minCost2(int c, vector<int> &arr, int n)
{
    vector<vector<int>> dp2(c + 2, vector<int>(c + 2, 0));
    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j)
                continue;
            int cost = INT_MAX;
            for (int idx = i; idx <= j; idx++)
            {
                cost = min(arr[i - 1] + arr[j + 1] + dp2[i][idx - 1] + dp2[idx + 1][j], cost);
            }
            dp2[i][j] = cost;
        }
    }
    return dp2[1][c];
}

//*Q2.Count the no of partitions required to make every partition of a string palindrome
// recursive
int PalindromePartition(string s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (isPalindrome(s, i, j))
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempans = 1 + PalindromePartition(s, i, k) + PalindromePartition(s, k + 1, j);
        ans = min(ans, tempans);
    }
    return ans;
}
// recursive + memoization
int dp[1000][1000];
int PalindromePartition2(string s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (isPalindrome(s, i, j))
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    int left, right;
    for (int k = i; k <= j - 1; k++)
    {
        if (dp[i][k] != -1)
        {
            left = dp[i][k];
        }
        else
        {
            left = PalindromePartition(s, i, k);
            dp[i][j] = left;
        }
        if (dp[k + 1][j] != -1)
        {
            right = PalindromePartition(s, k + 1, j);
            dp[k + 1][j] = right;
        }
        int tempans = 1 + left + right;
        ans = min(ans, tempans);
    }
    return ans;
}

//*Q3.Evaluate Expression to True Boolean Parenthesization
// Recursive
int EvalExpression(string s, int i, int j, bool isTrue)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue)
        {
            if (s[i] == 'T')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (s[i] == 'T')
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt = EvalExpression(s, i, k - 1, true);
        int lf = EvalExpression(s, i, k - 1, false);
        int rt = EvalExpression(s, k + 1, j, true);
        int rf = EvalExpression(s, k + 1, j, false);
        if (s[k] == '|')
        {
            if (isTrue)
            {
                ans += lt * rf + lt * rt + lf * rt;
            }
            else
            {
                ans += lf * rf;
            }
        }
        else if (s[k] == '&')
        {
            if (isTrue)
            {
                ans += lt * rt;
            }
            else
            {
                ans += lf * rt + lt * rf + lf * rf;
            }
        }
        else if (s[k] == '^')
        {
            if (isTrue)
            {
                ans += lt * rf + lf * rt;
            }
            else
            {
                ans += lt * rt + lf * rf;
            }
        }
    }
    return ans;
}
// Recursion + Memoization
unordered_map<string, int> mpp;
int EvalExpression2(string s, int i, int j, bool isTrue)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue)
        {
            if (s[i] == 'T')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (s[i] == 'T')
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));
    if (mpp.find(temp) != mpp.end())
    {
        return mpp[temp];
    }
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt = EvalExpression2(s, i, k - 1, true);
        int lf = EvalExpression2(s, i, k - 1, false);
        int rt = EvalExpression2(s, k + 1, j, true);
        int rf = EvalExpression2(s, k + 1, j, false);
        if (s[k] == '|')
        {
            if (isTrue)
            {
                ans += lt * rf + lt * rt + lf * rt;
            }
            else
            {
                ans += lf * rf;
            }
        }
        else if (s[k] == '&')
        {
            if (isTrue)
            {
                ans += lt * rt;
            }
            else
            {
                ans += lf * rt + lt * rf + lf * rf;
            }
        }
        else if (s[k] == '^')
        {
            if (isTrue)
            {
                ans += lt * rf + lf * rt;
            }
            else
            {
                ans += lt * rt + lf * rf;
            }
        }
    }
    return mpp[temp] = ans;
}

//*Q4.Scrambled String
// recursive
bool solve(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    if (a.empty() == b.empty())
    {
        return true;
    }
    if (a.compare(b) == 0)
    {
        return true;
    }
    if (a.length() <= 1)
    {
        return false;
    }
    int n = a.length();
    bool flag = false;

    for (int i = 1; i < n; i++)
    {
        if (solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i)))
        {
            flag = true;
            break;
        }
    }
    return flag;
}
// recursive + memoization
unordered_map<string, bool> mpp2;
bool solve2(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    if (a.empty() == b.empty())
    {
        return true;
    }
    if (a.compare(b) == 0)
    {
        return true;
    }
    if (a.length() <= 1)
    {
        return false;
    }

    string temp = a;
    temp.push_back(' ');
    temp.append(b);
    if (mpp.find(temp) != mpp.end())
    {
        return mpp[temp];
    }

    int n = a.length();
    bool flag = false;

    for (int i = 1; i < n; i++)
    {
        if (solve2(a.substr(0, i), b.substr(n - i, i)) && solve2(a.substr(i, n - i), b.substr(0, n - i)))
        {
            flag = true;
            break;
        }
    }
    return mpp[temp] = flag;
}

//*Q5.Egg Dropping Prblm
// recursive
int EggDropping(int floor, int egg)
{
    if (floor == 0 || floor == 1)
    {
        return floor;
    }
    if (egg == 1)
    {
        return floor;
    }
    int mn = INT_MAX;
    for (int k = 1; k <= floor; k++)
    {
        int temp = 1 + max(EggDropping(k - 1, egg - 1), EggDropping(floor - k, egg));
        mn = min(mn, temp);
    }
    return mn;
}

// recursive + memoization
// int dp[1000][1000];
int EggDropping2(int floor, int egg)
{
    if (floor == 0 || floor == 1)
    {
        return floor;
    }
    if (egg == 1)
    {
        return floor;
    }
    if (dp[floor][egg] != -1)
    {
        return dp[floor][egg];
    }
    int mn = INT_MAX, first, second;
    for (int k = 1; k <= floor; k++)
    {
        if (dp[k - 1][egg - 1] != -1)
        {
            first = dp[k - 1][egg - 1];
        }
        else
        {
            dp[k - 1][egg - 1] = EggDropping2(k - 1, egg - 1);
            first = dp[k - 1][egg - 1];
        }
        if (dp[floor - k][egg] != -1)
        {
            second = dp[floor - k][egg];
        }
        else
        {
            dp[floor - k][egg] = EggDropping2(floor - k, egg);
            second = dp[floor - k][egg];
        }
        int temp = 1 + max(first, second);
        mn = min(mn, temp);
    }
    return dp[floor][egg] = mn;
}

//*Q6.Maximum coins get when bursting a balloon
// recursive
int burstBalloon(int i, int j, vector<int> &arr2, int n)
{
    if (i > j)
    {
        return 0;
    }
    int coins = INT_MIN;
    for (int idx = i; idx <= j; idx++)
    {
        coins = max(arr2[i - 1] + arr2[j + 1] + arr2[idx] + burstBalloon(i, idx - 1, arr2, n) + burstBalloon(idx + 1, j, arr2, n), coins);
    }
    return coins;
}
// bottom up
// Time Complexity:- O(n^3)
// Space Complexity:- O(n^2)
int burstBalloon2(int c, vector<int> &arr, int n)
{
    vector<vector<int>> dp2(c + 2, vector<int>(c + 2, 0));
    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j)
                continue;
            int coins = INT_MIN;
            for (int idx = i; idx <= j; idx++)
            {
                coins = max(arr[i - 1] + arr[j + 1] + arr[idx] + dp2[i][idx - 1] + dp2[idx + 1][j], coins);
            }
            dp2[i][j] = coins;
        }
    }
    return dp2[1][c];
}

int main()
{
    vector<int> arr = {3, 1};
    int n = 4;
    arr.insert(arr.begin(), 0);
    arr.push_back(n);
    sort(arr.begin(), arr.end());
    // cout << minCost(1, 2, arr, n);
    // cout << minCost2(2, arr, n);
    // cout << PalindromePartition("nitik", 0, 4);
    // cout << EvalExpression("T|F&T^F", 0, 6, true);
    // cout << solve("great", "rgeat");
    // cout << EggDropping(5, 3);
    vector<int> arr2 = {7, 1, 8};
    arr2.push_back(1);
    arr2.insert(arr2.begin(), 1);
    cout << burstBalloon(1, 3, arr2, arr2.size());
    return 0;
}