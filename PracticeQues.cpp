//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Given a sorted array,a minimum difference value 'diff' and a value k. Print yes if array contains k elements whose minimum difference between any two elements is greater than or equal to diff
// for eg if array = [1,2,5,7,11,12] and diff=3, k=3, then three elements can be 1,5,11.Here minimum difference is 4 i.e. 5-1=4

bool isfeasible(int mid, int arr[], int n, int k)
{

    int pos = arr[0];
    int elements = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

//*Given an array and a value k.Print maximized of minimum difference between k elements.This problem is recognised by the name of Aggressive Cows
// for eg if array = [5,2,12,7,11,1] and k=3, then set of three elements can be {1,5,11}, {5,2,12}, {1,5,7}, {5,7,12}, {1,7,12} etc.
// minimum difference in 1st set is 4
// minimum difference in 2nd set is 3
// minimum difference in 3rd set is 4
// minimum difference in 4th set is 2
// minimum difference in 5th set is 5
// so the maximum minimum difference is 5 (we have calculated other sets as well there is no value greater than 5). So the output is 5

int AggressiveCows(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int left = 1, right = arr[n - 1];
    int ans = -1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isfeasible(mid, arr, n, k))
        {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return ans;
}

//*Allocate minimum no. of pages to m students
bool isPossible(int mid, int arr[], int n, int m)
{
    int studentsReq = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (sum + arr[i] > mid)
        {
            studentsReq++;
            sum = arr[i];
            if (studentsReq > m)
            {
                return false;
            }
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int pageAllocate(int arr[], int n, int m)
{
    if (n < m)
    {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int start = 0, end = sum, res = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(mid, arr, n, m))
        {
            res = min(res, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}

//*K-th smallest element after removing some integers from natural numbers
// Method 1
int kthSmallest(int arr[], int n, int k)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (k < arr[i])
        {
            return k;
        }
        k++;
    }
    return k;
}

// Method 2
int kthSmallest2(int arr[], int n, int k)
{
    sort(arr, arr + n);
    if (k < arr[0])
    {
        return k;
    }
    if (k == arr[0])
    {
        return k + 1;
    }
    if (k > arr[n - 1])
    {
        return k + n;
    }
    k -= arr[0] - 1;
    for (int i = 1; i < n; i++)
    {
        int c = arr[i] - arr[i - 1] - 1;
        if (c >= k)
        {
            return arr[i - 1] + k;
        }
        k -= c;
    }
    return arr[n - 1] + k;
}

int main()
{
    int arr[] = {1, 2, 5, 7, 11, 12};
    // cout << isfeasible(3, arr, 6, 3);
    // cout << AggressiveCows(arr, 6, 3);
    // int arr2[] = {10, 20, 30, 40};
    // cout << pageAllocate(arr2, 4, 2);
    int arr3[] = {1, 5, 7, 9};
    cout << kthSmallest(arr3, 4, 6);
    cout << kthSmallest2(arr3, 4, 6);
    return 0;
}