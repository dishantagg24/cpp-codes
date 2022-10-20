//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Job Sequencing Problem
struct Job
{
    int jobId;
    int deadline;
    int profit;
};
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}
pair<int, int> maxProfit(Job arr[], int n)
{
    sort(arr, arr + n, compare);
    int maxi = arr[0].deadline;
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, arr[i].deadline);
    }
    int slot[maxi + 1];
    for (int i = 1; i <= maxi; i++)
    {
        slot[i] = -1;
    }
    int countJobs = 0, jobsProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j >= 1; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                countJobs++;
                jobsProfit += arr[i].profit;
                break;
            }
        }
    }
    return {countJobs, jobsProfit};
}
struct Job arr[4];

//*Minimum PLatforms
int minPlatforms(int arrival[], int dept[], int n)
{
    sort(arrival, arrival + n);
    sort(dept, dept + n);
    int platform_needed = 1, ans = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arrival[i] <= dept[j])
        {
            platform_needed++;
            i++;
        }
        else
        {
            platform_needed--;
            j++;
        }
        ans = max(ans, platform_needed);
    }
    return ans;
}

int main()
{
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int a, b, c;
    //     cin >> a >> b >> c;
    //     arr[i].jobId = a;
    //     arr[i].deadline = b;
    //     arr[i].profit = c;
    // }
    // pair<int, int> p;

    // p = maxProfit(arr, n);
    // cout << p.first << " " << p.second;
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dept[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minPlatforms(arr, dept, 6);
    return 0;
}