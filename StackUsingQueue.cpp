//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <queue>
using namespace std;

//*Form a stack using queues (don't implement stack i.e. stack<int>st)
//First Method
class Stack {
    
    queue<int> primary_queue, secondary_queue;
    
    public:
        void push(int element){
            
            // enqueue in secondary_queue
            secondary_queue.push(element);
            
            // add elements of primary_queue to secondary_queue
            while(!primary_queue.empty()){
                secondary_queue.push(primary_queue.front());
                primary_queue.pop();
            }
            
            // swapping the queues
            queue<int> temp_queue = primary_queue;
            primary_queue = secondary_queue;
            secondary_queue = temp_queue;
        }
    
        void pop(){
            if(primary_queue.empty()){
                return;
            } else {
                primary_queue.pop();
            }
        }
    
        int top(){
            if(primary_queue.empty()){
                return -1;
            } else {
                return primary_queue.front();
            }
        }
    
        void displayStack()
        {
            queue<int> temp_queue = primary_queue;
            
            while(!temp_queue.empty()){
                cout<<temp_queue.front()<<" ";
                temp_queue.pop();
            }
            cout<<"\n";
            
        }
};

//Second Method
class Stack1{
    queue<int>q1;
    queue<int>q2;
    public:

    void push(int val){
        q1.push(val);
    }

    void pop(){
        if (q1.empty())
        {
            cout<<"stack is empty"<<endl;
            return;
        }
        while (q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        queue<int>temp=q1;
        q1=q2;
        q2=temp;
    }

    int top(){
        if (q1.empty())
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        while (q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int topval = q1.front();
        q2.push(topval);
        queue<int>temp=q1;
        q1=q2;
        q2=temp;

        return topval;
    }
};

int main(){
    
    Stack s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    s.displayStack();
    
    cout<<"Top: "<<s.top()<<"\n";
    
    s.pop();
    
    s.displayStack();

    Stack1 s1;
    
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    
    cout<<"Top: "<<s1.top()<<"\n";
    
    s1.pop();
    
    cout<<"Top: "<<s1.top()<<"\n";
    return 0;
    
}