#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    //* More Pattern Questions 
    //* Q1.
    /*     *                //Half Pyramid Pattern
           **
           ***
           ****
           *****    */
    /* for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<"*";
        }
        cout<<endl;    
    } */

    //* Q2.
    /*    1                 //Half Pyramid using numbers
          1 2
          1 2 3
          1 2 3 4
          1 2 3 4 5  */

    /* for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    } */

    //* Q3.
    /*     1 1 1 1 1        //Inverted Half Pyramid using numbers
           2 2 2 2
           3 3 3
           4 4
           5      */
    
    /* for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    } */
    
    //* Q4.
    /*         1            //Pyramid Pattern for numbers
              2 2
             3 3 3
            4 4 4 4
           5 5 5 5 5  */

    /* for (int i = 1; i <= n; i++)
    {
        for (int k = n-i; k >=1 ; k--)
        {
            cout<<" "; 
        }
        for (int j = 1; j <=i ; j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    } */
    
    //* Q5.
    /*        *         //Hollow Diamond
             * *
            *   *
           *     *
          *       *
          *       *
           *     *
            *   *
             * *
              *         */

    /* for (int i = 1; i <= n; i++)
    {
        for (int k = n-i; k >= 1; k--)
        {
            cout<<" ";
        }
        cout<<"*";
        for (int k = 1; k <= 2*i-3; k++)
        {
            cout<<" ";
        }
        if (i>1)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    
    for (int i = n; i >= 1; i--)
    {
        for (int k = n-i; k >= 1; k--)
        {
            cout<<" ";
        }
        cout<<"*";
        for (int k = 1; k <= 2*i-3; k++)
        {
            cout<<" ";
        }
        if (i>1)
        {
            cout<<"*";
        }
        cout<<endl;
    }  */

    //* Q6.
    /*     *********        //Hollow Diamond inscribed in a Rectangle
           **** ****
           ***   ***
           **     **
           *       *
           *       *
           **     **
           ***   ***
           **** ****
           *********   */

    /* for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1 ; j++)
        {
            cout<<"*";
        }
        for (int k = 1; k <= 2*i-3; k++)
        {
            cout<<" ";
        }
        if (i == 1)
        {
            for (int j = 1; j <= n-1; j++)
            {
                cout<<"*";
            }
            
        }
        else
        {
            for (int j = 1; j <= n - i + 1; j++)
            {
                cout<<"*";
            }
        }
        
        
        cout<<endl;
        
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout<<"*";
        }
        for (int k = 1; k <= 2*i-3; k++)
        {
            cout<<" ";
        }
        if (i == 1)
        {
            for (int j = 1; j <= n-1; j++)
            {
                cout<<"*";
            }
            
        }
        else
        {
            for (int j = 1; j <= n - i + 1; j++)
            {
                cout<<"*";
            }
        }
        cout<<endl;
        
    } */

    //* Q7.
    /*        *****         //Hollow Rhombus
             *   *
            *   *
           *   *
          *****         */

    /* for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n-i; k++)
        {
            cout<<" ";
        }
        
        if (i == 1 || i == n)
        {
            for (int j = 1; j <= n; j++)
            {
                cout<<"*";
            }
            
        }
        else
        {
            cout<<"*";
            for (int k = 1;  k <= n-2;  k++)            
            {
              cout<<" ";  
            }
            cout<<"*";
        }
        cout<<endl;
    } */

    //* Q8.
    /*    *        *            //Hollow Butterfly
          **      **
          * *    * *
          *  *  *  *
          *   **   *
          *   **   *
          *  *  *  *
          * *    * *
          **      **
          *        *      */


    /* for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            cout<<"*";
            for (int k = 1; k <= 2*n-2; k++)
            {
                cout<<" ";
            }
            cout<<"*";
            
        }
        else
        {
            cout<<"*";
            for (int k = 1; k <= i-2; k++)
            {
                cout<<" ";
            }
            cout<<"*";
            for (int k = 1; k <= 2*n-2*i; k++)
            {
                cout<<" ";
            }
            cout<<"*";
            for (int k = 1; k <= i-2; k++)
            {
                cout<<" ";
            }
            cout<<"*";
            
        }
        cout<<endl;
        
    }
    for (int i = n; i >= 1; i--)
    {
        if (i == 1)
        {
            cout<<"*";
            for (int k = 1; k <= 2*n-2; k++)
            {
                cout<<" ";
            }
            cout<<"*";
            
        }
        else
        {
            cout<<"*";
            for (int k = 1; k <= i-2; k++)
            {
                cout<<" ";
            }
            cout<<"*";
            for (int k = 1; k <= 2*n-2*i; k++)
            {
                cout<<" ";
            }
            cout<<"*";
            for (int k = 1; k <= i-2; k++)
            {
                cout<<" ";
            }
            cout<<"*";
            
        }
        cout<<endl;
        
    } */

    //* Q9.
    /*          1               //Pascal's Triangle
               1 1
              1 2 1
             1 3 3 1
            1 4 6 4 1 */

    /* int a = 1;
    for (int i = 0; i < n; i++)
    {
        for (int k = 1; k <= n-i; k++)
        {
            cout<<" ";
        }

        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
            {
                 a = 1;
            }
            else
            {
                 a = (a * (i-j+1))/j;
            }
            cout<<a<<" ";
        }
            cout<<endl;    
    } */
    
    return 0;
}