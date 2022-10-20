//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    int data;
    Node *link; 
};

Node *front = NULL;
Node *rear = NULL;

bool isempty(){
    if (front==NULL && rear==NULL)
    {
        return true;
    }
    return false;
}

void enqueue(int val){
    Node* ptr = new Node();
    ptr->data = val;
    ptr->link = NULL;

    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
    }else
    {
        rear->link = ptr;
        rear = ptr;
    }
}

void dequeue(){
    if (isempty())
    {
        cout<<"Queue is empty";
    }else
    {
        if (front == rear)
        {
            free(front);
            rear = NULL;
            front = rear;
        }
        else
        {
            Node *ptr = front;
            front = front->link;
            free(ptr);
        }
    }
}

void showFront(){
    if (isempty())
    {
        cout<<"Queue is empty";
    }else
    {
        cout<<front->data;
    }
}

void displayQueue(){
    if (isempty())
    {
        cout<<"Queue is empty";
    }else
    {
        Node *ptr = front;
        while (ptr != NULL)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->link;
        }
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    showFront();
    cout<<"\n";
    dequeue();
 
    showFront();
    cout<<"\n";
    dequeue();

    cout<<isempty()<<endl;
    enqueue(1);
    enqueue(2);
    enqueue(4);
    displayQueue();
    cout<<"\n";
    enqueue(5);

    return 0;
}