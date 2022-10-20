//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

//* Q1.
//*    ABCDEDCBA                //Alphabet Pattern 1
//*    ABCD DCBA
//*    ABC   CBA
//*    AB     BA
//*    A       A               

    int t;
    for (int i = 1; i <= n; i++)
    {
        char a = 'A';
        for (int j = n; j >= i; j--)
        {
            cout<<a;
            a++;
        }
        for (int k = 1; k <= ((2*i)-3); k++)
        {
            cout<<" ";
        }
        a--;
        if (i<=2)
        {
          t=i+3;  
          if (i==1)
          {
              a--;
          }
        }else{
            t=n;
        }
        
        for (; t >= i; t--)
        {   
            cout<<a;
            a--;
        }
        cout<<endl;
    }

//* Optimised Solution

    for (int i = 1; i <= n; i++)
    {
        char k = 'A';
        for (int j = 1; j <= (2*n)-1; j++)
        {
            if (j<=(n+1)-i || j>= (n-1)+i)
            {
                cout<<k;
                if (j<n)
                {
                    k++;
                }else{
                    k--;
                }
            }else{
                cout<<" ";
                if (j==n)
                {
                    k--;
                }
            }
        }
        cout<<endl;
    }

//* Q2.
/*      A               //Alphabet Pattern 2
       ABA
      ABCBA
     ABCDCBA
    ABCDEDCBA           */

    for (int i = 1; i <= n; i++)
    {
        char k='A';
        for (int j = 1; j <= (2*n)-1; j++)
        {
            if (j>= n-i+1 && j<= (n+i)-1)
            {
                cout<<k;
                if (j<n)
                {
                    k++;
                }else{
                    k--;
                }
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

//* Q3.
/*  A1              //Alphabet Number Pattern 1
   AB12
  ABC123
 ABCD1234
ABCDE12345          */   

for (int i = 1; i <= n; i++)
    {
        char k='A';
        int t=1;
        for (int j = 1; j <= 2*n; j++)
        {
            if (j>=n-i+1 && j<= n+i)
            {
                if (j<=n)
                {
                    cout<<k;
                    k++;
                }
                else{
                    cout<<t;
                    t++;
                }
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

//* Q4.
/*  1               //Alphabet Number Pattern 2
   12A
  123AB
 1234ABC
12345ABCD           */   

    for (int i = 1; i <= n; i++)
    {
        char k='A';
        int t=1;
        for (int j = 1; j <= (2*n)-1; j++)
        {
            if (j>= n-i+1 && j<= n+i-1)
            {
                if (j<=n)
                {
                    cout<<t;
                    t++;
                }
                else{
                    cout<<k;
                    k++;
                }
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
//* Q5.
/*  *********           //Star Pattern 
    *       *
    *       *
    *  ***  *
    *  * *  *
    *  ***  *
    *       *
    *       *
    *********           */

    for (int i = 1; i <= (2*n)-1; i++)
    {
        for (int j = 1; j <= (2*n)-1; j++)
        {
            if (i==1 || i==(2*n)-1 || j==(2*n)-1 || j==1 || (i>=n-1&&i<=n+1&&j>=n-1&&j<=n+1) && (i!=n || j!=n))
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

//* Q6.
/*        0                     //Number Pattern (Hard)  n=11
         121
        23432
       3456543       
      456787654
     56789098765
    6789012109876    
   789012343210987
  89012345654321098
 9012345678765432109
012345678909876543210
 9012345678765432109
  89012345654321098
   789012343210987
    6789012109876
     56789098765
      456787654
       3456543
        23432
         121
          0                     */

    int m=0;
    int k=1;
    for (int i = 1; i <= (2*n)-1; i++)
    {
        i<=n?m++:m--;
        k=m-1;
        for (int j = 1; j <= (2*n)-1; j++)
        {
            if (j>=n-m+1 && j<= n+m-1)
            {
                cout<<(j<n?k++%10:k--%10);
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }      

//* Q7.
/*  A               //Alphabet Pattern 3
   CB
  FED
 JIHG
ONMLK               */

    for (int i = 1; i <= n; i++)
    {
        char k='A';
        k += (i*(i+1)-2)/2;
        for (int t = 1; t <= n-i; t++)
        {
            cout<<" ";
        }
        for (int j = 1; j <= i; j++)
        {
          cout<<k;
          k--;  
        }
        cout<<endl;
    }

//* Q8.
/*        *             //Star Pattern (Hard)
         **
        ***
       ****
      *****
     ******
     |*****
*    | ****
**   |  ***
***  |   **
**** |    *
*****|
******
*****
****
***
**
*                       */

    int k;
    for (int i = 1; i <= (3*n); i++)
    {
        for (int j = 1; j <= (2*n)-1; j++)
        {
          if (i<=n)
          {
              if (j>=2*n-i)
              {
                  cout<<"*";
              }else{
                  cout<<" ";
              }
          }
          else if(i<=2*n){
              k=0;
              if (j==n)
              {
                  k=1;
                  cout<<"|";
              }
              if (j<=(i-n-1))
              {
                  k=1;
                  cout<<"*";
              }
              if (j>=i)
              {
                  k=1;
                  cout<<"*";
              }
              if (k==0)
              {
                  cout<<" ";
              }
          }
          else if (i<=3*n)
          {
              if (j<=3*n+1-i)
              {
                  cout<<"*";
              }else{
                  cout<<" ";
              }
          }
          
        }
        cout<<endl;
    }

//* Q9.
/*  ABCDEFG             //Alphabet Pattern 4
    ABC EFG
    AB   FG
    A     G             */

    for (int i = 1; i <= n; i++)
    {
        char k='A';
        for (int j = 1; j <= 2*n-1; j++)
        {
            if ((j>= n+i-1) || (j<=n-i+1))
            {
                cout<<k;
            }
            else{
                cout<<" ";
            }
            k++;
        }
        cout<<endl;
    }

//* Q10.
/*     1            //Alphabet Number Pattern 3
      A B
     1 2 3
    A B C D         */

    for (int i = 1; i <= n; i++)
    {
        int t=1;
        char k='A';
        for (int j = 1; j <= 2*n-1; j++)
        {
            if (i%2==0)
            {
                if (j>=n-i+1 && j<=n+i-1 && j%2!=0)
                {
                    cout<<k;
                    k++;
                }else{
                    cout<<" ";
                }
            }
            else{
                if (j>=n-i+1 && j<=n+i-1 && j%2==0)
                {
                    cout<<t;
                    t++;
                }else{
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}