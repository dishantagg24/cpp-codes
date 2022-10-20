//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

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

//*Dp on Trees
// Calculate Diameter
// Max Path Sum between any nodes
// Max Path Sum leaf node to leaf node
int calcDiameter(Node *root, int &res)
{
    if (root == NULL)
    {
        return 0;
    }
    int lDiameter = calcDiameter(root->left, res);
    int rDiameter = calcDiameter(root->right, res);
    int temp = max(lDiameter, rDiameter) + 1;
    int ans = max(temp, 1 + lDiameter + rDiameter);
    res = max(ans, res);
    return temp;
}

int maxPathSum(Node *root, int &res)
{
    if (root == NULL)
    {
        return 0;
    }
    int lSum = maxPathSum(root->left, res);
    int rSum = maxPathSum(root->right, res);
    int temp = max(max(lSum, rSum) + root->data, root->data);
    int ans = max(temp, root->data + lSum + rSum);
    res = max(ans, res);
    return temp;
}

int maxPathSumLeaf2Leaf(Node *root, int &res)
{
    if (root == NULL)
    {
        return 0;
    }
    int lSum = maxPathSumLeaf2Leaf(root->left, res);
    int rSum = maxPathSumLeaf2Leaf(root->right, res);
    int temp = max(lSum, rSum) + root->data;
    if (root->left == NULL && root->right == NULL)
    {
        temp = max(temp, root->data);
    }
    int ans = max(temp, root->data + lSum + rSum);
    res = max(ans, res);
    return temp;
}

int main()
{
    Node *root = new Node(5);
    return 0;
}