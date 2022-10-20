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

//*To Merge two sorted linkedlist using iterative method
node* merge(node* head1,node* head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* dummyNode =new node(-1);
    node* ptr3= dummyNode;
    while (ptr1!=NULL&&ptr2!=NULL)
    {
        if (ptr1->data<ptr2->data)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    while (ptr1!=NULL)
    {
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while (ptr2!=NULL)
    {
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    return dummyNode->next;
}

//*To merge two sorted linkedlist using recursion
node* mergeRecursive(node* &head1,node* &head2){
    if (head1==NULL)
    {
        return head2;
    }
    if (head2==NULL)
    {
        return head1;
    }
    
    node* result;
    if (head1->data>head2->data)
    {
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }else{
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    return result;
}

//*Put even position nodes after odd position nodes
void oddEven(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenStart=even;
    while (odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    if (odd->next==NULL)
    {
        even->next=NULL;
    }
    odd->next=evenStart;
}

//*To delete a node in a linkedlist(not given access to the head of the list but given access to the node to be deleted directly)
void deleteNode(node* newNode){
    node* temp=newNode;
    newNode->data=temp->data;
    newNode->next=temp->next;
    delete temp;
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
int main(){
    // node* head1=NULL;
    // node* head2=NULL;
    // int arr1[]={1,4,5,7};
    // int arr2[]={2,3,6};
    // for (int i = 0; i < 4; i++)
    // {
    //     insertAtTail(head1,arr1[i]);
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     insertAtTail(head2,arr2[i]);
    // }
    // display(head1);
    // display(head2);
    // node* newHead=merge(head1,head2);
    // node* newHead=mergeRecursive(head1,head2);
    // display(newHead);

    node* head=NULL;
    int arr[]={1,2,3,4,5,6};
    for (int i = 0; i < 6; i++)
    {
        insertAtTail(head,arr[i]);
    }
    oddEven(head);
    display(head);
    return 0;
}