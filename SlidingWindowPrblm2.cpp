//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//*Q1. Size of Largest subarray of sum k
int MaxSubarray(vector<int> v, int k)
{
    int i = 0, j = 0, sum = 0, ans = 0, res = 0;
    while (j < v.size())
    {
        sum += v[j];
        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            ans = j - i + 1;
            res = max(ans, res);
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum -= v[i];
                i++;
            }
            j++;
        }
    }
    return res;
}

//*Q. Minimum size of subarray whose sum of elements is greater than x
int MinSizeSubarr(int arr[], int n, int x)
{
    int sum = 0, minLength = n + 1, st = 0, en = 0;
    while (en < n)
    {
        while (sum <= x && en < n)
        {
            sum += arr[en];
            en++;
        }
        while (sum > x && st < n)
        {
            minLength = min(minLength, en - st);
            sum -= arr[st];
            st++;
        }
    }
    return minLength;
}

// For Negative nos.
//*Q2.Longest Substring with K unique characters
int MaxSubstring(string s, int k)
{
    int i = 0, j = 0, ans = 0;
    map<int, int> mp;
    while (j < s.length())
    {
        mp[s[j]]++;
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}

//*Q3.Longest Substring Without Repeating Characters
int MaxSubstring2(string s)
{
    int i = 0, j = 0, ans = 0;
    map<int, int> mp;
    while (j < s.length())
    {
        mp[s[j]]++;
        if (mp.size() == j - i + 1)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (mp.size() < j - i + 1)
        {
            while (mp.size() < j - i + 1)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}
//*Minimum Window Substring
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    string t;
    cin>>t;
    map<char,int> m;
    for(auto i: t)
    {
        m[i]++;
    }
    int i=0,j=0,count=m.size(),ans=INT_MAX;
    while(j<str.size())
    {
        if(m.find(str[j])!=m.end())
        {
            m[str[j]]--;
            if(m[str[j]]==0)
                count--;
        }
        if(count>0)
        {
            j++;
        }
        else if(count==0)
        {
            while(count==0 && i<=j)
            {
                ans=min(ans,j-i+1);
                if(m.find(str[i])!=m.end())
                {
                    m[str[i]]++;
                    if(m[str[i]]==1)
                        count++;
                }
                i++;
                if(i==str.size())
                break;
            }
            j++;
        }
    }
    cout<<ans<<endl;
}	*/

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = MaxSubarray(v, k);
    cout << ans << endl;
    string s;
    cin >> s;
    int ans1 = MaxSubstring(s, k);
    cout << ans1 << endl;
    int ans3 = MaxSubstring2(s);
    cout << ans3 << endl;
    return 0;
}