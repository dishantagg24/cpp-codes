#include<iostream>
#include<cmath>
using namespace std;

//* prime no. using function******************
   /*  bool isprime(int n){
        for (int num = 2; num <= sqrt(n); num++)
        {
            if (n % num == 0)
            {
                return false;
            }
        }
                return true;
        
    } */

//* print fibonacci series*******************
    /* void fibprint(int n){
        int t1 = 0;
        int t2 = 1;
        int nextterm;
        for (int i = 1; i <= n; i++)
        {
            cout<<t1<<endl;
            nextterm = t1 + t2;
            t1 = t2;
            t2 = nextterm;
        }
        
    } */

//* sum of fibonacci series till n******************
    /* int fib(int n){
        if (n<2)
        {
            return 1;
        }
        
        return fib(n-1) + fib(n-2);
    } */

//* factorial of n******************
    int factorial(int n){
        if (n<2)
        {
            return 1;
        }
        return n * factorial(n-1);
    }

//* Calculate Age******************
void CalcAge(int dyear,int dmonth,int ddate){

    int year,month,date;
    cin>>year>>month>>date;
    int cyear,cmonth,cdate;
    cin>>cyear>>cmonth>>cdate;

    dyear = cyear-year;
    dmonth = cmonth-month;
    ddate = cdate-date;

    if (dmonth<0 && ddate>0)
    {
        dmonth = -(dmonth);
        dyear = dyear - 1;
    }
    else if (ddate<0 && dmonth>0)
    {
        ddate = -(ddate);
    }else if (ddate<0 && dmonth<0)
    {
        ddate = -(ddate);
        dmonth = -(dmonth);
        dyear = dyear - 1;
    }
    else if (dyear<0)
    {
        cout<<"you are not born yet";
    }
    else if (dyear==0 && ddate>0 && dmonth>0)
    {
        dmonth = cmonth-month;
        ddate = cdate-date;
    }

    else{
        dyear = dyear-1;
    }
    cout<<dyear<<dmonth<<ddate;
    return;
}

int main(){
    // int n;
    // cin>>n;
    // cout<<fib(n)<<endl;
    // fibprint(n);

//*print nCr value*************************    
     int n,r,s;
     cin>>n>>r;
     s = n - r;
     int nfact = factorial(n);
    int rfact = factorial(r);
    int sfact = factorial(s);
    int ans = (nfact)/(rfact * sfact);
    cout<<ans; 

//*print prime no.************************    
    /* int a,b;
    cin>>a>>b;
    
    for (int i = a; i <= b; i++)
    {
        if (isprime(i))
        {
            cout<<i<<endl;
        }
        
    } */

//*print pascal triangle using nCr value***************    
    /* for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<factorial(i)/(factorial(j)*factorial(i-j))<<" ";
        }
        cout<<endl;
    } */

//*Calculate Age******************************    
    int dyear,dmonth,ddate;
    CalcAge(dyear,dmonth,ddate);

    return 0;
}  