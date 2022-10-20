//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//*Initialisation of a linkedlist
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

//*Insert a node at head of circular linkeldist
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    if (head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

//*Insert a node at tail of circular linkedlist
void insertAtTail(node* &head,int val){
    if (head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

//*To delete a node at head in circular linkedlist
void deleteAtHead(node* &head){
    node* temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    node* todelete=head;
    temp->next=head->next;
    head=head->next;
    delete todelete;
}

//*To delete a node at a given position in circular linkedlist
void deletion(node* &head,int pos){
    if (pos==1)
    {
        deleteAtHead(head);
        return;
    }
    int count=1;
    node* temp=head;
    while (count!=pos-1)
    {
        temp=temp->next;
        count++;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

//*To print circular linkedlist
void display(node* head){
    node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);
    cout<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    deletion(head,5);
    display(head);
    deleteAtHead(head);
    display(head);
    return 0;
}