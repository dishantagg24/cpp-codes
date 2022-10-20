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

//*Insert a element at head of list
void insertAtHead(node* &head,int val){
    node* n =new node(val);
    n->next=head;
    head=n;
}


//*Insert a element at end of list
void insertAtTail(node* &head,int val){
    node* n= new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    
}

//*To determine the length of linkedlist
int length(node* head){
    int count=0;
    node* temp=head;
    while (temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

//*To append k nodes at head of linkedlist
node* appendKnodes(node* &head,int k){
    node* tail=head;
    node* newHead;
    node* newTail;
    int l=length(head);
    k=k%l;
    int count=1;
    while (tail->next!=NULL)
    {
        if (count==l-k)
        {
            newTail=tail;
        }
        if (count==l-k+1)
        {
            newHead=tail;
        }
        count++;
        tail=tail->next;
    }
    tail->next=head;
    newTail->next=NULL;
    return newHead;
}

//*To print the linkedlist
void display(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//*To determine the value of node at which two linkedlist intersect 
int intersect2point(node* head1,node* head2){
    node* ptr1;
    node* ptr2;
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    if (l1>l2)
    {
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while (d)
    {
        ptr1=ptr1->next;
        if (ptr1==NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1!=NULL && ptr2!=NULL)
    {
        if (ptr1==ptr2)
        {
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;   
    }
    return -1;
}

//*To intersect two linkedlist
void intersect(node* &head1,node* &head2,int pos){
    node* temp1=head1;
    pos--;
    while (pos--)
    {
        temp1=temp1->next;
    }
    node* temp2=head2;
    while (temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
int main(){
    // node* head=NULL;
    // insertAtTail(head,1);
    // insertAtTail(head,2);
    // insertAtTail(head,3);
    // insertAtTail(head,4);
    // insertAtTail(head,5);
    // insertAtTail(head,6);
    // display(head);
    // node* newHead = appendKnodes(head,3);
    // display(newHead);
    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    insertAtTail(head1,7);
    insertAtTail(head2,3);
    insertAtTail(head2,5);
    intersect(head1,head2,3);
    cout<<intersect2point(head1,head2)<<endl;
    display(head1);
    display(head2);
    return 0;
}