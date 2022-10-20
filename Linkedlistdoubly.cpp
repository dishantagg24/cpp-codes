//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//*Initialisation of a doubly linkedlist
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

//*Insert a node at head in doubly linkedlist
void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    if (head!=NULL)
    {
        head->prev=n;
    }
    head=n;
}

//*Insert a node at tail in doubly linkedlist
void insertAtTail(node* &head,int val){
    if (head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    
    node* n = new node(val);
    node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

//*To print doubly linkedlist
void print(node* &head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//*To delete a node at head in doubly linkedlist
void deleteAtHead(node* &head){
    node* temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
}

//*To delete a node at a given position in doubly linkedlist
void deletion(node* &head,int pos){
    if (pos==1)
    {
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=0;
    while (temp->next!=NULL&&count<pos)
    {
        temp=temp->next;
        count++;
    }
    node* todelete=temp->next;
    temp->prev->next=temp->next;
    if (temp->next!=NULL)
    {
       temp->next->prev=temp->prev;
    }
    
    delete temp;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    print(head);
    insertAtHead(head,6);
    print(head);
    deletion(head,2);
    print(head);
    deleteAtHead(head);
    print(head);
    return 0;
}