#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    //*Pattern Questions

    //* Q1.
    /*    ****                  //Rectangle Pattern
          ****
          ****
          ****
          ****  */


    /* for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    } */

    //* Q2.
    /*     ****                 //Hollow Rectangle Pattern
           *  *  
           *  *  
           *  *  
           ****   */

          
    /*  for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == (n-1))
        {
            for (int j = 0; j < n-1; j++)
            {
                cout<<"*";
            }
            
        }
        else
        {
            for (int j = 0; j < n-1; j++)
            {
                if (j == 0 || j == (n-2))
                {
                    cout<<"*";
                }
                else
                {
                    cout<<" ";
                }
            }
        }
        cout<<endl;
        
    } */

    //* Q3.
    /*     *****                //Inverted Half Pyramid
           ****
           ***
           **
           *        */

    /*       
    for (int i = 0; i < n; i++)
    {
        for (int j = (n-i); j > 0 ; j--)
        {
        cout<<"*";
        }
        cout<<endl;
        
    }*/
    
    //* Q4.
    /*        *                 //Half Pyramid after 180 rotation
             **
            ***
           ****
          *****  */  
    
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n-i-1); j++)
        {
            cout << " ";
        }
        for (int k = 0; k < (i+1); k++)
        {
            cout << "*";
        }
        cout << endl;
    }  */

    //* Q5.
    /*    1                 //Half Pyramid using numbers
          22
          333
          4444
          55555   */
    /*

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < (i+1) ; j++)
        {
            cout << i;
        }
        cout << endl;
    }   */

    //* Q6.
    /*    1                   //Floyd's Triangle
          2 3
          4 5 6
          7 8 9 10
          11 12 13 14 15    */
    /* int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<k<<" ";
            k++;
        }
        cout<<endl;
    } */

    //* Q7.
    /*     *      *             //Butterfly Pattern
           **    **
           ***  ***
           ********
           ********
           ***  ***
           **    **
           *      *        */       
    
    /* for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<<"*";
        }
        int space = 2*n - 2*i;
        for (int j= 1; j <= space; j++)
        {
            cout<<" ";
        }
        for (int j = 1; j <=i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<<"*";
        }
        int space = 2*n - 2*i;
        for (int j= 1; j <= space; j++)
        {
            cout<<" ";
        }
        for (int j = 1; j <=i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
     */
    return 0;
}