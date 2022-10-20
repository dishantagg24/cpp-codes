//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Inorder traversal of BST always produces sorted output.
//*We can construct a BST with only Preorder or Postorder or Level Order traversal.
//*Note that we can always get inorder traversal by sorting the only given traversal.

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

//*Insertion in Binary Search Tree
Node *BinarySearchTree(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = BinarySearchTree(root->left, val);
    }
    else
    {
        root->right = BinarySearchTree(root->right, val);
    }
    return root;
}

//*Search In Binary Search Tree***************************
bool Search(Node *root, int k)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == k)
    {
        return true;
    }
    bool RightT = false, leftT = false;
    if (root->data < k)
    {
        RightT = Search(root->right, k);
    }
    else
    {
        leftT = Search(root->left, k);
    }
    return leftT || RightT;
}

//*Inorder Successor of given value***********************
void inorderSucc(Node *root, int val, int &succ)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data == val)
    {
        inorderSucc(root->right, val, succ);
    }
    else if (root->data > val)
    {
        succ = root->data;
        inorderSucc(root->left, val, succ);
    }
    else
    {
        inorderSucc(root->right, val, succ);
    }
}

//*Inorder Successor of root***************************
Node *inorderSuccOfRoot(Node *root)
{
    Node *curr = root->right;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

//*Inorder Predecessor of given value***********************
void inorderPre(Node *root, int val, int &pre)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == val)
    {
        inorderPre(root->left, val, pre);
    }
    else if (root->data > val)
    {
        inorderPre(root->left, val, pre);
    }
    else
    {
        pre = root->data;
        inorderPre(root->right, val, pre);
    }
}

//*Inorder Predecessor of root***************************
Node *inorderPreOfRoot(Node *root)
{
    Node *curr = root->left;
    while (curr && curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr;
}

int main()
{
    int arr[] = {5, 1, 3, 4, 2, 7};
    Node *root = NULL;
    root = BinarySearchTree(root, 5);
    BinarySearchTree(root, 1);
    BinarySearchTree(root, 3);
    BinarySearchTree(root, 4);
    BinarySearchTree(root, 2);
    BinarySearchTree(root, 7);
    int pre = 0;
    inorderPre(root, 4, pre);
    // cout << pre;
    Node *inorderPreRoot = inorderPreOfRoot(root);
    cout << inorderPreRoot->data;
    return 0;
}