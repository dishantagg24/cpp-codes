//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//*Check if array is sorted or not  
bool check(int arr[],int n){

    if (n==1)
    {
        return true;
    }

    bool RestArray=check(arr+1, n-1);

    return (arr[0]<arr[1] && RestArray);
}

//*Print index of first occurence of a repeated element in an array
int firstocc(int arr[],int n,int i,int key){

    if (i == n)
    {
        return -1;
    }
    
    if (arr[i] == key)
    {
        return i;
    }
    return firstocc(arr, n, i+1, key);
}

//*Print index of last occurence of a repeated element in an array
int lastocc(int arr[],int n,int i,int key){

    if (i == n)
    {
        return -1;
    }
    
    int restArray=lastocc(arr, n, i+1, key);

    if (restArray != -1)
    {
        return restArray;
    }
    
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}

//*Check Palindrome with recursion
void checkPalindrome(string s,int flag){
    if (s.length()==1)
    {
        if (flag==1)
        {
            cout<<"Palindrome";
        }else{
            cout<<"Not Palindrome";
        }
        return;
    }
    string ros = s.substr(1,s.length()-2);
    if (s[0]==s[s.length()-1])
    {
        flag=1;
    }else{
        flag=0;
    }
    checkPalindrome(ros,flag);
    return;
}

//*BinarySearch using recursion
void Binary(int arr[], int n,int low, int high, int k){
    if (low>high)
    {
        cout<<"Element doesn't exist";
        return;
    }
    int mid = (low + high)/2;
    if (arr[mid]>k)
    {
        Binary(arr,n,low,mid-1,k);
    }else if (arr[mid]<k)
    {
        Binary(arr,n,mid+1,high,k);
    }else{
        cout<<"Element exist";
        return;
    }
    return;
}

//*First Capital Letter in a string

void firstLetter(string s){
    if (s.length()==0)
    {
        return;
    }
    string ros = s.substr(1);
    if (s[0]>='A' && s[0]<='Z')
    {
        cout<<s[0];
        return;
    }
    firstLetter(ros);
    return;
}

//*Copy string to another
void stringCopy(string s,string s1){
    if (s.length()==0)
    {
        cout<<s1;
        return;
    }
    string ros = s.substr(1);
    s1.append(s,0,1);
    stringCopy(ros,s1);
    return;
}

//*HailSequence using recursion
void HailSequence(int n,int length){
    if (length==0)
    {
        return;
    }else if (n%2==0)
    {
        cout<<n<<" ";
        HailSequence(n/2,length-1);
    }else{
        cout<<n<<" ";
        HailSequence((3*n)+1,length-1);
    }
    return;
}

//*Sort an array using recursion
void sort1(int arr[],int n,int i){
    if (n==1)
    {
        return;
    }
    if (arr[i]>arr[i+1])
    {
        swap(arr[i],arr[i+1]);
    }
    if (i==n-1)
    {
        sort1(arr,n-1,0);
    }else{
        sort1(arr,n,i+1);
    }
    return;
}


int main(){
    int arr[]={4,2,1,2,5,2,7};
    cout<<check(arr,7);
    cout<<firstocc(arr,7,0,2)<<endl;
    cout<<lastocc(arr,7,0,2)<<endl;
    checkPalindrome("dishant",0);
    int arr[] = {15,25,35};
    Binary(arr,3,0,2,40);
    firstLetter("dIsHaNt");
    stringCopy("dIsHaNt","");
    HailSequence(13,10);
    int arr[] = {2,3,1,10,7,5};
    sort1(arr,6,0);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}