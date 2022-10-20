//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//*Q1.Number of times a sorted array is rotated**************************
// int main(){
//     int arr[] = {11,12,15,18,2,5,7,8};
//     int low=0,high=7;
//     while (low<=high)
//     {
//         int mid = (low+high)/2;
//         int next = (mid + 1)%8;
//         int previous = (mid + 7)%8;

//         if (arr[mid]<=arr[next] && arr[mid]<=arr[previous])
//         {
//             cout<<mid;
//             return 0;
//         }else{
//             if(arr[mid]>=arr[low] && arr[mid]<=arr[high])
//             { 
//                 cout<<low;
//                 return 0;
//             }    
//             else if (arr[low]<=arr[mid])
//             {
//                 low = mid+1;
//             }
//             else if (arr[mid]<= arr[high])
//             {
//                 high = mid-1;
//             }
//         }

//     }
      
//     return 0;
// }
//*Q2.Find an element in a rotated sorted array
//*Unofficial Method
// int main(){
//     int arr[] = {11,12,15,18,2,5,7,8};
//     int low=0,high=7,k;
//     cin>>k;
//     while (low<=high)
//     {
//         int mid = (low+high)/2;
//         if (arr[mid]==k)
//         {
//             cout<<mid;
//             return 0;
//         }else{
//             if (arr[mid]>=k && arr[low]<=k)
//             {
//                 high = mid-1;
//             }else if (arr[mid]<=k && arr[low]<=k)
//             {
//                 low = mid+1;
//             }else if (arr[mid]>=k && arr[low]>=k)
//             {
//                 low = mid+1;
//             }
            
//         }
        
//     }
    
//     return 0;
// }
//*Official Method
// int binarySearch(int arr[], int low, int high, int key){
//     while (low<=high)
//     {
//         int mid = (low+high)/2;
//         if (arr[mid]>key)
//         {
//             high = mid-1;
//         }
//         else if (arr[mid]<key)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             return mid;
//         }
//     }
    
//     return -1;
// }
// int minindex(int arr[],int n){
//     int low=0,high=n-1;
//     while (low<=high)
//     {
//         int mid = (low+high)/2;
//         int next = (mid + 1)%n;
//         int previous = (mid + n-1)%n;

//         if (arr[mid]<=arr[next] && arr[mid]<=arr[previous])
//         {
//             return mid;
//         }else{
//             if(arr[mid]>=arr[low] && arr[mid]<=arr[high])
//             { 
//                 return low;
//             }    
//             else if (arr[low]<=arr[mid])
//             {
//                 low = mid+1;
//             }
//             else if (arr[mid]<= arr[high])
//             {
//                 high = mid-1;
//             }
//         }
//     }
//     return -1;
// }
//     int main(){
//     int arr[] = {11,12,15,18,2,5,7,8};
//     int indexMinElement = minindex(arr,8);
    
//     int a=binarySearch(arr,0,indexMinElement-1,15);    
//     int b=binarySearch(arr,indexMinElement,7,15);
//     cout<<max(a,b);    
//     return 0;
// }    
//*Q3.Searching in a nearly sorted array

// int main(){
//     int arr[] = {10,20,40,30,50};
//     int key;
//     cin>>key;
//     int low=0,high=4;
//     while (low<=high)
//     {
//         int mid = (low+high)/2;
//         if (arr[mid]==key)
//         {
//             cout<<mid;
//             return 0;
//         }
//         if (mid-1>=low && arr[mid-1]==key)
//         {
//             cout<<mid-1;
//             return 0;
//         }
//         if (mid+1<=high && arr[mid+1]==key)
//         {
//             cout<<mid+1;
//             return 0;
//         }
//         if (arr[mid]<key)
//         {
//             low = mid+2;
//         }
//         if (arr[mid]>key)
//         {
//             high = mid-2;
//         }
//     }
//     return 0;
// }

//*Q4.Minimum difference element in a sorted array
//*Unofficial Method
// int main(){
//     int arr[]={1,3,8,10,12,15};
//     int low=0,high=5,k=12,mindiff=INT_MAX,currdiff=INT_MAX,ans;
//     while (low<=high)
//     {
//         int mid=(low+high)/2;
//         if (arr[mid]==k)
//         {
//             mindiff=0;
//             cout<<k;
//             return 0;
//         }
//         else if (arr[mid]>k)
//         {
//             currdiff=abs(arr[mid]-k);
//             mindiff = min(mindiff,currdiff);
//             if (mindiff==currdiff)
//             {
//                 ans=arr[mid];
//             }
//             high=mid-1;
//         }else if (arr[mid]<k)
//         {
//             currdiff=abs(arr[mid]-k);
//             mindiff = min(mindiff,currdiff);
//             if (mindiff==currdiff)
//             {
//                 ans=arr[mid];
//             }
//             low = mid+1;
//         }
//     }
//     cout<<ans;
//     return 0;
// }
//*Official Method

// int main(){
//     int arr[]={1,3,8,10,15};
//     int low=0,high=4,k=12,ans;
//     while (low<=high)
//     {
//         int mid=(low+high)/2;
//         if (arr[mid]==k)
//         {
//             cout<<k;
//             return 0;
//         }
//         else if (arr[mid]>k)
//         {
//             high=mid-1;
//         }else if (arr[mid]<k)
//         {
//             low = mid+1;
//         }
//     }
//     int a=abs(arr[low]-k);
//     int b=abs(arr[high]-k);
//     ans = min(a,b);
//     if (ans==a)
//     {
//         cout<<arr[low];
//     }else{
//         cout<<arr[high];
//     }
//     return 0;
// }

//*Q5.Peak Element

// int main(){
//     int arr[] = {5,10,20,15};
//     int low=0,high=3;
//     while (low<=high)
//     {
//         int mid = (low+high)/2;
//         if (mid>0 && mid<3)
//         {
//             if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
//             {
//                 cout<<mid<<" ";
//                 return 0;
//             }else if (arr[mid+1]>arr[mid])
//             {
//                 low = mid+1;
//             }else if (arr[mid-1]>arr[mid])
//             {
//                 high = mid-1;
//             }
//         }else if (mid==0)
//         {
//             if (arr[mid]>arr[mid+1])
//             {
//                 cout<<mid<<" ";
//                 return 0;
//             }
//         }else{
//             if (arr[mid]>arr[mid-1])
//             {
//                 cout<<mid<<" ";
//                 return 0;
//             }
//         }
//     }
    
//     return 0;
// }

//*Q6.Search Maximum element in Bitonic Array

// int main(){
//     int arr[]={1,3,8,12,4,2};
//     int low=0,high=5;
//     while (low<=high)
//     {
//         int mid = (low+high)/2;
//         if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
//         {
//             cout<<arr[mid];
//             return 0;
//         }
//         else if (arr[mid]<arr[mid+1])
//         {
//             low = mid+1;
//         }else if (arr[mid]<arr[mid-1])
//         {
//             high = mid-1;
//         }       
//     }
    
//     return 0;
// }

//*Q7.Search an element in a Bitonic Array

// int binarySearchAsc(int arr[], int low,int high, int key){
//     while (low<=high)
//     {
//         int mid = (low+high)/2;
//         if (arr[mid]>key)
//         {
//             high = mid-1;
//         }
//         else if (arr[mid]<key)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             return mid;
//         }
//     }
//     return -1;
// }
// int binarySearchDesc(int arr[], int low,int high, int key){
//     while (low<=high)
//     {
//         int mid = (low+high)/2;
//         if (arr[mid]>key)
//         {
//             low = mid + 1;
//         }
//         else if (arr[mid]<key)
//         {
//             high = mid-1;
//         }
//         else
//         {
//             return mid;
//         }
//     }
//     return -1;
// }
// int main(){
//     int arr[]={1,3,8,12,4,2};
//     int low=0,high=5,ans;
//     while (low<=high)
//     {
//         int mid = (low+high)/2;
//         if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
//         {
//             ans = mid;
//             cout<<ans<<endl;
//             break;
//         }
//         else if (arr[mid]<arr[mid+1])
//         {
//             low = mid+1;
//         }else if (arr[mid]<arr[mid-1])
//         {
//             high = mid-1;
//         }       
//     }
//     int a=binarySearchAsc(arr,0,ans-1,4);
//     int b=binarySearchDesc(arr,ans,5,4);
//     cout<<max(a,b);
//     return 0;
// }

//* Q8.Allocate Minimum no. of Pages of Book***********************

bool isvalid(int arr[],int n, int k, int mid){
    int sum=0;
    int students=1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum>mid)
        {
            students++;
            sum = arr[i];
        }
        if (students>k)
        {
            return false;
        }
    }
    return true;
}
int main(){
    int arr[] = {10,20,30,40};
    int k=2;
    int high=0,low=INT_MIN;
    for (int i = 0; i < 4; i++)
    {
        high += arr[i];
        low = max(low,arr[i]);
    }
    int res=-1;
    while (low<=high)
    {
        int mid = (low+high)/2;
        if (isvalid(arr,4,k,mid))
        {
            res=mid;
            high = mid-1;
        }else
        {
            low = mid+1;
        }        
    }
    cout<<res;
    return 0;
}