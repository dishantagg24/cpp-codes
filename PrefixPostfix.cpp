//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//*Prefix Evalution
int prefixEvaluation(string s){

    stack<int>st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }else{
            int operand1=st.top();
            st.pop();
            int operand2=st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(operand1+operand2);
                break;
            case '-':
                st.push(operand1-operand2);
                break;
            case '/':
                st.push(operand1/operand2);
                break;
            case '*':
                st.push(operand1*operand2);
                break;
            case '^':
                st.push(pow(operand1,operand2));
                break;
            }
        }
    }
    return st.top();
}

//*Postfix Evaluation
int postfixEvaluation(string s){

    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }else{
            int operand2=st.top();
            st.pop();
            int operand1=st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(operand1+operand2);
                break;
            case '-':
                st.push(operand1-operand2);
                break;
            case '/':
                st.push(operand1/operand2);
                break;
            case '*':
                st.push(operand1*operand2);
                break;
            case '^':
                st.push(pow(operand1,operand2));
                break;
            }
        }
        
    }
    return st.top();
}

//*For checking operator precedence
int prec(char ch){
    if(ch=='^'){
        return 3;
    }else if (ch=='*' || ch=='/')
    {
        return 2;
    }else if (ch=='+' || ch=='-')
    {
        return 1;
    }
    return -1;
}

//*Infix to Postfix
string InfixToPostfix(string s){
    string res;
    stack <char>st;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i]>='a'&& s[i]<='z') || (s[i]>='A'&& s[i]<='Z'))
        {
            res+=s[i];
        }else if(s[i]=='('){
            st.push(s[i]);
        }else if (s[i]==')')
        {
            while (!st.empty() && st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }else{
            while (!st.empty() && prec(s[i])<prec(st.top()))
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
        while (!st.empty())
        {
            res+=st.top();
            st.pop();
        }
    return res;
}

//*Infix To Prefix
string InfixToPrefix(string s){
    reverse(s.begin(),s.end());
    string res;
    stack <char>st;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i]>='a'&& s[i]<='z') || (s[i]>='A'&& s[i]<='Z'))
        {
            res+=s[i];
        }else if(s[i]==')'){
            st.push(s[i]);
        }else if (s[i]=='(')
        {
            while (!st.empty() && st.top()!=')')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }else{
            while (!st.empty() && prec(s[i])<prec(st.top()))
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
        while (!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
    return res;
}

int main(){
    string s="-+7*45+20";
    cout<<prefixEvaluation(s)<<endl;
    string s1="46+2/5*7+";
    cout<<postfixEvaluation(s1)<<endl;

    cout<<InfixToPostfix("(a-b/c)*(a/k-l)")<<endl;
    cout<<InfixToPrefix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}