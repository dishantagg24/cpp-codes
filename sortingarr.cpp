#include<iostream>
using namespace std;

//* Array can be sort (arranging elements in ascending or descending order) by 3 methods :-
//* 1. Selecton sort
//* 2. Bubble sort
//* 3. Insertion sort 

void selectionsort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[i])
            {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;    
            }    
        }        
    }    
}

void bubblesort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
            
        }
        
    }
    
}

void insertionsort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

void inputarray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }   
}

void printarray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    
    inputarray(arr,n);
    selectionsort(arr,n);
//    bubblesort(arr,n);
//    insertionsort(arr,n);
    printarray(arr,n);

    return 0;
}