//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//*no.of sliding window of length k in array of size n
// n - k + 1

//*Q1. Maximum sum subarray of size k
int maxSum(vector<int> v, int k)
{
    int ans = INT_MIN;
    int i = 0, j = 0;
    int sum = 0;
    while (j < v.size())
    {
        sum += v[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans = max(ans, sum);
            sum -= v[i];
            i++;
            j++;
        }
    }
    return ans;
}

//*Q2. Minimum sum subarray of size k
int minSum(vector<int> v, int k)
{
    int ans = INT_MAX;
    int i = 0, j = 0;
    int sum = 0;
    while (j < v.size())
    {
        sum += v[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans = min(ans, sum);
            sum -= v[i];
            i++;
            j++;
        }
    }
    return ans;
}

//*Q3. First Negative Number in subarray of size of k
// Unofficial Method (without using deque)
vector<int> firstNegativeNo(vector<int> v, int k)
{
    int j = 0, i = 0, s = 0;
    vector<int> ans;
    vector<int> ans2;
    while (j < v.size())
    {
        if (v[j] < 0)
        {
            ans.push_back(v[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (s >= ans.size())
            {
                ans2.push_back(0);
            }
            else
            {
                ans2.push_back(ans[s]);
            }
            if (v[i] < 0)
            {
                s++;
            }
            i++;
            j++;
        }
    }
    return ans2;
}
// Official Method (using deque)
vector<int> firstNegativeNo1(vector<int> v, int k)
{
    int j = 0, i = 0;
    deque<int> dq;
    vector<int> ans2;
    while (j < v.size())
    {
        if (v[j] < 0)
        {
            dq.push_back(v[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (dq.empty())
            {
                ans2.push_back(0);
            }
            else
            {
                ans2.push_back(dq.front());
                if (v[i] == dq.front())
                {
                    dq.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    return ans2;
}

//*Q4.Count Occurences Of Anagrams
// Unofficial Method
int anagramOccurences(string s1, string s2)
{
    int k = s2.length();
    int i = 0, j = 0;
    int count = 0;
    sort(s2.begin(), s2.end());
    string ans = "";
    while (j < s1.length())
    {
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans = s1.substr(i, k);
            sort(ans.begin(), ans.end());
            if (s2.compare(ans) == 0)
            {
                count++;
            }
            j++;
            i++;
        }
    }
    return count;
}
// Official Method
int anagramOccurences1(string s1, string s2)
{
    int k = s2.length();
    map<char, int> mp;
    for (int i = 0; i < k; i++)
    {
        mp[s2[i]]++;
    }
    int count = mp.size();
    int i = 0, j = 0, ans = 0;
    while (j < s1.length())
    {
        auto it = mp.find(s1[j]);
        if (it != mp.end())
        {
            mp[s1[j]]--;
            if (mp[s1[j]] == 0)
                count--;
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (count == 0)
            {
                ans++;
            }
            auto it = mp.find(s1[i]);
            if (it != mp.end())
            {
                mp[s1[i]]++;
                if (mp[s1[i]] == 1)
                    count++;
            }
            j++;
            i++;
        }
    }
    return ans;
}

//*Q5.Maximum of all subarrays of size k
// Using Multiset
vector<int> MaxElement(vector<int> v, int k)
{
    vector<int> ans;
    multiset<int, greater<int>> st;
    for (int i = 0; i < k; i++)
    {
        st.insert(v[i]);
    }
    ans.push_back(*st.begin());
    for (int i = k; i < v.size(); i++)
    {
        st.erase(st.lower_bound(v[i - k]));
        st.insert(v[i]);
        ans.push_back(*st.begin());
    }
    return ans;
}

// Using deque
vector<int> MaxElement(vector<int> v, int k)
{
    vector<int> ans;
    deque<int> dq;
    int i = 0, j = 0;
    int maxElement = INT_MIN;
    while (j < v.size())
    {
        while (dq.size() > 0 && dq.back() < v[j])
        {
            dq.pop_back();
        }
        dq.push_back(v[j]);
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans.push_back(dq.front());
            if (dq.front() == v[i])
            {
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = maxSum(v, k);
    cout << ans << endl;
    int ans1 = minSum(v, k);
    cout << ans1 << endl;
    vector<int> res = firstNegativeNo(v, k);
    for (auto it : res)
        cout << it << " ";
    string s1 = "aabaabaa";
    string s2 = "aaba";
    cout << anagramOccurences(s1, s2) << endl;
    return 0;
}