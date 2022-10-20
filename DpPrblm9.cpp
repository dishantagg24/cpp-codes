//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

//*String Matching Problems
// Distinct Subsequences
// Edit Distance (insert, delete, replace operation)
// Wildcard Matching (containing '?' , '*' characters)

//*Distinct Subsequences
// recursive
// Time Complexity:- O(2^n * 2^m)
// Space Complexity:- O(n+m)
int distSubseq(int n, int m, string s1, string s2)
{
    if (m == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (s1[n - 1] == s2[m - 1])
    {
        return distSubseq(n - 1, m - 1, s1, s2) + distSubseq(n - 1, m, s1, s2);
    }
    return distSubseq(n - 1, m, s1, s2);
}

// bottom up
// Time Complexity:- O(n*m)
// Space Complexity:- O(n*m)
int distSubseq1(int n, int m, string s1, string s2)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
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
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

//*Edit Distance
// recursive
// Time Complexity:- O(3^n * 3^m)
// Space Complexity:- O(n+m)
int editDist(int n, int m, string s1, string s2)
{
    if (n == 0)
    {
        return m;
    }
    if (m == 0)
    {
        return n;
    }
    if (s1[n - 1] == s2[m - 1])
    {
        return editDist(n - 1, m - 1, s1, s2);
    }
    int insertOp = 1 + editDist(n, m - 1, s1, s2);
    int deleteOp = 1 + editDist(n - 1, m, s1, s2);
    int replaceOp = 1 + editDist(n - 1, m - 1, s1, s2);
    return min(insertOp, min(deleteOp, replaceOp));
}
// bottom up
// Time Complexity:- O(n*m)
// Space Complexity:- O(n*m)
int editDist1(int n, int m, string s1, string s2)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int insertOp = 1 + dp[i][j - 1];
                int deleteOp = 1 + dp[i - 1][j];
                int replaceOp = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(insertOp, min(deleteOp, replaceOp));
            }
        }
    }
    return dp[n][m];
}

//*Wildcard Matching
// recursive
// Time Complexity:- O(2^n * 2^m)
// Space Complexity:- O(n+m)
bool isMatchPattern(int n, int m, string s, string p)
{
    if (n == 0 && m == 0)
    {
        return true;
    }
    if (n != 0 && m == 0)
    {
        return false;
    }
    if (n == 0 && m != 0)
    {
        for (int i = 0; i < m; i++)
        {
            if (p[i] != '*')
            {
                return false;
            }
        }
        return true;
    }
    if (s[n - 1] == p[m - 1] || p[m - 1] == '?')
    {
        return isMatchPattern(n - 1, m - 1, s, p);
    }
    if (p[m - 1] == '*')
    {
        return isMatchPattern(n, m - 1, s, p) || isMatchPattern(n - 1, m, s, p);
    }
    return false;
}
// bottom up
// Time Complexity:- O(n*m)
// Space Complexity:- O(n*m)
bool isMatchPattern1(int n, int m, string s, string p)
{
    int dp[n + 1][m + 1];
    dp[0][0] = 1;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i != 0 && j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j != 0)
            {
                bool flag = true;
                for (int i1 = 0; i1 < j; i1++)
                {
                    if (p[i1] != '*')
                    {
                        flag = false;
                    }
                }
                dp[i][j] = flag;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
}

int main()
{
    cout << distSubseq1(7, 6, "rabbbit", "rabbit");
    cout << editDist1(5, 3, "horse", "ros");
    cout << isMatchPattern1(7, 5, "abdejcd", "?b*cd");
    return 0;
}