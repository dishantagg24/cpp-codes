//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*To find length of subarray whose sum is equal to given sum
int lengthSubarray(int arr[], int n, int sum)
{
    map<int, int> mpp;
    int currSum = 0;
    int st = 0, en = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum == sum)
        {
            st = 0;
            en = i;
            break;
        }
        else if (mpp.find(currSum - sum) != mpp.end())
        {
            st = mpp[currSum - sum] + 1;
            en = i;
            break;
        }
        mpp.insert({currSum, i});
    }
    return en - st + 1;
}

//*To find maximum length of subarray whose sum is equal to given sum
int maxLengthSubarray(int arr[], int n, int sum)
{
    map<int, int> mpp;
    int currSum = 0;
    int st = 0, en = 0;
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum == sum)
        {
            st = 0;
            en = i;
            maxLength = max(maxLength, en - st + 1);
        }
        else if (mpp.find(currSum - sum) != mpp.end())
        {
            st = mpp[currSum - sum] + 1;
            en = i;
            maxLength = max(maxLength, en - st + 1);
        }
        mpp.insert({currSum, i});
    }
    return maxLength;
}

//*To find maximum length of subarray in a binary array which contain equal number of 0s and 1s
int maxLengthSubarray0s1s(int arr[], int n)
{
    map<int, int> mpp;
    int currSum = 0;
    int st = 0, en = 0;
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = -1;
        }
        currSum += arr[i];
        if (currSum == 0)
        {
            st = 0;
            en = i;
            maxLength = max(maxLength, en - st + 1);
        }
        else if (mpp.find(currSum - 0) != mpp.end())
        {
            st = mpp[currSum - 0] + 1;
            en = i;
            maxLength = max(maxLength, en - st + 1);
        }
        mpp.insert({currSum, i});
    }
    return maxLength;
}

//*To find minimum length of subarray whose sum is equal to given sum
int minLengthSubarray(int arr[], int n, int sum)
{
    map<int, int> mpp;
    int currSum = 0;
    int st = 0, en = 0;
    int minLength = n;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum == sum)
        {
            en = i;
            minLength = min(minLength, en - st + 1);
            st = i + 1;
        }
        else if (mpp.find(currSum - sum) != mpp.end())
        {
            st = mpp[currSum - sum] + 1;
            en = i;
            minLength = min(minLength, en - st + 1);
        }
        mpp.insert({currSum, i});
    }
    return minLength;
}

int main()
{
    int arr[] = {10, 15, -5, 15, -10, 5};
    int arr2[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int arr3[] = {1, 1, -2, 5, 5, 5, -15, 3, -3, 0};
    int arr4[] = {1, 1, 0, 1, 1, 0, 0};
    cout << lengthSubarray(arr3, 10, 0) << "\n";
    cout << maxLengthSubarray(arr3, 10, 0) << "\n";
    cout << minLengthSubarray(arr3, 10, 0) << "\n";
    cout << maxLengthSubarray0s1s(arr4, 7);
    return 0;
}