//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

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

//*Variations of Longest Common Subsequence
// Length of Longest Common Substring of 2 given strings
// Length of shortest Common Supersequence of 2 given strings
// Print the shortest Common Supersequence of 2 given strings
// Length of longest palindromic Subsequence of a given string
// Min no. of insertion & deletion require to convert string a to b
// Min no. of deletion require to convert the given string into longest palindromic string
// Check if string a is present in string b (it can be present as subsequence)

//*Q1.Print the length of longest common substring between 2 given strings
int LCSubstring2(int i, int j, int n, int m, string x, string y, int count)
{
    if (i >= n || j >= m)
    {
        return count;
    }
    int same = count;
    if (x[i] == y[j])
    {
        same = LCSubstring2(i + 1, j + 1, n, m, x, y, count + 1);
    }
    return max(same, max(LCSubstring2(i + 1, j, n, m, x, y, 0), LCSubstring2(i, j + 1, n, m, x, y, 0)));
}

int LCSubstring(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
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
                dp[i][j] = 0;
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

//*Q2.Print the length of shortest common supersequence
int superSeq(string x, string y, int n, int m)
{
    return n + m - LCS(x, y, n, m);
}

//*Q3.Print the shortest common supersequence between 2 given strings
string printSCS(string x, string y, int n, int m)
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
                s.push_back(x[i - 1]);
                i--;
            }
            else
            {
                s.push_back(y[j - 1]);
                j--;
            }
        }
    }
    while (i > 0)
    {
        s.push_back(x[i - 1]);
        i--;
    }
    while (j > 0)
    {
        s.push_back(y[j - 1]);
        j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

//*Q4.Print the length of longest palindromic subsequence
int palindromicSubSeq(string x, int n)
{
    string y = x;
    reverse(y.begin(), y.end());
    int m = y.length();
    return LCS(x, y, n, m);
}

//*Q5.Print the min no. of insertion & deletion require to convert string a to b
vector<int> minInsertDelete(string x, string y, int n, int m)
{
    int lengthLCS = LCS(x, y, n, m);
    int insert_ele = y.length() - lengthLCS;
    int delete_ele = x.length() - lengthLCS;
    vector<int> ans;
    ans.push_back(insert_ele);
    ans.push_back(delete_ele);
    return ans;
}

//*Q6.Print the min no. of deletion require to convert the given string into longest palindromic string
int minDeletionPalindromic(string x, int n)
{
    return x.length() - palindromicSubSeq(x, n);
}

//*Q7.Check if string a is present in string b (it can be present as subsequence)
bool Checkab(string x, string y, int n, int m)
{
    int lengthLCS = LCS(x, y, n, m);
    return n == lengthLCS;
}

int main()
{
    cout << LCSubstring("abcde", "abfce", 5, 5);
    cout << LCSubstring2(0, 0, 5, 5, "abcde", "abfce", 0);
    cout << printSCS("abcdaf", "acbcf", 6, 5);
    return 0;
}