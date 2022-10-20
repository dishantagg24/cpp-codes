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

//*Delete in Binary Search Tree***************************
Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node *deleteinBST(Node *root, int key)
{
    if (root->data < key)
    {
        root->right = deleteinBST(root->right, key);
    }
    else if (root->data > key)
    {
        root->left = deleteinBST(root->left, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteinBST(root->right, temp->data);
    }
    return root;
}

//*Construct BST from given preorder array
Node *constructBST(int preorder[], int *preorderidx, int key, int min, int max, int n)
{
    if (*preorderidx >= n)
    {
        return NULL;
    }
    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderidx = *preorderidx + 1;
        if (*preorderidx < n)
        {
            root->left = constructBST(preorder, preorderidx, preorder[*preorderidx], min, key, n);
        }
        if (*preorderidx < n)
        {
            root->right = constructBST(preorder, preorderidx, preorder[*preorderidx], key, max, n);
        }
    }
    return root;
}

//*Check if a given tree is BST or not
bool CheckBST(Node *root, Node *max, Node *min)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }
    bool leftValid = CheckBST(root->left, root, min);
    bool rightValid = CheckBST(root->right, max, root);
    return leftValid && rightValid;
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
    root = deleteinBST(root, 3);
    return 0;
}