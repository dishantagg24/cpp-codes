//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Print all subsequences of a given array
void printSubSequences(int idx, vector<int> &ans, int arr[], int n)
{
    if (idx == n)
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(arr[idx]);
    printSubSequences(idx + 1, ans, arr, n);
    ans.pop_back();
    printSubSequences(idx + 1, ans, arr, n);
}

//*Print all subsequences of a given array with given sum
void printSubSequencesWithSum(int idx, vector<int> &ans, int arr[], int n, int s, int sum)
{
    if (idx == n)
    {
        if (s == sum)
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
            return;
        }
        return;
    }
    ans.push_back(arr[idx]);
    s += arr[idx];
    printSubSequencesWithSum(idx + 1, ans, arr, n, s, sum);
    ans.pop_back();
    s -= arr[idx];
    printSubSequencesWithSum(idx + 1, ans, arr, n, s, sum);
}

//*Print only one subsequence of a given array with given sum
bool printSubSequencesWithSum2(int idx, vector<int> &ans, int arr[], int n, int s, int sum)
{
    if (idx == n)
    {
        if (s == sum)
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    ans.push_back(arr[idx]);
    s += arr[idx];
    if (printSubSequencesWithSum2(idx + 1, ans, arr, n, s, sum) == true)
    {
        return true;
    };
    ans.pop_back();
    s -= arr[idx];
    if (printSubSequencesWithSum2(idx + 1, ans, arr, n, s, sum) == true)
    {
        return true;
    };
    return false;
}

//*Count all subsequences of a given array with given sum
int printSubSequencesWithSum3(int idx, int arr[], int n, int s, int sum)
{
    if (idx == n)
    {
        if (s == sum)
        {
            return 1;
        }
        return 0;
    }
    s += arr[idx];
    int left = printSubSequencesWithSum3(idx + 1, arr, n, s, sum);
    s -= arr[idx];
    int right = printSubSequencesWithSum3(idx + 1, arr, n, s, sum);
    return left + right;
}

//*Combination Sum :- Print all subsequences of a given array with given sum (each element can be chosen multiple times)
void printSubSequencesWithSum4(vector<int> &ans, int arr[], int n, int sum)
{
    if (n == 0)
    {
        return;
    }
    if (sum == 0)
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    if (arr[n - 1] > sum)
    {
        printSubSequencesWithSum4(ans, arr, n - 1, sum);
        return;
    }
    ans.push_back(arr[n - 1]);
    printSubSequencesWithSum4(ans, arr, n, sum - arr[n - 1]);
    ans.pop_back();
    printSubSequencesWithSum4(ans, arr, n - 1, sum);
    return;
}

//*Combination Sum2 :- Print all different combinations of subsequences of a given array with given sum (each element can only be choose one time)
// Time Complexity :- O(2^n * k) where k=length of each combination, n = size of array
// Space Complexity :- O(k*x)  where x = no of combinations
void printSubSequencesWithSum5(int idx, vector<int> &ans, int sortedArr[], int n, int sum)
{
    if (sum == 0)
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (i > idx && sortedArr[i] == sortedArr[i - 1]) // This code checks for what element we need to call recursion.for eg:- if our array be like:- [1,1,1,2,2] then if choose our first element of the resulting subsequences to be o 1 (i.e. we chosen 0th index) then there will be no point of choosing 1st index and 2nd index element because they are identical as 0th index
        {
            continue;
        }
        if (sortedArr[i] > sum)
        {
            break;
        }
        ans.push_back(sortedArr[i]);
        printSubSequencesWithSum5(i + 1, ans, sortedArr, n, sum - sortedArr[i]);
        ans.pop_back();
    }
}

int main()
{
    int arr[] = {1, 2, 1};
    vector<int> ans;
    // printSubSequences(0, ans, arr, 3);
    // printSubSequencesWithSum(0, ans, arr, 3, 0, 2);
    // printSubSequencesWithSum2(0, ans, arr, 3, 0, 2);
    cout << printSubSequencesWithSum3(0, arr, 3, 0, 2);
    return 0;
}