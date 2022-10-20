//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//*Reverse a string using stack
void reverseString(string s){
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string word="";
        while (s[i]!=' ' && i<s.length())
        {
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

//*Reverse stack using resursion
void insertAtBottom(stack<int>&st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele=st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);
}
void reverse(stack<int> &st){
    if (st.empty())
    {
        return;
    }
    int ele=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);
}

//*Check given string is balanced parenthesis or not
bool checkBalancedParenthesis(string s){
    stack<char>st;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            st.push(s[i]);
        }else{
            if (st.empty())
            {
                return false;
            }
            if (st.top()=='(' && s[i]==')')
            {
                st.pop();
            }
            else if (st.top()=='[' && s[i]==']')
            {
                st.pop();
            }
            else if (st.top()=='{' && s[i]=='}')
            {
                st.pop();
            }else{
                return false;
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }   
    return true;
}
int main(){
    string s="Hey, how are you doing?";
    // reverseString(s);
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse(st);
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    string s="{([])}(";
    cout<<checkBalancedParenthesis(s);
    return 0;
}