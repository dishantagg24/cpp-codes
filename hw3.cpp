#include<iostream>
using namespace std;

//* Q1. Check odd even using function*************************
/* bool oddeven(int n){
    if (n % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
} */

//* Q2. Check given char. is an alphabet or not with the help of function*****
/* void alpha(char c){
    if (97 <= (int)c && (int)c <= 122 || 65 <= (int)c && (int)c <= 90 )
    {
        cout<<"alphabet";
    }
    else{cout<<"no buddy it's not an alphabet";}
} */

//* Q3. Maximum among 3 nos. using function*****************************
/* int max(int a,int b, int c){
    if (a>b && a>c)
    {
        return a;
    }
    else if (b>c && b>a)
    {
        return b;
    }
    else
    {
        return c;
    }   
} */

//* Q4. Minimum among 3 nos. using function****************************
/* int min(int a,int b, int c){
    if (a<b && a<c)
    {
        return a;
    }
    else if (b<c && b<a)
    {
        return b;
    }
    else
    {
        return c;
    }   
} */

//* Q5. Swap the value of 2 intergers using function********************

//5.1. Swap using refernce************
/* void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
    cout<<a<<endl<<b;
} */

//5.2. Swap using pointer*************
/* void swappointer(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
} */

//* Q6. Check a person eligible for vote using function*********************
/*  bool vote(int age){
    if (age >= 18)
    {
        return true;
    }
    else
    {
        return false;
    }    
}  */

int main(){

//    int age;
//    cin>>age;
//    int x,y;
//    cin>>x>>y;
//    swap(x,y);
//    swappointer(&x , &y);
//    cout<<x<<endl<<y;

//    int n,b,c,a;
//    cin>>a>>b>>c;
//    cin>>n;
//    char c;
//    cin>>c;

//* Check odd even using function
    /* if (oddeven(n))
    {cout<<"even";}
    else{cout<<"odd";} */

//    alpha(c);
//    cout<<max(a,b,c);
//    cout<<min(a,b,c);

//* Check a person eligible for vote using function
    /* if (vote(age))
    {cout<<"eligible and vote buddy";}
    else{cout<<"play and focus on study";}  */
    return 0;
}