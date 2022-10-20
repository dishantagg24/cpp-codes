//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

// Count number of palindromic substrings present in a string s
// Count number of palindromic subsequence present in a string s
// Print all the palindromic substrings present in a string s
// Length of longest palindromic substring present in a string s
// Print the longest palindromic substring present in a string s
// Length of longest alternating subsequence in a string s
// Count Common subsequences in two strings

//* Count number of palindromic substrings present in a string s
int countPalinSubstrings(int n, string s)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int count = 0;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
                count++;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 1;
                    count++;
                }
            }
            else
            {
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    count++;
                }
            }
        }
    }
    return count;
}
//* Count number of palindromic subsequence present in a string s
int countPalinSubsequences(string str)
{
    int n = str.length();
    long long int dp[n][n];
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (gap == 1)
            {
                dp[i][j] = str[i] == str[j] ? 3 : 2;
            }
            else
            {
                if (str[i] == str[j])
                {
                    dp[i][j] = (1 + dp[i + 1][j] + dp[i][j - 1]);
                }
                else
                {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]);
                }
            }
        }
    }
    return dp[0][n - 1];
}

//* Print all the palindromic substrings present in a string s
void printPalinSubstrings(int n, string s)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    string ans = "";
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
                cout << s[i] << "\n";
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 1;
                    string temp = s.substr(i, j - i + 1);
                    cout << temp << "\n";
                }
            }
            else
            {
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    string temp = s.substr(i, j - i + 1);
                    cout << temp << "\n";
                    dp[i][j] = 1;
                }
            }
        }
    }
    return;
}

//* Length of longest palindromic substring present in a string s
int LongestPalinSubstring(int n, string s)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ans = 0;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 1;
                }
            }
            else
            {
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                }
            }
            if (dp[i][j])
                ans = gap + 1;
        }
    }
    return ans;
}

//* Print the longest palindromic substring present in a string s
string printLongestPalinSubstring(int n, string s)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    string res = "";
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 1;
                }
            }
            else
            {
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                }
            }
            if (dp[i][j])
                res = s.substr(i, j - i + 1);
        }
    }
    return res;
}

//* Length of longest alternating subsequence in a string s
// recursive
int LAS(int idx, int prev, int n, vector<int> &nums, int sm)
{
    if (idx >= n)
    {
        return 0;
    }
    if (prev != -1)
    {
        if (sm)
        {
            if (nums[idx] > nums[prev])
            {
                return max(1 + LAS(idx + 1, idx, n, nums, 0), LAS(idx + 1, prev, n, nums, sm));
            }
            else
            {
                return LAS(idx + 1, prev, n, nums, sm);
            }
        }
        else
        {
            if (nums[idx] < nums[prev])
            {
                return max(1 + LAS(idx + 1, idx, n, nums, 1), LAS(idx + 1, prev, n, nums, sm));
            }
            else
            {
                return LAS(idx + 1, prev, n, nums, sm);
            }
        }
    }
    return max(LAS(idx + 1, prev, n, nums, sm), 1 + LAS(idx + 1, idx, n, nums, sm));
}
// bottom up
int LAS2(int n, vector<int> &nums)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev = idx - 1; prev >= -1; prev--)
        {
            for (int sm = 0; sm < 2; sm++)
            {
                if (prev != -1)
                {
                    if (sm)
                    {
                        if (nums[idx] > nums[prev])
                        {
                            dp[idx][prev + 1][sm] = max(1 + dp[idx + 1][idx + 1][0], dp[idx + 1][prev + 1][sm]);
                        }
                        else
                        {
                            dp[idx][prev + 1][sm] = dp[idx + 1][prev + 1][sm];
                        }
                    }
                    else
                    {
                        if (nums[idx] < nums[prev])
                        {
                            dp[idx][prev + 1][sm] = max(1 + dp[idx + 1][idx + 1][1], dp[idx + 1][prev + 1][sm]);
                        }
                        else
                        {
                            dp[idx][prev + 1][sm] = dp[idx + 1][prev + 1][sm];
                        }
                    }
                }
                else
                {
                    dp[idx + 1][prev + 1][sm] = max(dp[idx + 1][prev + 1][sm], 1 + dp[idx + 1][idx + 1][sm]);
                }
            }
        }
    }
    return max(dp[0][0][1], dp[0][0][0]);
}
// Optimised Approach (without using dp)
int LAS3(vector<int> &nums)
{
    int ma = 1, mi = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
        {
            ma = mi + 1;
        }
        else if (nums[i - 1] < nums[i])
        {
            mi = ma + 1;
        }
    }
    return max(ma, mi);
}

//* Count Common subsequences in two strings
int countCommonSubsequences(string s, string t)
{
    int n1 = s.length();
    int n2 = t.length();
    int dp[n1 + 1][n2 + 1];

    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }
    return dp[n1][n2];
}

int main()
{
    cout << countPalinSubstrings(5, "cabaa");
    printPalinSubstrings(5, "cabaa");
    return 0;
}