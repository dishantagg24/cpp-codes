//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Generally sorting is done first while applying greedy techniques
//*If there is uniformity in values like sorted values in ascending or descending or smthng like that an we have to find max,min then we can apply greedy technique

//* Q1.Minimum Coins
// In the given array the ith element > (i-1)th element & (i-2)th element, that's why we can apply greedy algorithm else we have to apply dp.
int minCoins(int arr[], int n, int val)
{
    sort(arr, arr + n);
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (val <= 0)
        {
            break;
        }
        count += val / arr[i];
        cout << count << " ";
        val -= ((val / arr[i]) * arr[i]);
    }
    cout << "\n";
    return count;
}

//*Q2. Activity Selection Problem (same problem as N meeting in one room)
int activitySel(vector<vector<int>> &nums)
{
    sort(nums.begin(), nums.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });
    int take = 1;
    int end = nums[0][1];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i][0] >= end)
        {
            take++;
            end = nums[i][1];
        }
    }
    return take;
}

//*Q3. Fractional Knapsack Problem
int FractionalKnap(vector<vector<int>> &nums, int val)
{
    int ans = 0;
    sort(nums.begin(), nums.end(), [&](vector<int> &a, vector<int> &b)
         { return a[0] / a[1] > b[0] / b[1]; });
    for (int i = 0; i < nums.size(); i++)
    {
        if (val == 0)
        {
            break;
        }
        if (nums[i][1] <= val)
        {
            ans += nums[i][0];
            val -= nums[i][1];
        }
        else
        {
            ans += ((nums[i][0] / nums[i][1]) * val);
            val = 0;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 5, 10, 20, 100, 200, 500, 2000};
    cout << minCoins(arr, 9, 49) << "\n";
    int n;
    cin >> n;
    vector<vector<int>> nums;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        nums.push_back({a, b});
    }
    cout << activitySel(nums);
    cout << FractionalKnap(nums, 20);
    return 0;
}