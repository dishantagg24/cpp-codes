//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//*Initialisation of a list
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

//*Insert a element at end of list
void insertAtTail(node* &head,int val){
    node* n = new node(val);
    if (head==NULL)
    {
        n->next=NULL;
        head=n;
        return;
    }
    node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;
}

//*To print the list
void print(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//*Reverse a linkedlist (Iterative Method)
node* reverse(node* &head){
    node* currptr=head;
    node* prevptr=NULL;
    node* nextptr;

    while (currptr!=NULL)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

//*Reverse a linkedlist (Recursive Method)
node* revRecursive(node* head){
    if (head==NULL||head->next==NULL)
    {
        return head;
    }
    
    node* newhead=revRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

//*Reverse K nodes of linkeldist (Recursive Method)
node* revKnodes(node* & head, int k){
    node* currptr=head;
    node* prevptr=NULL;
    node* nextptr;
    int count=0;
    while (currptr!=NULL && count<k)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if (nextptr!=NULL)
    {
        head->next=revKnodes(nextptr,k);
    }
    
    return prevptr;
}
int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    print(head);
    // node* newhead=reverse(head);
    // node* newhead=revRecursive(head);
    // print(newhead);
    node* newhead=revKnodes(head,2);
    print(newhead);
    return 0;
}