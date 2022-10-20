//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
using namespace std;

//*Print all nos. till n that are divisible by a or b
int divisible(int n,int a,int b){
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);
    return c1+c2-c3;
}

//*Print greatest common divisor(H.C.F) of a and b using Euclid Algorithm
int gcd(int a,int b){
    while (b!=0)
    {
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
}

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    //cout<<divisible(n,a,b);
    cout<<gcd(a,b);
    return 0;
}