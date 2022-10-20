//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
using namespace std;

void swap(int arr[],int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//* Time Complexity is O(n/2) or we can write it as O(n)

void waveSort(int arr[], int n){
    for (int i = 1; i < n; i+=2)
    {
        if (arr[i]>arr[i-1])
        {
            swap(arr,i,i-1);
        }
        if (arr[i]>arr[i+1] && i<=n-2)
        {
            swap(arr,i+1,i);
        }       
    }
    
}
int main(){
    int arr[]={1,3,4,7,5,6,2};
    waveSort(arr,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}