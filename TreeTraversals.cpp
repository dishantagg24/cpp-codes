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

int search(int inorder[], int curr, int st, int en){
    for (int i = st; i <= en; i++)
    {
        if (curr==inorder[i])
        {
            return i;
        }
    }
    return -1;    
}

//*Build tree using preorder and inorder elements
Node* buildTree1(int preorder[],int inorder[], int st, int en){
    static int idx=0;
    if (st>en)
    {
        return NULL;
    }
    
    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);
    if(st==en){
        return node;
    }
    int pos = search(inorder,curr,st,en);
    node->left = buildTree1(preorder,inorder,st,pos-1);
    node->right = buildTree1(preorder,inorder,pos+1,en);

    return node;
}

//*Build tree using postorder and inorder elements
Node* buildTree2(int postorder[],int inorder[],int st,int en){
    static int idx=en;

    if (st>en)
    {
        return NULL;
    }

    int curr = postorder[idx];
    idx--;
    Node* node = new Node(curr);
    if(st==en){
        return node;
    }
    int pos = search(inorder,curr,st,en);
    node->right = buildTree2(postorder,inorder,pos+1,en);
    node->left = buildTree2(postorder,inorder,st,pos-1);

    return node;

}

//*To Print tree in inorder
void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }    
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

//*To Print elements of every level 
void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
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
}

int main(){
    int preorder[]={1,2,4,3,5};
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};

    // Node* root1=buildTree1(preorder,inorder,0,4);
    // Node* root1=buildTree2(postorder,inorder,0,4);
    // inorderPrint(root1);

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    levelOrderTraversal(root);
    return 0;
}