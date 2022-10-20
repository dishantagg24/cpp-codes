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
//*Insert a node at a given position
void insert(node* &head,int val,int pos){
    node* n=new node(val);
    if(pos==1){
        n->next=head;
        head=n;
        return;
    }
    node* temp=head;
    for (int i = 0; i < pos-2; i++)
    {
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}
//*To print the list
void display(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//*To search an element in a list
bool search(node* head,int key){
    node* temp=head;
    while (temp!=NULL)
    {
        if (temp->data==key)
        {
            return true;
        }
        
        temp=temp->next;
    }
    return false;
}
//*To delete a node from list 
void deletion(node* &head,int val){
    node* temp=head;
    while (temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
    
}

//*To delete the first node
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}

//*To delete a node at a given position
void deleteatpos(node* &head,int pos){
    node* temp=head;
    if(pos==1){
        head=temp->next;
        delete temp;
        return;
    }
    for(int i=0;i<pos-2;i++){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,4);
    display(head);
    cout<<search(head,5)<<endl;
    cout<<search(head,3)<<endl;
    // deletion(head,3);
    deleteAtHead(head);
    display(head);
    return 0;
}