//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
using namespace std;
#define ll long long
#define n 100

class stack{

    int* arr;
    int top;
    public:

    stack(){
        arr = new int[n];
        top = -1;
    }
    void push(int x){
        if(top==n-1){
            cout<<"Stack overflow\n";
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if (top==-1)
        {
            cout<<"No element in stack\n";
            return;
        }
        top--;
    }
    int Top(){
        if (top==-1)
        {
            cout<<"No element in stack\n";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }
};
int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    cout<<st.isEmpty()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.isEmpty()<<endl;
    return 0;
}