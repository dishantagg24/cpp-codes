//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//*Q1.StockSpan Problem solved using NearestGreaterLeftIndex(NGLI)
vector<int> stockSpan(vector<int>v){
    stack<pair<int,int>> st;
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }else if (st.size()>0 && st.top().first>v[i])
        {
            ans.push_back(st.top().second);
        }else if (st.size()>0 && st.top().first<=v[i])
        {
            while (!st.empty() && st.top().first<=v[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(-1);
            }else{
                ans.push_back(st.top().second);
            }
        }
        st.push({v[i],i});
    }
    return ans;
}

//*Q2.Maximum Area Histogram (MAH) Problem solved using NearestSmallerLeftIndex(NSLI) & NearestSmallerRightIndex(NSRI)
vector<int>NearestSmallerLeftIndex(vector<int> v){
    vector<int>ans;
    stack<pair<int,int>> st;
    for (int i = 0; i < v.size(); i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }else if (st.size()>0 && st.top().first<v[i])
        {
            ans.push_back(st.top().second);
        }else if (st.size()>0 && st.top().first>=v[i])
        {
            while (!st.empty() && st.top().first>=v[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(-1);
            }else{
                ans.push_back(st.top().second);
            }            
        }
        st.push({v[i],i});
    }
    return ans;
}
vector<int>NearestSmallerRightIndex(vector<int> v){
    vector<int>ans;
    stack<pair<int,int>> st;
    for (int i = v.size()-1; i >= 0; i--)
    {
        if (st.empty())
        {
            ans.push_back(v.size());
        }else if (st.size()>0 && st.top().first<v[i])
        {
            ans.push_back(st.top().second);
        }else if (st.size()>0 && st.top().first>=v[i])
        {
            while (!st.empty() && st.top().first>=v[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(v.size());
            }else{
                ans.push_back(st.top().second);
            }            
        }
        st.push({v[i],i});
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int MAH(vector<int> v){
    vector<int> NSLI = NearestSmallerLeftIndex(v);
    vector<int> NSRI = NearestSmallerRightIndex(v);
    vector<pair<int,int>> result;
    int maxElement=INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        result.push_back({NSLI[i],NSRI[i]});
        maxElement=max(maxElement,(result[i].second-result[i].first-1)*v[i]);
    }
    return maxElement;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &it: v) cin>>it;
    vector<int>ans=stockSpan(v);
    vector<int>result;
    for (int i = 0; i < v.size(); i++)
    {
        result.push_back(i-ans[i]);
    }
    for(auto it: result) cout<<it<<" ";

//*Q3.Maximum Area of Rectange in Binary Matrix solved using MAH question
    int r,c;
    cin>>r>>c;
    vector<int> v;
    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>arr[i][j];
        }
    }
    
    int maxAns = INT_MIN;
        for (int j = 0; j < c; j++)
        {
            v.push_back(arr[0][j]);
        }
        maxAns = max(maxAns,MAH(v));   
    int k=0;
    for (int i = 1; i < r; i++)
    {
        k=0;
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j]==1)
            {
                v[k] += arr[i][j];
            }else
            {
                v[k] = 0;
            }
            k++;
        }
        maxAns = max(maxAns,MAH(v));   
    }
    cout<<maxAns<<endl;

    return 0;
}