//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//*Q1.Sort Integers by The Number of 1 Bits*****************************
int countSetBits(int n){
        int count=0;
        while(n!=0){
            if(n&1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
    bool myCompare(pair<int,int>p1,pair<int,int>p2){
        if(p1.second==p2.second){
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    }
int main(){
    int n;
        cin>>n;
        
        int arr1[n];
        vector<int>arr;
        for (int i = 0; i < n; i++)
        {
            cin>>arr1[i];
            arr.push_back(arr1[i]);
        }
        
        vector<pair <int,int>> p;
        for(int i=0;i<arr.size();i++){
            p.push_back(make_pair(arr[i],countSetBits(arr[i])));
        }
        sort(p.begin(),p.end(),myCompare);
                
        for(int i=0;i<p.size();i++){
            cout<<p[i].first<<" ";
        }

//*Q2.You are given an array A consisting of N integers and an integer X. Your goal is to have as many equal integers as possible in the array. To achieve this goal, you can do the following operation: Choose an index i (1≤i≤N) and set Ai=Ai⊕X, where ⊕ denotes the bitwise xor operation.Find the maximum number of equal integers you can have in the final array and the minimum number of operations to obtain these many equal integer
//*TestCase: 
//8 6
//4 4 2 2 1 1 7 5        

int n,x;
    cin>>n>>x;
    map<int,int> m;
    int max_freq=0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        m[num]++;
        max_freq=max(max_freq,m[num]);
    }
    int ops=0;
    for(auto [key,val]:m){
        int count=val;
        if (x!=0)
        {
            count+=m[key^x];
        }
        int reqOperations=m[key^x];
        if (count>max_freq)
        {
            max_freq=count;
            ops=reqOperations;
        }
    }
    cout<<max_freq<<" "<<ops<<endl;
    return 0;
}