#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    //* More Pattern Questions 
    //* Q1.
    /*     1 2 3 4 5            //inverted Pattern
           1 2 3 4
           1 2 3
           1 2
           1            */ 
    /* for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n-i ; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    } */

    //* Q2.
    /*     1                //0-1 Pattern
           0 1
           1 0 1
           0 1 0 1
           1 0 1 0 1    */

    /* for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout<<"1"<<" ";
            }
            else
            {
                cout<<"0"<<" ";
            }
            
        }
        cout<<endl;
    } */

    //* Q3.
    /*        *****         //Rhombus Pattern
             *****
            *****
           *****
          *****     */
    /* for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <=(n-i); k++)
        {
            cout<<" ";
        }
        for (int j = 1; j <= n; j++)
        {
            cout<<"*";
        }
        cout<<endl;
        
    } */

    //* Q4.
    /*         1            //Number Pattern
              1 2
             1 2 3
            1 2 3 4
           1 2 3 4 5  */

    /* for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n-i; k++)
        {
            cout<<" ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    } */

    //* Q5.
    /*             1               //Palindromic Pattern
                 2 1 2
               3 2 1 2 3
             4 3 2 1 2 3 4
           5 4 3 2 1 2 3 4 5      */

    /*  for (int i = 1; i <= n; i++)
    {
        for (int k = 2*n-2*i; k >=1; k--)
        {
            cout<<" ";
        }
        for (int j = i; j >=1; j--)
        {
            cout<<j<<" ";    
        }
        if (i>1)
            {
                for (int j = 2; j <= i; j++)
                {
                    cout<<j<<" ";
                }
                
            }
        cout<<endl;      
        
    }     */

    //* Q6.
    /*           *              //Star Pattern
               * * *
             * * * * *
           * * * * * * *
           * * * * * * *
             * * * * *
               * * *
                 *           */
    /* for (int i = 1; i <= n; i++)
    {
        for (int k = 2*n-2*i; k >= 1; k--)
        {
            cout<<" ";
        }
        for (int j = 1; j <= (2*i-1) ; j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int k = 2*n-2*i; k >= 1; k--)
        {
            cout<<" ";
        }
        for (int j = 1; j <= (2*i-1) ; j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    } */

    //* Q7.
    /*          *       *           //Zigzag Pattern
              *   *   *   *
            *       *       *       */         
    
    /* for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (((i+j) % 4 == 0) || ((i==2) && (j % 4 == 0)))
            {
                cout<<"* ";
            }
            else
            {
                cout<<"  ";
            }
            
        }
        cout<<endl;
    }  */ 
    
    return 0;
}