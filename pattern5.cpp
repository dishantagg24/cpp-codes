//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

//*Pattern Questions
//* Q1.
/*     10101            //Chessboard Number Pattern
       01010
       10101
       01010
       10101        */

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i%2==0)
            {
                if (j%2 == 0)
                {
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }else{
                if (j%2 == 0)
                {
                    cout<<0;
                }
                else{
                    cout<<1;
                }
            } 
        }
        cout<<endl;
    }

//Another Method
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (k==1)
            {
                cout<<1;
            }
            else{
                cout<<0;
            }
            k *= -1;
        }
        if (n%2==0)
        {
            k *= -1;
        }
        cout<<endl;
    }

//* Q2.
/*  55555           //Number Pattern 1
    54444
    54333
    54322
    54321       */

    for (int i = 1; i <= n; i++)
    {
        int k=n;
        for (int j = 1; j < i; j++)
        {
            cout<<k;
            k--;
        }
        for (int t = n-i; t >= 0; t--)
        {
            cout<<n-i+1;
        }
        cout<<endl;
    }

//* Q3.
/*  55555           //Number Pattern 2
    44445
    33345
    22345
    12345       */

    for (int i = 1; i <= n; i++)
    {
        for (int t = n-i; t >= 0; t--)
        {
            cout<<n-i+1;
        }
        int k=n-i+2;
        for (int j = 1; j < i; j++)
        {
            cout<<k;
            k++;
        }
        cout<<endl;
    }    

//* Q4.
/*  54321           //Number Pattern 3
    54322
    54333
    54444
    55555           */

    for (int i = 1; i <= n; i++)
    {
        int k = n;
        for (int t = n-i; t >= 0; t--)
        {
            cout<<k;
            k--;
        }
        for (int j = 1; j < i; j++)
        {
            cout<<i;
        }
        cout<<endl;
    }

//* Q5.
/*  12345       //Number Pattern 4
    22345
    33345
    44445
    55555       */

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cout<<i;
        }
        int k = i;
        for (int t = n-i; t >= 0; t--)
        {
            cout<<k;
            k++;
        }
        cout<<endl;
    }

//* Q6.
/*  12345           //Number Pattern 5
    23455
    34555
    45555
    55555           */

    for (int i = 1; i <= n; i++)
    {
        int k = i;
        for (int t = n-i; t >= 0; t--)
        {
            cout<<k;
            k++;
        }
        for (int j = 1; j < i; j++)
        {
            cout<<n;
        }
        cout<<endl;
    }

//* Q7.
/*  12345       //Number Pattern 6
    23451
    34521
    45321
    54321       */

    for (int i = 1; i <= n; i++)
    {
        int k = i;
        for (int t = n-i; t >= 0; t--)
        {
            cout<<k;
            k++;
        }
        int s = i-1;
        for (int j = 1; j < i; j++)
        {
            cout<<s;
            s--;
        }
        cout<<endl;
    }

//* Q8.
/*  555555555           //Number Pattern 7
    544444445
    543333345
    543222345
    543212345
    543222345
    543333345
    544444445
    555555555          */

    for (int i = 1; i <= n; i++)
    {
        int k=n;
        for (int j = 1; j < i; j++)
        {
            cout<<k;
            k--;
        }
        for (int s = 0; s < (2*(n-i)) + 1; s++)
        {
            cout<<n-i+1;
        }
        int m = n-i+2;
        for (int t = 1; t < i; t++)
        {
            cout<<m;
            m++;
        }
        cout<<endl;
    }
    for (int i = n; i >= 2; i--)
    {
        int k=n;
        for (int j = 1; j < i; j++)
        {
            cout<<k;
            k--;
        }
        for (int s = 0; s < (2*(n-i)) + 1; s++)
        {
            cout<<n-i+2;
        }
        int m = n-i+2;
        for (int t = 1; t < i; t++)
        {
            cout<<m;
            m++;
        }
        cout<<endl;
    }

//* Q9.
//*    1 2 3 4 5               //Spiral Number Pattern
//*    16 17 18 19 6
//*    15 24 25 20 7
//*    14 23 22 21 8
//*    13 12 11 10 9         

    int a=1;
    int arr[n][n];
    
    int row_start=0;
    int row_end=n-1;
    int col_start=0;
    int col_end=n-1;

    while (row_start <= row_end && col_start<=col_end)
    {
        for (int col = col_start; col <= col_end; col++,a++)
        {
            arr[row_start][col] = a;            
        }
        row_start++;
        for (int row = row_start; row <= row_end; row++,a++)
        {
            arr[row][col_end] = a;
        }
        col_end--;
        for (int col = col_end; col >= col_start; col--,a++)
        {
            arr[row_end][col] = a;
        }
        row_end--;
        for (int row = row_end; row >= row_start; row--,a++)
        {
            arr[row][col_start] = a;            
        }
        col_start++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

//* Q10.
/*  1               //Number Pattern 8
    22
    333
    2222
    11111           */

    for (int i = 1; i <= n; i++)
    {
        if (i<=n/2)
        {
            for (int j = 1; j <= i; j++)
            {
                cout<<i;
            }
        }else{
            int k = n-(i-1);
            for (int t = 1; t <= i; t++)
            {
                cout<<k;
            }
        }
        cout<<endl;
    }

//* Q11.
/*  1                   //Number Pattern 9
    32
    456
    10987
    1112131415         */

    int k=0;
    int s;
    for (int i = 1; i <= n; i++)
    {
        if (i%2==0)
        {
            s = k+i;
        }else{
            s = k+1;
        }       
        for (int j = 1; j <= i; j++)
        {
            cout<<s;
            if (i%2==0)
            {
                s--;
            }else{
                s++;
            }
            k++;
        }
        cout<<endl;
    }

//* Q11.
/*  1                   //Number Pattern 10
    24
    71116
    22293746
    56677992106         */

    int k=1;
    int s=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<k;
            s++;
            k += s;
        }
        cout<<endl;
    }

//* Q11.
/*  1                   //Number Pattern 11
    26
    3710
    481113
    59121415            */

    for (int i = 1; i <= n; i++)
    {
        int s=n;
        int k=i;
        for (int j = 1; j <= i; j++)
        {
            cout<<k;
            s--;
            k += s;
        }
        cout<<endl;
    }
    
    return 0;
}