//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*If we have to find kth smallest/lowest/closest something then we use max heap and if we have to find kth largest/greatest/top something then we use min heap

//*Kth Smallest number in an array
int kthSmallest(int arr[], int n, int k)
{
    priority_queue<int> maxH;
    for (int i = 0; i < n; i++)
    {
        maxH.push(arr[i]);
        if (maxH.size() > k)
        {
            maxH.pop();
        }
    }
    return maxH.top();
}

//*Kth Largest number in array
int kthLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < n; i++)
    {
        minH.push(arr[i]);
        if (minH.size() > k)
        {
            minH.pop();
        }
    }
    return minH.top();
}

//*Sort the nearly sorted array (k integers are sorted in the array)
void sortArray(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minH;
    vector<int> temp(n, 0);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        minH.push(arr[i]);
        if (minH.size() > k)
        {
            temp[s] = minH.top();
            s++;
            minH.pop();
        }
    }
    while (!minH.empty())
    {
        temp[s] = minH.top();
        minH.pop();
        s++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
}

int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    cout << kthSmallest(arr, 6, 3) << "\n";
    cout << kthLargest(arr, 6, 3) << "\n";
    sortArray(arr, 7, 3);

    return 0;
}