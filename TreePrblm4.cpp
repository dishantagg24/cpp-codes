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

//*To find LCA(Lowest Common Ancestor) between two nodes
// There are two methods
// 1.To find rootToNode path for the given two nodes (we did the similar prblm in TreePrblm3.cpp) and store them in two vectors and then compare the two vectors, from where change occurs the element before it, is LCA. (Not Optimised)
// 2.Compare the node values

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *LeftLCA = LCA(root->left, n1, n2);
    Node *RightLCA = LCA(root->right, n1, n2);
    if (LeftLCA && RightLCA)
    {
        return root;
    }
    if (LeftLCA != NULL)
    {
        return LeftLCA;
    }
    return RightLCA;
}

//*Shortest distance between Two Nodes
// Steps:
// 1.Find LCA between these two nodes
// 2.Find distance d1 between LCA & n1 and distance d2 between LCA & n2 (using findDist method we have done in TreePrblm3.cpp)
// 3. Return d1+d2;

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left = new Node(5);
    Node *LCA2Nodes = LCA(root, 5, 6);
    cout << LCA2Nodes->data << "\n";
    return 0;
}