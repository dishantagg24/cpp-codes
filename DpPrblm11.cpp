//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

//*Longest Increasing Subsequence (LIS) Problems
// length of LIS
// print LIS (imp.)
// length of LIS using binary search (only for length)
// print longest divisible subset(LDS) (i.e. every pair in subset is divisible by each other)
// longest string chain
// longest bitonic subsequence
// count total number of LISs

//*length of LIS
// recursive
// Time Complexity:- O(2^n)
// Space Complexity:- O(n)
int lis(int idx, int prev, vector<int> &nums, int n)
{
    if (idx == n)
    {
        return 0;
    }
    if (prev != -1 && nums[idx] <= nums[prev])
    {
        return lis(idx + 1, prev, nums, n);
    }
    return max(lis(idx + 1, prev, nums, n), 1 + lis(idx + 1, idx, nums, n));
}

// bottom up with 2D
// Time Complexity:- O(n^2)
// Space Complexity:- O(n^2)
int lis1(vector<int> &nums, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev = idx - 1; prev >= -1; prev--)
        {
            if (prev != -1 && nums[idx] <= nums[prev])
            {
                dp[idx][prev + 1] = dp[idx + 1][prev + 1];
            }
            else
            {
                dp[idx][prev + 1] = max(dp[idx + 1][prev + 1], 1 + dp[idx + 1][idx + 1]);
            }
        }
    }
    return dp[0][0];
}

// bottom up with space optimisation
// Time Complexity:- O(n^2)
// Space Complexity:- O(n*2)
int lis2(vector<int> &nums, int n)
{
    vector<int> next(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev = idx - 1; prev >= -1; prev--)
        {
            if (prev != -1 && nums[idx] <= nums[prev])
            {
                curr[prev + 1] = next[prev + 1];
            }
            else
            {
                curr[prev + 1] = max(next[prev + 1], 1 + next[idx + 1]);
            }
        }
        next = curr;
    }
    return next[0];
}

// bottom up with 1D (Algorithmic Approach)
// Time Complexity:- O(n^2)
// Space Complexity:- O(n)
int lis3(vector<int> &nums, int n)
{
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[prev] < nums[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

// using binary search (lower_bound)
// Time Complexity:- O(nlogn)
// Space Complexity:- O(n)
int lis4(vector<int> &nums, int n)
{
    vector<int> temp;
    temp.push_back(nums[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
            len++;
        }
        else
        {
            int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[idx] = nums[i];
        }
    }
    return len;
}

//*print longest increasing subsequence
vector<int> printLIS(vector<int> &nums, int n)
{
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int maxi = 1;
    int last_index = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[prev] < nums[i] && dp[i] < 1 + dp[prev])
            {
                hash[i] = prev;
                dp[i] = 1 + dp[prev];
            }
        }
        if (dp[i] > maxi)
        {
            last_index = i;
            maxi = dp[i];
        }
    }
    vector<int> ans;
    ans.push_back(nums[last_index]);
    while (last_index != hash[last_index])
    {
        last_index = hash[last_index];
        ans.push_back(nums[last_index]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//*print longest divisible subset (not required to be subsequence)
vector<int> printLDS(vector<int> &nums, int n)
{
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int maxi = 1;
    int last_index = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j])
            {
                hash[i] = j;
                dp[i] = 1 + dp[j];
            }
        }
        if (dp[i] > maxi)
        {
            last_index = i;
            maxi = dp[i];
        }
    }
    vector<int> ans;
    ans.push_back(nums[last_index]);
    while (last_index != hash[last_index])
    {
        last_index = hash[last_index];
        ans.push_back(nums[last_index]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool isPossible(string &s1, string &s2)
{
    if (s1.length() != s2.length() + 1)
        return false;
    int first = 0;
    int second = 0;
    while (first < s1.length())
    {
        if (second < s2.length() && s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
        {
            first++;
        }
    }

    if (first == s1.size() && second == s2.size())
        return true;
    return false;
}

bool comp(string &s1, string &s2)
{
    return s1.length() < s2.length();
}

//*Longest string chain
int lsc(vector<string> &words, int n)
{
    sort(words.begin(), words.end(), comp);
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (isPossible(words[i], words[j]))
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

//*Longest bitonic subsequence
// Time Complexity:- O(n^2)
int lbs(vector<int> &nums, int n)
{
    vector<int> dp1(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp1[i] = max(dp1[i], 1 + dp1[j]);
            }
        }
    }
    vector<int> dp2(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp2[i] = max(dp2[i], 1 + dp2[j]);
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}

//*Count no of longest increasing subsequences
int countLIS(vector<int> &nums, int n)
{
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[prev] < nums[i] && dp[i] > 1 + dp[prev])
            {
                dp[i] = 1 + dp[prev];
                count[i] = count[prev];
            }
            else if (nums[prev] < nums[i] && dp[i] == 1 + dp[prev])
            {
                count[i] += count[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int nos = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
        {
            nos += count[i];
        }
    }
    return nos;
}

//*Count subsequences whose product less than k
int countSubProd(int idx, int prev, int n, int arr[], int k)
{
    if (idx >= n)
    {
        return 0;
    }
    if (arr[idx] >= k || prev * arr[idx] >= k)
    {
        return countSubProd(idx + 1, prev, n, arr, k);
    }
    return 1 + countSubProd(idx + 1, prev, n, arr, k) + countSubProd(idx + 1, arr[idx] * prev, n, arr, k);
}
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lis1(nums, nums.size()) << "\n";
    vector<int> res = printLIS(nums, nums.size());
    for (auto it : res)
        cout << it << " ";
    return 0;
}