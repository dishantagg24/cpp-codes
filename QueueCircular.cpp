//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define n 5


class queue{
    int* arr;
    int front;
    int rear;
    public:
    
    queue(){
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool isempty(){
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }

    void enqueue(int val){
        if((rear+1)%n==front){
            cout<<"Queue overflow"<<endl;
        }else
        {
            if (front == -1)
            {
                front++;
            }
            rear = (rear+1)%n;
            arr[rear] = val;
        }
    }

    void dequeue(){
        if (isempty())
        {
            cout<<"Queue is empty\n";
        }else{
            if (front==rear)
            {
                rear = -1;
                front = rear;
            }else
            {
                front = (front+1)%n;   
            }
        }
    }

    void showFront(){
        if (isempty())
        {
            cout<<"Queue is empty\n";
        }else
        {
            cout<<"element at front is: "<<arr[front];
        }
    }

    void displayQueue(){
        if (isempty())
        {
            cout<<"Queue is empty\n";
        }else
        {
            int i;
            if (front <= rear)
            {
                for (i = front; i <= rear; i++)
                {
                    cout<<arr[i]<<" ";
                }
            }else
            {
                i=front;
                while (i<n)
                {
                    cout<<arr[i]<<" ";
                    i++;
                }
                i=0;
                while (i<=rear)
                {
                    cout<<arr[i]<<" ";
                    i++;
                }
            }
        }
    }

};
int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.showFront();
    cout<<"\n";
    q.dequeue();
 
    q.showFront();
    cout<<"\n";
    q.dequeue();

    cout<<q.isempty()<<endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(4);
    q.displayQueue();
    cout<<"\n";
    q.enqueue(5);

    return 0;
}