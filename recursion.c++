//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
using namespace std;

//*Calculate till sum n
int sum(int n){
    if (n==0)
    {
        return 0;
    }
    return n+sum(n-1);
}

//*Calculate n raised to power of p
//*Official Method (O(n))
int power(int n,int p){
	if (p == 0)
	{
		return 1;
	}	
	return n*power(n,p-1);	
}  

//*Optimised Approach (O(logn))
int power(int n,int p){
	if (p == 0)
	{
		return 1;
	}else if (p%2==0)
    {
        int y=power(n,p/2);
        return y*y;
    }
    else{
    	return n*power(n,p-1);	
    }	
}  

//*Calculate factorial of a no.
int factorial(int n){
    if (n == 0)
    {
        return 1;
    }
    return n*factorial(n-1);
}

//*Print the nth Fibonacci number
int fib(int n){
    if (n == 1 || n == 0)
    {
        return n;
    }
    return fib(n-1)+ fib(n-2);
}

//*H.W. Questions
//*Print nos. from n to 1 in decreasing order
//*Not official Method
/* void decreasing(int n){
    if (n>0)
    {
        cout<<n<<" ";
    }
    decreasing(n-1);
}  */

//*Official Method
void decreasing(int n){
    if (n==1)
    {
        cout<<1<<" ";
        return;
    }
    cout<<n<<" ";
    decreasing(n-1);
} 

//*Print nos. from 1 to n in increasing order
void increasing(int n){
    if (n == 1)
    {
        cout<<1<<" ";
        return;
    }
    increasing(n-1);
    cout<<n<<" ";
} 

//* Check Prime no. using recursion
void checkPrime(int n,int num){
    if (num==n)
    {
        cout<<"Prime";
        return;
    }
    if (n%num==0)
    {
        cout<<"Not Prime";
        return;
    }
    checkPrime(n,num+1);
    return;
}

//*LCM using recursion
void lcm(int a, int b,int multiple){
    if (multiple%b==0)
    {
        cout<<multiple;
        return;
    }
    lcm(a,b,multiple+a);
    return;
}
int main(){
	//int n,p;
	//cin>>n>>p;
    //cout<<sum(n);
	//cout<<power(n,p);
    //cout<<factorial(n);
    //cout<<fib(n);
    int n;
    cin>>n;
    //decreasing(n);
    //increasing(n);
    //checkPrime(97,2);
    //lcm(6,4,6);
	return 0;
}