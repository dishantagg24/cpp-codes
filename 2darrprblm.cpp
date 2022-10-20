//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }

//* Q1.Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1
/*  Input:  
    3 3
    1 0 0
    0 0 1
    0 0 0
    Output:
    1 1 1
    1 1 1
    1 0 1           */

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                arr[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]==-1){
                for (int k = 0; k < n; k++)
                {
                    if (arr[i][k]!=-1)
                    {
                        arr[i][k]=1;
                    }
                }
                for (int k = 0; k < m; k++)
                {
                    if (arr[k][j]!=-1)
                    {
                        arr[k][j]=1;
                    }
                }
                arr[i][j] = 1;                
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j==m-1)
            {
            cout<<arr[i][j];
            }
            else{
            cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }

//*Q2.The Xs and 0s must be filled alternatively, the matrix should have outermost rectangle of Xs, then a rectangle of 0s, then a rectangle of Xs, and so on.. 
/*  Input:
    6 7
    Output:     
    X X X X X X X
    X 0 0 0 0 0 X
    X 0 X X X 0 X
    X 0 X X X 0 X
    X 0 0 0 0 0 X
    X X X X X X X       */

    char arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] == 'A';
        }
    }

    int i=0,j=0;
    while (i<(n/2) && j<(m/2))
    {
        if (i%2==0 && j%2==0)
        {
            int row_start=i,col_start=j,row_end=n-1-i,col_end=m-1-j;
                for (int col = col_start; col <= col_end; col++)
                {
                    arr[row_start][col] = 'X';
                }
                row_start++;
                for (int row = row_start; row <= row_end; row++)
                {
                    arr[row][col_end] = 'X';
                }
                col_end--;
                for (int col = col_end; col >= col_start; col--)
                {
                    arr[row_end][col] = 'X';
                }
                row_end--;
                for (int row = row_end; row >= row_start; row--)
                {
                    arr[row][col_start] = 'X';
                }
                col_start++;
        }
        else{
            int row_start=i,col_start=j,row_end=n-1-i,col_end=m-1-j;
                for (int col = col_start; col <= col_end; col++)
                {
                    arr[row_start][col] = '0';
                }
                row_start++;
                for (int row = row_start; row <= row_end; row++)
                {
                    arr[row][col_end] = '0';
                }
                col_end--;
                for (int col = col_end; col >= col_start; col--)
                {
                    arr[row_end][col] = '0';
                }
                row_end--;
                for (int row = row_end; row >= row_start; row--)
                {
                    arr[row][col_start] = '0';
                }
                col_start++;
        }
        i++;
        j++;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j==m-1)
            {
                cout<<arr[i][j];
            }else{
                cout<<arr[i][j]<<" ";
            }           
        }
        cout<<endl;
    }

//*Q3.Given a 2D matrix, print all elements of the given matrix in diagonal order.
/*  Input:
    5 4
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    17 18 19 20
    Output:    
    1 
    5 2
    9 6 3
    13 10 7 4
    17 14 11 8
    18 15 12
    19 16
    20          */

    int k=0,i=0,j=0,originali=0,originalj=0;
    while (originali<n && originalj<m)
    {
        i=originali;
        j=originalj;
        while (i>=0 && j>=0 && i<n && j<m)
        {        
            if (i+j==k)
            {
                cout<<arr[i][j]<<" ";
            }
            i--;
            j++;
        }
        k++;
        if (k>=n)
        {
            originalj++;
        }else{
            originali++;
        }
        cout<<endl;
    }

//* Q4.Find the length of the longest chain of consecutive integers in an unsorted 2D square array   
/*  Input:
    3 3
    1 2 3
    4 5 6
    7 8 9
    Output:
    9           */
    int k=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == k)
            {
                k++;
                i=0;j=-1;
            }
        }
    }
    cout<<k-1;
    return 0;
}