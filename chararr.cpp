#include <iostream>
using namespace std;

int main()
{
//* Printing each character of character array***************************
    /* char arr[6] = "apple";          // arr[n+1]---> if a string contains n variable & +1 is for null character
    int i = 0;
    while (arr[i] != '\0')             //  \0 ---> Null character
    {
        cout<<arr[i]<<endl;
        i++;
    } */

//* For input and Output of character array********************************

    int n;
    cin>>n;
    char arr[n+1];

    cin>>arr;

    cout<<arr<<endl;
    cout<<arr[2];                       // for printing ith character of char array

//* check a word is palindrome or not****************************************************
 /* int n;
    cin>>n;

    char arr[n+1];
    cin>>arr;

    bool flag = true; */
//* Not official method********************************    
   /*  int i = 0;
    int j = n-1;
    while (i<n && j>=0)
    {
            if (i!=j && arr[i] != arr[j])
            {
                flag = false;
                break;
            }

            if (i!=j && arr[i] == arr[j])
            {
                i++;
                j--;
            }
            else
            {
                flag = true;
                break;    
            }
    } */

//* Official Method*************************************
    /* for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[n-1-i])
        {
            flag = false;
            break;
        }
        
    }
    
    if (flag == true)
    {
        cout<<"palindrome"<<endl;
    }
    else
    {
        cout<<"not palindrome"<<endl;
    }
 */
    return 0;
}