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

//*Insert an element in a list
void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if (head==NULL)
    {
        head=n;
        n->next=NULL;
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

//*To print a linkedlist
void print(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//*Making a cycle in linkedlist from end point to given position
void makeCycle(node* &head,int pos){
    int count=0;
    node* startNode;
    node* temp=head;
    while (temp->next!=NULL)
    {
        if (count==pos)
        {
            startNode=temp;
        }
        
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

//*To detect if a cycle is present or not
bool detectCycle(node* head){
    node* fastptr=head;
    node* slowptr=head;
    while (fastptr!=NULL && fastptr->next!=NULL)
    {
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
        if (fastptr==slowptr)
        {
            return true;
        }
    }
    return false;
}

//*To remove cycle from linkedlist (it is assumed that cycle is already present)
void removeCycle(node* &head){
    node* fastptr=head;
    node* slowptr=head;
    do
    {
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
    } while (fastptr!=slowptr);
    fastptr=head;
    while (fastptr->next!=slowptr->next)
    {
        fastptr=fastptr->next;
        slowptr=slowptr->next;
    }
    slowptr->next=NULL;
}
int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    print(head);
    makeCycle(head,3);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    print(head);
    return 0;
}