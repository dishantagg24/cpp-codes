//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> NextGreaterToRight(vector<int> v){
    vector<int> ans;
    stack<int> st;
    for (int i = v.size()-1; i >=0 ; i--)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }else if(st.size()>0 && st.top()>v[i]){
            ans.push_back(st.top());
        }else if (st.size()>0 && st.top()<=v[i])
        {
            while(!st.empty() && st.top()<=v[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(st.top());
            }
        }
        st.push(v[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<int> NextGreaterToLeft(vector<int> v){
    vector<int> ans;
    stack<int>st;
    for (int i = 0; i < v.size(); i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }else if (st.size()>0 && st.top()>v[i])
        {
            ans.push_back(st.top());
        }else if (st.size()>0 && st.top()<=v[i])
        {
            while (!st.empty() && st.top()<=v[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(-1);
            }else
            {
                ans.push_back(st.top());
            }
        }
        st.push(v[i]);
    }
    return ans;
}

vector<int> NextSmallerToLeft(vector<int> v){
    vector<int> ans;
    stack<int>st;
    for (int i = 0; i < v.size(); i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }else if (st.size()>0 && st.top()<v[i])
        {
            ans.push_back(st.top());
        }else if (st.size()>0 && st.top()>=v[i])
        {
            while (!st.empty() && st.top()>=v[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(-1);
            }else
            {
                ans.push_back(st.top());
            }
        }
        st.push(v[i]);
    }
    return ans;
}

vector<int> NextSmallerToRight(vector<int> v){
    vector<int> ans;
    stack<int> st;
    for (int i = v.size()-1; i >=0 ; i--)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }else if(st.size()>0 && st.top()<v[i]){
            ans.push_back(st.top());
        }else if (st.size()>0 && st.top()>=v[i])
        {
            while(!st.empty() && st.top()>=v[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(st.top());
            }
        }
        st.push(v[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &it: v) cin>>it;
    // vector<int>ans=NextGreaterToRight(v);
    // vector<int>ans=NextGreaterToLeft(v);
    // vector<int>ans=NextSmallerToLeft(v);
    vector<int>ans=NextSmallerToRight(v);
    for(auto it: ans)cout<<it<<" ";
    return 0;
}