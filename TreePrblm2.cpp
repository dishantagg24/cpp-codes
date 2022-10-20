//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

//*To replace the data of root node with sum of its value and its subtrees value
void SumReplacement(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    SumReplacement(root->left);
    SumReplacement(root->right);
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
    return;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight) + 1;
}

//*To check a Tree is balanced or not (a tree is balanced if absolute differnce of left height and right height is less than or equal to 1 for every node)
// Time Complexity O(n^2) {Not Optimised}
bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isBalanced(root->left) == false)
    {
        return false;
    }
    if (isBalanced(root->right) == false)
    {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    return false;
}

// Time Complexity O(n) {Optimised}
bool isBalanced1(Node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if (isBalanced1(root->left, &lh) == false)
    {
        return false;
    }
    if (isBalanced1(root->right, &rh) == false)
    {
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preorder(root);
    cout << "\n";
    SumReplacement(root);
    preorder(root);

    int height = 0;
    if (isBalanced1(root, &height) == true)
    {
        cout << "balanced tree"
             << "\n";
    }
    else
    {
        cout << "unbalanced tree"
             << "\n";
    }
    return 0;
}