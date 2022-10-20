#include <iostream>
using namespace std;

int main()
{
    //* check entered number is prime or not (not official method)    
    int n,div=2;
    cin>>n;
    if(n > div){
        if(n % div == 0)
        {
            cout << "not Prime no. " << endl;
        }
        else
        {
            for ( ; div < n; div++)
            {
              if(n % div == 0)
                {
                    cout << "not Prime no. " << endl;
                    
                }  
              else if(n == div + 1)
              {
                  cout << "Prime no. " << endl;
              }
            }
            
        }
        
    }
    else{
        cout << "prime no " << endl;
    }

    //*  Printing prime no............
    //    int n;
    //    cin>>n;
    /* int i;
    for(i = 2; i <= n-1; i++)
    {
        if(n % i == 0)
        {
            cout<<"not prime"<<endl;
            break;  
        }  
    }
    if(i == n){
        cout<<"prime no."<<endl;
    } */

    //* Printing all prime nos. till n
    /* int n, a = 2;
    cin >> n;
    cout << a << endl;
    for (int num = 3; num <= n; num++)
    {
        int i;
        for (i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                break;
            }
        }
        if (i == num)
        {
            cout << num << endl;
        }
    } */

    //* Printing all prime nos. b/w a and b
    /* int a,b;    
    cin>>a>>b;

    for (int num = a; num <= b; num++)
    {
        int i;
        for ( i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                break;
            }
            
        }
        if(i == num)
            {
                cout<<num<<endl;
            }
        
    } */

    return 0;
}