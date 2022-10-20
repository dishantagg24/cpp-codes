//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//*To find shortest root to node path**********************************8
bool getPath(Node *root, vector<int> &ans, int n)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(root->data);
    if (root->data == n)
    {
        return true;
    }
    bool LeftT = getPath(root->left, ans, n);
    bool RightT = getPath(root->right, ans, n);
    if (LeftT || RightT)
    {
        return true;
    }
    ans.pop_back();
    return false;
}

vector<int> RootToNode(Node *root, int n)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    getPath(root, ans, n);
    return ans;
}

//*Distance Between Two Nodes**************************************
int findDist(Node *root, int n, int dist)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == n)
    {
        return dist;
    }
    int leftT = findDist(root->left, n, dist + 1);
    if (leftT != -1)
    {
        return leftT;
    }
    int rightT = findDist(root->right, n, dist + 1);
    return rightT;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left = new Node(5);
    // vector<int> res = RootToNode(root, 6);
    // for (auto it : res)
    // {
    //     cout << it << " ";
    // }
    cout << findDist(root, 6, 0);
    return 0;
}