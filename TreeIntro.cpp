//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Properties of Binary Trees
1. Maximum nodes at Level L = 2^L
2. Maximum nodes in a tree of height H is 2^H-1
3. For N nodes, minimum possible height or minimum number of levels are log2(N+1)
4. A binary tree with L leaves has at least log2(N+1)+1 number of level  */
// we can make a tree from the given array by the property that the element at index 2*i+1 will be the left child and the element at index 2*i+2 will be the right child of ith element
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
Root
Left Subtree
Right Subtree */
// Using Recursive Method
void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Using Iterative Method
void preorder1(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        cout << root->data << " ";
        if (root->right != NULL)
        {
            st.push(root->right);
        }
        if (root->left != NULL)
        {
            st.push(root->left);
        }
    }
}

/*
Left Subtree
Root
Right Subtree */
// Using recursive method
void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Using Iterative Method
void inorder1(struct Node *root)
{
    stack<Node *> st;
    while (1)
    {
        if (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            root = st.top();
            st.pop();
            cout << root->data << " ";
            root = root->right;
        }
    }
}

/*
Left Subtree
Right Subtree
Root          */
// Using recursive Method
void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Using Iterative Method
// Using extra space like another stack or vector
void postorder1(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> st;
    stack<int> st1;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        st1.push(root->data);
        if (root->left != NULL)
        {
            st.push(root->left);
        }
        if (root->right != NULL)
        {
            st.push(root->right);
        }
    }
    while (!st1.empty())
    {
        cout << st1.top() << " ";
        st1.pop();
    }
}

// Using only 1 stack
void postorder2(struct Node *root)
{
    struct Node *current = root;
    stack<Node *> st;
    while (current != NULL || !st.empty())
    {
        if (current != NULL)
        {
            st.push(current);
            current = current->left;
        }
        else
        {
            Node *temp = st.top();
            if (temp->right != NULL)
            {
                current = temp->right;
            }
            else
            {
                cout << temp->data << " ";
                st.pop();
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
        }
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    /*
        1
       / \
      2  3    */

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    /*
         1
       /   \
      2     3
    /  \   / \
   4    5 6   7     */
    preorder(root);
    cout << "\n";
    preorder1(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    inorder1(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    postorder1(root);
    cout << "\n";
    postorder2(root);
    cout << "\n";
    return 0;
}