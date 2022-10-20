//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//*Q1.Rain Water Trapping Problem solved by finding max element in left array & max element in right array
//First Method (without using stack)
int RainWaterTrapping(vector<int> v){
    vector<int>mxl(v.size());
    vector<int>mxr(v.size());
    mxl[0] = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        mxl[i] =  max(mxl[i-1],v[i]); 
    }
    mxr[mxr.size()-1] = v[v.size()-1];
    for (int i = v.size()-2; i >= 0; i--)
    {
        mxr[i] = max(mxr[i+1],v[i]);
    }
    vector<int> water(v.size());
    int sum=0;
    for (int i = 0; i < v.size(); i++)
    {
        water[i] = min(mxl[i],mxr[i])-v[i];
        sum += water[i];
    }
    return sum;
}

//Second Method (using stack)
int RainWaterTrapping(vector<int> v){
    stack<int>st;
    int n = v.size(),sum=0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && v[st.top()]<v[i])
        {
            int cur = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            int diff = i - st.top() - 1;
            sum += (min(v[st.top()],v[i]) - v[cur])*diff;
        }
        st.push(i);
    }
    return sum;
}

//*Q2.Minimum element in stack with extra space
int minElement(stack<int> st){
    stack<int>st1;
    if (st.empty())
    {
        return -1;
    }
    
    while (!st.empty())
    {
        if (st1.empty() || st1.top()>st.top())
        {
            if (!st1.empty())
            {
                st1.pop();
            }
            st1.push(st.top());
        }
        st.pop();
    }
    return st1.top();
}

//*Q3.Minimum element in stack without using extra space
int minElement1;
stack<int>s;

int getMin(){
    if (s.size()==0)
    {
        return -1;
    }
    return minElement1;
}

void push(int x){
    if (s.size()==0)
    {
        s.push(x);
        minElement1=x;
    }else{
        if (x>=minElement1)
        {
            s.push(x);
        }else if (x<minElement1){
            s.push(2*x-minElement1);
            minElement1=x;
        }
    }
}

void pop(){
    if (s.size()==0)
    {
        return;
    }else
    {
        if (s.top()>=minElement1)
        {
            s.pop();
        }else if(s.top()<minElement1){
            minElement1=2*minElement1-s.top();
            s.pop();
        }
    }
}

int top(){
    if (s.size()==0)
    {
        return -1;
    }else{
        if (s.top()>=minElement1)
        {
            return s.top();
        }else if (s.top()<minElement1)
        {
            return minElement1;
        }
    }
}

//*Redundant Parenthesis
int RedundantParenthesis(string s){
    stack<char>st;
    int count=0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
            st.push(s[i]);
        }else if(s[i]==')')
        {
            if (st.top()=='(')
            {
                count++;
            }
            while(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/'){
                st.pop();
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &it : v) cin>>it;
    cout<<RainWaterTrapping(v)<<endl;

//*Q2.
    stack<int> st;
    for(auto &it: v){
        cin>>it;
        st.push(it);    
    }
    st.pop();
    cout<<minElement(st);     

    string s="((a+b))";
    cout<<RedundantParenthesis(s)<<endl;
    return 0;
}