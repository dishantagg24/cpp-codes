#include<iostream>
#include<climits>           //for using int_max and int_min
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    } 
    int maxno = INT_MIN;
    int minno = INT_MAX;

    for (int i = 0; i < n; i++)
    {
       /*  if (array[i]>maxno)
        {
            maxno = array[i];
        } */
        maxno = max(maxno,array[i]);    //short form of above comment lines
        /* if (array[i]<minno)
        {
            minno = array[i];
        } */
        minno = min(minno,array[i]);    //short form of above comment lines
    }
      cout<<maxno<<" "<<minno;

//*SUM of an array(H.W.)******************************
    /*  for (int i = 0; i < n; i++)
    {
        array[i+1] = array[i+1] + array[i];
    }
    cout<<array[n-1];  */
        

//*print kid with the greatest no. of candles (H.W.2)******
    /* cout << "Enter the no. of kids "<<endl;
    int n;
    cin >> n;
    int maxno = INT_MIN;
    int minno = INT_MAX;

    int array[n];
    cout<<"Enter no. of candles each student have "<<endl;

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i]>maxno)
        {
            maxno = array[i];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if (maxno == array[i])
        {
            cout<<"the kid "<<i+1<<" has highest no. of candles i.e. "<<maxno<<endl;
        }
        
    } */   
    return 0;
}