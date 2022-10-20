#include <iostream>
using namespace std;

int main()
{
    // int n;
    // cin>>n;
    int m;
    cin >> m;
    // int arr[n][m];
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cin>>arr[i][j];
    //     }

    // }

    // Dynamically allocation of 2D array
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    //* ****************Printing 2D array***********************************************
    /* for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
//* ****************Searching an element in 2D array********************************
    int key;
    cin>>key;
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == key)
            {
                cout<<i<<" "<<j<<endl;
                cout<<"Element found";
            }

        }

    }  */

    //* ****************Spiral Order Matrix Traversal***********************************
    int rows = 0;
    int rowe = n - 1;
    int cols = 0;
    int cole = m - 1;
    while (rows <= rowe && cols <= cole)
    {
        //* for row_start
        for (int col = cols; col <= cole; col++)
        {
            cout << arr[rows][col] << " ";
        }
        rows++;

        //* for column_end
        for (int row = rows; row <= rowe; row++)
        {
            cout << arr[row][cole] << " ";
        }
        cole--;

        //* for row_end
        if (rows <= rowe)
        {
            for (int col = cole; col >= cols; col--)
            {
                cout << arr[rowe][col] << " ";
            }
        }
        rowe--;

        //* for column_start
        if (cols <= cole)
        {
            for (int row = rowe; row >= rows; row--)
            {
                cout << arr[row][cols] << " ";
            }
        }
        cols++;
    }

    return 0;
}