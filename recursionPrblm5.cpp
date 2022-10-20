//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Print all subset sum of a given array
void subSetSum(int i, int arr[], int n, int s)
{
    if (n == i)
    {
        cout << s << endl;
        return;
    }
    subSetSum(i + 1, arr, n, s + arr[i]);
    subSetSum(i + 1, arr, n, s);
}

//*Print all subsets without any duplicate
void subSets(int idx, int arr[], int n, vector<int> &s)
{
    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;
    if (n == idx)
    {
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (i > idx && arr[i] == arr[i - 1])
        {
            continue;
        }
        s.push_back(arr[i]);
        subSets(i + 1, arr, n, s);
        s.pop_back();
    }
}

int main()
{
    int arr[] = {1, 1, 2};
    vector<int> ans;
    subSets(0, arr, 3, ans);
    return 0;
}