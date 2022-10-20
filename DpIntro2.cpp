//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

//*Longest Common Subsequence Prblm
//*Print the length of Longest Common Subsequence between 2 given strings
// solved using recursion
int LCS(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (x[n - 1] == y[n - 1])
    {
        return 1 + LCS(x, y, n - 1, m - 1);
    }
    return max(LCS(x, y, n, m - 1), LCS(x, y, n - 1, m));
}

// solved using recursion + memoization
int dp[1000][1000];
// memset(dp, -1, sizeof(dp));
int LCS1(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (x[n - 1] == y[n - 1])
    {
        return dp[n][m] = 1 + LCS1(x, y, n - 1, m - 1);
    }
    return dp[n][m] = max(LCS1(x, y, n, m - 1), LCS1(x, y, n - 1, m));
}

// solved using bottom up approach
// in this approach we change the original recursion code into matrix format
// we reduce the time complexity by using just little extra memory
int LCS2(string x, string y, int n, int m)
{
    int dp2[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp2[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp2[i][j] = dp2[i - 1][j - 1] + 1;
            }
            else
            {
                dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]);
            }
        }
    }
    return dp2[n][m];
}

//*Print the longest common subsequence between 2 given strings
// recursive method
string printLCS(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return "";
    }
    if (x[n - 1] == y[m - 1])
    {
        return x[n - 1] + printLCS(x, y, n - 1, m - 1);
    }
    return max(printLCS(x, y, n - 1, m), printLCS(x, y, n, m - 1));
}

string printLCS2(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    string s;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    return s;
}

int main()
{
    cout << LCS("abcdgh", "abedfhr", 6, 7);
    cout << LCS2("abcdgh", "abedfhr", 6, 7);
    cout << printLCS2("abcdgh", "abedfhr", 6, 7);
    return 0;
}