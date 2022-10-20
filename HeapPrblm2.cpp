//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Given an array, convert it into maxHeap
// All the leaf nodes are naturally heap
// Leaf nodes are starting from index n/2 in array of length n
void heapify(vector<int> &v, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && v[l] > v[i])
    {
        largest = l;
    }
    if (r < n && v[r] > v[i])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void buildHeap(vector<int> &v, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(v, n, i);
    }
}

//*Given a maxHeap, covert it into sorted array
void heapSort(vector<int> &v)
{
    int n = v.size();
    for (int i = n - 1; i > 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

int main()
{
    int arr[] = {30, 20, 35, 10, 5, 32, 34};
    vector<int> v;
    for (int i = 0; i < 7; i++)
    {
        v.push_back(arr[i]);
    }
    buildHeap(v, 7);
    heapSort(v);
    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}