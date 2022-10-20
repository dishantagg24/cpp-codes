//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Expedi Problem
// Truck Petrol problem
int noOfStops(vector<vector<int>> &nums, int dist, int fuel)
{
    sort(nums.begin(), nums.end());
    int ans = 0;
    int curr_fuel = fuel;

    priority_queue<int> maxH;
    for (int i = 0; i < nums.size(); i++)
    {
        if (curr_fuel >= dist)
        {
            break;
        }
        while (curr_fuel < nums[i][0])
        {
            if (maxH.empty())
            {
                return ans;
            }
            ans++;
            curr_fuel = maxH.top();
            maxH.pop();
        }
        maxH.push(nums[i][1]);
    }

    while (!maxH.empty() && curr_fuel < dist)
    {
        curr_fuel += maxH.top();
        maxH.pop();
    }

    if (curr_fuel < dist)
    {
        return -1;
    }
    return ans;
}

//*Maximum and Minimum Difference
// Given an array A. Remove n/2 elements and add it to another array B(initially empty).Print the sum of maximum and minimum values of differences between these two arrays
// for eg:-if A=[12,-3,10,0] then for max difference we can write A=[-3,0] and B=[12,10]
// and for min diff we can write A=[-3,12] and B=[0 10]
int maxDiff(int arr[], int n)
{
    sort(arr, arr + n);
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n / 2; i++)
    {
        sum1 += arr[i];
        sum2 += arr[i + n / 2];
    }
    return sum2 - sum1;
}

int minDiff(int arr[], int n)
{
    sort(arr, arr + n);
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n / 2; i++)
    {
        sum1 += arr[2 * i];
        sum2 += arr[2 * i + 1];
    }
    return sum2 - sum1;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        nums.push_back({a, b});
    }
    cout << noOfStops(nums, 10, 25);
    int arr[] = {12, -3, 10, 0};
    cout << maxDiff(arr, 4) << "\n";
    cout << minDiff(arr, 4);
    return 0;
}