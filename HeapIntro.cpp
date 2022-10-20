//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Heap :- A complete binary tree (a tree in which all the nodes have 2 children except leaf nodes. In leaf nodes there can be one child only but it will be left child not right child)
//*There are two types of heap i.e. MaxHeap & MinHeap
//*In MaxHeap all nodes of subtree are smaller than root node
//*In MinHeap all nodes of subtree are greater than root node
// for eg:- given an array = [50, 30, 40, 10, 5, 20, 30] if we draw this array in tree format then we will know that it will form a maxHeap
// we can make a tree from the given array by the property that the element at index 2*i+1 will be the left child and the element at index 2*i+2 will be the right child of ith element

//*Insert an element in a maxHeap
void insertMaxHeap(vector<int> &v, int key)
{
    v.push_back(key);
    int n = v.size();
    int i = n - 1;
    while (i > 0)
    {
        if (i % 2 == 0)
        {
            if (v[i] > v[(i / 2) - 1])
            {
                swap(v[i], v[(i / 2) - 1]);
                i /= 2;
                i--;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (v[i] > v[i / 2])
            {
                swap(v[i], v[i / 2]);
                i /= 2;
            }
            else
            {
                break;
            }
        }
    }
}

//*Insert an element in a minHeap
void insertMinHeap(vector<int> &v, int key)
{
    v.push_back(key);
    int n = v.size();
    int i = n - 1;
    while (i > 0)
    {
        if (i % 2 == 0)
        {
            if (v[i] < v[(i / 2) - 1])
            {
                swap(v[i], v[(i / 2) - 1]);
                i /= 2;
                i--;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (v[i] < v[i / 2])
            {
                swap(v[i], v[i / 2]);
                i /= 2;
            }
            else
            {
                break;
            }
        }
    }
}

//*In heap we can delete only root node
//* Deletion in MaxHeap
void deleteMaxHeap(vector<int> &v)
{
    int n = v.size();
    v[0] = v[n - 1];
    v.pop_back();
    n = n - 1;
    for (int i = 0; i < n; i++)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && v[l] > v[i])
        {
            swap(v[l], v[i]);
        }
        if (r < n && v[r] > v[i])
        {
            swap(v[r], v[i]);
        }
    }
}

//* Deletion in MinHeap
void deleteMinHeap(vector<int> &v)
{
    int n = v.size();
    v[0] = v[n - 1];
    v.pop_back();
    n = n - 1;
    for (int i = 0; i < n; i++)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && v[l] < v[i])
        {
            swap(v[l], v[i]);
        }
        if (r < n && v[r] < v[i])
        {
            swap(v[r], v[i]);
        }
    }
}

int main()
{
    vector<int> v;
    int maxHeap[] = {36, 32, 34, 30, 5, 33, 31};
    // int minHeap[] = {10, 30, 20, 50, 40, 30, 70};
    for (int i = 0; i < 7; i++)
    {
        v.push_back(maxHeap[i]);
    }
    // insertMaxHeap(v, 60);
    // insertMaxHeap(v, 45);
    // insertMinHeap(v, 5);
    // insertMinHeap(v, 20);
    deleteMaxHeap(v);
    // deleteMinHeap(v);
    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}