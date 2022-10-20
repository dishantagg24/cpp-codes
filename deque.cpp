//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//*Sliding Window (print maximum element in subarray of k integers)

//First Method (using multiset)
vector<int> slidingWindow(vector<int>v, int k){
    multiset<int,greater<int>>s;
    vector<int>ans;
    for (int i = 0; i < k; i++)
    {
        s.insert(v[i]);
    }
    ans.push_back(*s.begin());
    for (int i = k; i < v.size(); i++)
    {
        s.erase(s.lower_bound(v[i-k]));
        s.insert(v[i]);
        ans.push_back(*s.begin());
    }
    return ans;
}

//Second Method (using deque)
vector<int> slidingWindow1(vector<int>v, int k){
    deque<int>dq;
    vector<int>ans1;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && v[dq.back()] < v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans1.push_back(v[dq.front()]);
    for (int i = k; i < v.size(); i++)
    {
        if (dq.front()==i-k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && v[dq.back()] < v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans1.push_back(v[dq.front()]);
    }
    return ans1;
};

int main(){
//*Deque basic    
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    for(auto i:dq)cout<<i<<" ";
    cout<<endl;
    dq.pop_back();
    dq.pop_front();
    for(auto i:dq)cout<<i<<" ";
    cout<<"\n"<<dq.size()<<endl;

//*Sliding Window (print maximum element in subarray of k integers)
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto &it: v)cin>>it;
    vector<int>ans = slidingWindow(v,k);
    for(auto it: ans)cout<<it<<" ";
    cout<<endl;
    vector<int>ans1 = slidingWindow1(v,k);
    for(auto it: ans1)cout<<it<<" ";
    return 0;
}