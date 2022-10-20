//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//*Q1. Three Sum problem
vector<int>threeSum(vector<int>v,int target){
    vector<int>ans;
    sort(v.begin(),v.end());
    int temp=target;
    for (int i = 0; i < v.size(); i++)
    {
        temp=target;
        temp = temp - v[i];
        int st=i+1,en=v.size()-1-i;
        while (st<en && (v[st] + v[en]) != temp)
        {
            if (v[st]+v[en]<temp)
            {
                st++;
            }else{
                en--;
            }
        }
        if ((v[st] + v[en]) == temp)
        {
        ans.push_back(v[i]);
        ans.push_back(v[st]);
        ans.push_back(v[en]);
        return ans;
        }
    }
    ans.push_back(-1);
    return ans;
}

//*Q2. Max Consecutive Ones 
int maxConsecutiveOnes(vector<int>v,int k){
    int zero_count=0,i=0, ans=0;
    for (int j = 0; j < v.size(); j++)
    {
        if (v[j]==0)
        {
            zero_count++;
        }
        while (zero_count>k)
        {
            if (v[i]==0)
            {
                zero_count--;
            }
            i++;
        }
        ans = max(ans,j-i+1);
    }
    return ans;
}

//*Q3. Longest substring without repeating characters
int LongestSubstring(string s){
    vector<int>dict(256,-1);
    int maxLen = 0, start = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (dict[s[i]]>start)
        {
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int>v(n);
    for(auto &it : v)cin>>it;
    vector<int> ans = threeSum(v,target);
    for(auto it : ans)cout<<it<<" ";

    string s="bhavyakapooramandishanttushar";
    cout<<LongestSubstring(s)<<endl;

    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto &it : v)cin>>it;
    cout<<maxConsecutiveOnes(v,k)<<endl;
    return 0;
}