//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<int> maxH;
priority_queue<int, vector<int>, greater<int>> minH;
//*Find Median of running stream integers
void insert(int key)
{

    if (!maxH.empty() && key > maxH.top())
    {
        minH.push(key);
    }
    else
    {
        maxH.push(key);
    }
    if (maxH.size() > minH.size() + 1)
    {
        minH.push(maxH.top());
        maxH.pop();
    }
    else if (maxH.size() < minH.size())
    {
        maxH.push(minH.top());
        minH.pop();
    }
    return;
}

double median()
{
    if (minH.size() == maxH.size())
    {
        return (minH.top() + maxH.top()) / 2.0;
    }
    return maxH.top();
}

int main()
{
    int arr[] = {10, 15, 21, 30, 18, 19};
    for (int i = 0; i < 6; i++)
    {
        insert(arr[i]);
        cout << median() << " ";
    }

    return 0;
}