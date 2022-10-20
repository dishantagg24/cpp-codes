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

//*Build balanced BST from given sorted array
Node *ConstructBalancedBST(int arr[], int st, int en)
{
    if (en < st)
    {
        return NULL;
    }
    int mid = (st + en) / 2;
    Node *root = new Node(arr[mid]);
    root->left = ConstructBalancedBST(arr, st, mid - 1);
    root->right = ConstructBalancedBST(arr, mid + 1, en);
    return root;
}

//*Catalan Numbers are a sequence of natural nos. that occur in various counting problems, often involving recursively defined objects.
//*c0 = 1 and c1 = 1 and c2 = c0*c1 + c1*c0 and c3 = c0*c2 + c1*c1 + c2*c0 and c4, c5, c6 are also calculated like this.
//*Applications of Catalan Numbers
// 1. Possible BSTs
// 2. Parenthesis / bracket combinations
// 3. Possible forests
// 4. Ways of triangulations
// 5. Possible paths in matrix
// 6. Dividing a circle using N chords
// 7. Dyck words of given length & much more

//*To find nth Catalan Number
int catalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += catalan(i) * catalan(n - i - 1);
    }

    return ans;
}

//*Print all Possible BSTs for a given n value n->no of nodes
vector<Node *> ConstructTrees(int start, int end)
{
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSubTree = ConstructTrees(start, i - 1);
        vector<Node *> rightSubTree = ConstructTrees(i + 1, end);
        for (int j = 0; j < leftSubTree.size(); j++)
        {
            Node *left = leftSubTree[j];
            for (int k = 0; k < rightSubTree.size(); k++)
            {
                Node *right = rightSubTree[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
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

//*Zigzag Traversal of Binary Tree
void zigzag(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> currLevel;
    stack<Node *> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);
    while (!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();

        if (temp)
        {
            cout << temp->data << " ";
            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        if (currLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }

    return;
}

//*Given two roots of two BSTs, check whether they are identical or not
bool isIdenticalBST(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
    {
        return false;
    }
    if (root1->data == root2->data)
    {
        return isIdenticalBST(root1->left, root2->left) && isIdenticalBST(root1->right, root2->right);
    }
    return false;
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

    vector<Node *> totalTrees = ConstructTrees(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << (i + 1) << " : ";
        preorder(totalTrees[i]);
        cout << endl;
    }

    return 0;
}