//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
using namespace std;

//* Prime no. using Sieve of Eratothenes
void primeSieve(int n){
    int arr[100]={0};

    for (int i = 2; i <= n; i++)
    {
        if (arr[i]==0)
        {
            for (int j = i*i; j <=n ; j+=i)
            {
                arr[j]=1;
            }   
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (arr[i]==0)
        {
            cout<<i<<" ";
        }
        
    }
    cout<<endl;
}

//*Prime Factorisation using Sieve of Eratothenes
void primeFactor(int n){
    int spf[100]={0};
    for (int i = 2; i <= n; i++)
    {
        spf[i]=i;
    }

    for (int i = 2; i <= n; i++)                //Assigning smallest divisor or factor to every element like smallest factor of 12 is 2 and of 25 is 5  
    {
        if (spf[i] == i)
        {
            for (int j = i*i; j <= n; j+=i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    
    while (n!=1)
    {
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }   
}

//*H.W. Question
//*Prime nos. b/w a and b using sieve of eratothenes
void prime2(int a,int b){
    int arr[100]={0};
    for (int i = 2; i <= b; i++)
    {
        if (arr[i] == 0)
        {
            int j = i*i;
            while (j<=b)
            {
                arr[j] = 1;
                j+=i;
            }
        }        
    }
        
for (int i = a; i <= b; i++)
{
    if (arr[i] == 0)
    {
        cout<<i<<" ";
    }
}

}

int main(){
    // int n;
    // cin>>n;
    // primeSieve(n);
    // primeFactor(n);
    int a,b;
    cin>>a>>b;
    prime2(a,b);
    return 0;
}