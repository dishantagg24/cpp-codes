#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

//* Not Official Method
//* Maximum Sum of Subarray***********************************************
//* Time Complexity O(n^2)    
    int psum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        psum = 0;
        for (int j = i; j < n; j++)
        {
            psum += arr[j];
            sum = max(sum,psum);
        }
        
    }
    cout<<sum<<endl;

//* Brute Force Approach*************************************************
//* Time Complexity O(n^3)    
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum+=arr[k];
            }
            maxsum = max(maxsum,sum);
        }
    }
    cout<<maxsum<<endl;
 
//* Cumulative sum approach********************************************
//* Time Complexity O(n^2)    
int currarr[n+1];
    currarr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        currarr[i] = currarr[i-1] + arr[i-1];
    }
    int maxsum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum = currarr[i]-currarr[j];
            maxsum = max(maxsum,sum); 
        }        
    }
    cout<<maxsum;    

//*Kandane's Algorithm*************************************************
//* Time Complexity O(n)    
int sum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        maxsum = max(maxsum,sum);
        if (sum<0)
        {
            sum = 0;
        }
        
    }
    cout<<maxsum;


//*Not Official Method
//* Printing subarray whose sum is maximum*********************************
    int st = 0;
    int en = 0;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            s = 0;
            for (int k = i; k <= j; k++)
            {
                s+=arr[k];
                if (s==sum)
                {
                    for (int p = i; p <= j; p++)
                    {
                        cout<<arr[p]<<" ";
                    }   
                }   
            }   
        }        
    } 
    return 0;
}

//* Maximum Circular Subarray Sum*************************************************

int kadane(int arr[],int n){
    int sum = 0;
    int maxsum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        sum+=arr[i];
        maxsum = max(maxsum,sum);
        if (sum<0)
        {
            sum = 0;
        }
    }
    return maxsum;
}

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for (int i = 0; i < n; i++)             //For Input elements in array
    {
        cin>>arr[i];
    }
    int tsum = 0;
    for (int i = 0; i < n; i++)             //For sum of all elements of array
    {
        tsum+=arr[i];
    }
    for (int i = 0; i < n; i++)             //For reversing the sign of all elements of array
    {
        arr[i] = -arr[i];
    }

    int nonwrapsum;
    nonwrapsum = kadane(arr,n);             //For finding the largest element in reversed sign array

    int wrapsum;
    wrapsum = tsum + kadane(arr,n);         //total sum - negative of sum of non contributing elements

    cout<<max(wrapsum,nonwrapsum);          //compare wrapsum and nonwrapsum

//* Pair Sum Problem (For Sorted Array)*******************************************
//* Brute Force Approach Time complexity O(n^2)
int key;
    cin>>key;
    
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i]+arr[j] == key)
            {
                cout<<i<<" "<<j;
                return 0;
            }
            
        }
        
    }
        cout<<"no two elements exist whose sum can be equal to key"<<endl;

//* Optimised Approach Time complexity O(n)
    int key;
    cin>>key;
    bool flag = false; 
    int i=0, j=n-1;
    while (i < j)
    {
        if (arr[i] + arr[j] == key)
        {
            cout<<i<<" "<<j;
            flag = true;
            break;
        }
        else if (arr[i] + arr[j] < key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
     if (flag == false)
     {
        cout<<"no two elements exist whose sum can be equal to key"<<endl;
     } 

//*Maximum Product Subarray***********************************************
//Test Cases
//{-5,-3,-4}
//{-1,-3,-4}
//{-3,4,5}

int arr[] = {-1,-4,-3};
    
    int max_ending_here=1;
    int min_ending_here=1;
    int max_so_far=0;
    for (int i = 0; i < 3; i++)
    {
        if (arr[i]>0)
        {
            max_ending_here *= arr[i];
            min_ending_here = min(1,min_ending_here*arr[i]);  
        }else if (arr[i]==0)
        {
            max_ending_here=1;
            min_ending_here=1;
        }else{
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here*arr[i],1);
            min_ending_here = temp * arr[i];
        }
        max_so_far = max(max_so_far,max_ending_here);
    }
    cout<<max_so_far;

//*Mindbending Product**************************************************
//Conditions:
//1.U can not use divide(/) operator
//2.U can not make two arrays or cannot take extra space
int arr[]={10,3,5,6,2};
    int arr1[5] = {0};
    int left_product=1;
    arr1[0]=1;
    for (int i = 1; i < 5; i++)
    {
        left_product *= arr[i-1];
        arr1[i] = left_product;
    }
    int right_product=1;
    for (int i = 3; i >=0 ; i--)
    {
        right_product *= arr[i+1];
        arr1[i] *= right_product;
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<arr1[i]<<" ";
    }
    return 0;
} 