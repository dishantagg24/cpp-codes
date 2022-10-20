//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

//*Sum of all nodes at Kth Level In Binary Tree
//Unofficial Method
int Sum1(Node* root, int k){
    if(root==NULL){
        return -1;
    }
    int count=0;
    int sum=0;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(count<=k){
        Node* node = q.front();
        q.pop();
        if(node!=NULL){
            sum+=node->data;
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }else if(!q.empty()){
            if(count==k){
                return sum;
            }
            count++;
            sum=0;
            q.push(NULL);
        }
    }
    return sum;
}

//Official Method
int Sum2(Node* root, int k){
    if(root==NULL){
        return -1;
    }
    int count=0;
    int sum=0;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node!=NULL){
            if(count==k){
                sum+=node->data;
            }
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }else if(!q.empty()){
            q.push(NULL);
            count++;
        }
    }
    return sum;
}

//*Count all the nodes in a binary tree
//Unofficial Method
int count(Node* root){
    if(root==NULL){
        return -1;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    int ans=0;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if (node!=NULL)
        {
            ans++;
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }else if(!q.empty()){
            q.push(NULL);
        }
    }
    return ans;
}

//Official Method
int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

//*Sum of all nodes in a binary tree
int Sum(Node* root){
    if(root==NULL){
        return 0;
    }
    return Sum(root->left) + Sum(root->right) + root->data;
}

//*Height of binary tree (distance between root and deepest node)
int Height(Node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight = Height(root->left);
    int rHeight = Height(root->right);

    return max(lHeight,rHeight) + 1;
}

//*To calculate Diameter in Binary Tree (Longest distance b/w two leaves)
//Time Complexity O(n^2) {Not Optimised}
int calcDiameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight = Height(root->left);
    int rHeight = Height(root->right);
    int currDiameter =  lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter,max(lDiameter,rDiameter));
}
//Time Complexity O(n) {Optimised}
int calcDiameter(Node* root, int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh = 0;
    int rh = 0;
    int lDiameter = calcDiameter(root->left,&lh);
    int rDiameter = calcDiameter(root->right,&rh);

    int currDiameter =  lh + rh + 1;
    *height = max(lh,rh) + 1;

    return max(currDiameter,max(lDiameter,rDiameter));
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<Sum2(root,2)<<"\n";
    cout<<count(root)<<"\n";
    cout<<countNodes(root)<<"\n";
    cout<<Sum(root)<<"\n";
    cout<<Height(root)<<"\n";
    return 0;
}