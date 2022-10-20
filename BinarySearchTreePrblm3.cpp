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

Node *BuildBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (root->data > val)
    {
        root->left = BuildBST(root->left, val);
    }
    else
    {
        root->right = BuildBST(root->right, val);
    }
    return root;
}

//*Largest size of BST in a Binary Tree
struct info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

info LargestBST(Node *root)
{
    if (root == NULL)
    {
        return {0, INT_MAX, INT_MIN, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }
    info leftTree = LargestBST(root->left);
    info rightTree = LargestBST(root->right);
    info curr;
    curr.size = 1 + leftTree.size + rightTree.size;
    if (leftTree.isBST && rightTree.isBST && leftTree.max < root->data && root->data < rightTree.min)
    {
        curr.min = min(leftTree.min, min(rightTree.min, root->data));
        curr.max = max(leftTree.max, max(rightTree.max, root->data));
        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(leftTree.ans, rightTree.ans);
    curr.isBST = false;
    return curr;
}

//*Recover Binary Search Tree
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointers(Node *root, Node **first, Node **last, Node **prev, Node **mid)
{
    if (root == NULL)
    {
        return;
    }
    calcPointers(root->left, first, last, prev, mid);
    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcPointers(root->right, first, last, prev, mid);
}

void restoreBST(Node *root)
{
    Node *first = NULL;
    Node *last = NULL;
    Node *prev = NULL;
    Node *mid = NULL;

    calcPointers(root, &first, &last, &prev, &mid);

    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else
    {
        swap(&(first->data), &(mid->data));
    }
}

int main()
{
    Node *root = NULL;
    root = BuildBST(root, 10);
    root = BuildBST(root, 12);
    root = BuildBST(root, 13);
    root = BuildBST(root, 11);
    root = BuildBST(root, 1);
    root = BuildBST(root, 3);
    root = BuildBST(root, 2);
    root = BuildBST(root, 4);
    root = BuildBST(root, 6);
    root = BuildBST(root, 7);
    root = BuildBST(root, 8);

    return 0;
}