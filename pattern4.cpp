#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
//*Pattern Questions
//* Q1.
/*      *****                               //Hollow Square with Diagonals
        ** **
        * * *
        ** **
        *****        */

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i==j || i==1 || i==n || j==1 || j==n || j==(n-i+1))
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

//* Q2.
/*      *****               //Hollow Inverted Right Triangle
        *  *
        * *
        **
        *        */

       for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (i == 0 || j == 0 || j==(n-i-1))
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

//* Q3.
/*      *                   //Hollow Pyramid Star Pattern
       * *
      *   *
     *     *
    *********       */

   for (int i = 1; i <= n; i++)
    {
        for (int k = n-i; k >= 1; k--)
        {
            cout<<" ";
        }
        for (int j = 0; j < (2*i-1); j++)
        {
            if (i==n || j==0 || j==(2*i-2))
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

//* Q4.
/*      *               //Half Diamond Star Pattern
       **
      ***
     ****
    *****
     ****
      ***
       **
        *      */

    for (int i = 0; i < n; i++)
    {
        for (int j = n-i; j >1; j--)
        {
            cout<<" ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout<<"*";
        }
        cout<<endl;        
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<" ";
        }
        for (int k = n-i-1; k >= 1; k--)
        {
            cout<<"*";
        }
        cout<<endl;        
    }

    //* Q5.
/*         *                    //Diamond Star Pattern
          ***
         *****
        *******
       *********
        *******
         *****
          ***
           *            */

    int star = 1;
    int space = n-1;

    for (int i = 1; i < 2*n; i++)
    {
        for (int j = 0; j < space; j++)
        {
            cout<<" ";
        }
        for (int k = 0; k < star; k++)
        {
            cout<<"*";
        }
        cout<<endl;
        if (i<n)
        {
            space--;
            star += 2;
        }
        else{
            space++;
            star -= 2;
        }
    }

    //* Q6.
/*       *****                  //Right Arrow Star Pattern
          ****
           ***
            **
             *
            **
           ***
          ****
         *****          */ 

    int star = n;
    int space = 0;
    
    for (int i = 1; i < 2*n; i++)
    {
        for (int k = 0; k < space; k++)
        {
            cout<<" ";
        }
        for (int j = 0; j < star; j++)
        {
            cout<<"*";
        }
        cout<<endl;
        if (i<n)
        {
            space++;
            star--;
        }else{
            space--;
            star++;
        }
    }

    //* Q7.
/*     *****            //Left Arrow Star Pattern
       ****
       ***
       **
       *
       **
       ***
       ****
       *****           */

    int star = n;
    int space = 0;

    for (int i = 1; i < 2*n; i++)
    {
        for (int j = 0; j < star; j++)
        {
            cout<<"*";
        }
        for (int k = 0; k < space; k++)
        {
            cout<<" ";
        }
        cout<<endl;
        if (i<n)
        {
            space++;
            star--;
        }else{
            space--;
            star++;
        }
    }

        //* Q8.
/*         +                //Plus Star Pattern
           +
           +
           +
       +++++++++
           +
           +
           +
           +              */
    
    for (int i = 1; i < 2*n; i++)
    {
        for (int j = 1; j < 2*n; j++)
        {
            if (i==n || j==n)
            {
                cout<<"+";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    //* Q9.
/*  *       *               //X Star Pattern
     *     *
      *   *
       * *
        *
       * *
      *   *
     *     *
    *       *           */    

   for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < (2*n); j++)
        {
            if (j==i || j==(2*n)-i)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = 1; j < (2*n); j++)
        {
            if (j==i || j==(2*n)-i)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    //* Q10.
/*   ***            //Eight Star Pattern
    *   *
    *   *
    *   *
     *** 
    *   *
    *   *
    *   *
     ***            */
    
    for (int i = 1; i < 2*n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if (i==1 || i==(2*n)-1 || i==n)
            {
                if (j==1 || j== n)
                {
                    cout<<" ";
                }
                else{
                    cout<<"*";
                }
            }
            else{
                if (j==1 || j==n)
                {
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }            
        }
        cout<<endl;
    }

//* Q11.
//*     *****     *****               //Heart Star Pattern
//*    *******   ******* 
//*   ********* *********
//*   *******************
//*    *****************
//*     ***************
//*      *************
//*       ***********
//*        *********
//*         *******
//*          *****
//*           ***
//*            *              

    int i,j;
    for (i = n/2; i < n; i+=2)
    {
        for (j = 1; j < n-i; j+=2)
        {
            cout<<" ";
        }
        for (j = 1; j <= i; j++)
        {
            cout<<"*";
        }
        for (j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        for (j = 1; j <= i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for (i = n; i >= 1; i--)
    {
        for (j = i; j < n; j++)
        {
            cout<<" ";
        }
        for (j = 1; j <= (i*2-1); j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    //* Q12.
/*      *****     *****             //Heart Star Pattern with Name
       *******   *******
      ********* *********
      *****codeforwin****
       *****************
        ***************
         *************
          ***********
           *********
            *******
             *****
              ***
               *            */

    int i,j;
    char name[50];
    cout<<"Enter your name";
    gets(name);
    int len = strlen(name);

    for (i = n/2; i < n; i+=2)
    {
        for (j = 1; j < n-i; j+=2)
        {
            cout<<" ";
        }
        for (j = 1; j <= i; j++)
        {
            cout<<"*";
        }
        for (j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        for (j = 1; j <= i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for (i = n; i >= 1; i--)
    {
        if (i==n)
        {
            for (j = 1; j <= ((2*n-len)/2); j++)
            {
                cout<<"*";
            }
            cout<<name;
            for (j = 1; j < ((2*n-len)/2); j++)
            {
                cout<<"*";
            }
        }
        else{
            for (j = i; j < n; j++)
            {
                cout<<" ";
            }
            for (j = 1; j <= (i*2-1); j++)
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }       
    return 0;
}