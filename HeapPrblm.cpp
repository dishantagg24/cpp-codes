//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ppi;

class Compare
{
public:
    bool operator()(ppi x, ppi y)
    {
        if (x.first == y.first)
        {
            return x.second > y.second;
        }
        return (x.first < y.first);
    }
};

//*Find k closest numbers to x
// for eg:-in array = [1,3,4,6,7,8,9] the 3 closest numbers to 7 are 6,7,8
void kClosest(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int>> maxH;
    for (int i = 0; i < n; i++)
    {
        maxH.push({abs(arr[i] - x), i});
        if (maxH.size() > k)
        {
            maxH.pop();
        }
    }
    while (maxH.size() > 0)
    {
        int idx = maxH.top().second;
        cout << arr[idx] << " ";
        maxH.pop();
    }
}

//*Top K freq numbers
// for eg:- in array = [1,1,1,3,3,5,5,5,6,7,8]and k=2 then output will be 1 and 5 because their frequencies are maximum
void kFreq(int arr[], int n, int k)
{
    priority_queue<ppi, vector<ppi>, greater<ppi>> minH;
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        minH.push({it.second, it.first});
        if (minH.size() > k)
        {
            minH.pop();
        }
    }
    while (minH.size() > 0)
    {
        int idx = minH.top().second;
        cout << idx << " ";
        minH.pop();
    }
}

//*Sort array according to their frequencies
// for eg:- in array = [1,1,1,2,2,3,3,3,4,5,6] then output will be [1,1,1,3,3,3,2,2,4,5,6]
void freqSort(int arr[], int n)
{
    priority_queue<ppi, vector<ppi>, Compare> maxH;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        maxH.push({it.second, it.first});
    }
    while (maxH.size() > 0)
    {
        int no_of_rep_ele = maxH.top().first;
        int idx = maxH.top().second;
        for (int i = 0; i < no_of_rep_ele; i++)
        {
            cout << idx << " ";
        }
        maxH.pop();
    }
}

//*Connect Ropes. In this problem greedy technique is used like we are sorting by pushing element in minheap and then ans depends on previous value.
// Given n ropes of a[i] unit the cost of merging two ropes is a[i]+a[j].Minimum the cost of merging of all the ropes.
int connectRopes(int arr[], int n)
{
    int k = 2;
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < n; i++)
    {
        minH.push(arr[i]);
    }
    int ans = 0;
    while (minH.size() > 1)
    {
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += minH.top();
            minH.pop();
        }
        minH.push(sum);
        ans += sum;
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    kClosest(arr, 9, 3, 7);
    kFreq(arr, 9, 2);
    freqSort(arr, 9);
    return 0;
}