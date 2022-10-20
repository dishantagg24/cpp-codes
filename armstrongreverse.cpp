#include<iostream>
#include<math.h>
using namespace std;

int main(){
     int n;
     cin>>n;

    //* PRIME NO.
    /* int flag = 0;

    for (int i = 2; i < n; i++)
    {
        if ( n % i == 0)
        {
            cout<<"not prime";
            flag =1;
            break;
        }
        
    }
     if (flag == 0)
    {
        cout<<"prime";
    } */

    //***********Reverse of a Number*******************
    
    /* int reverse = 0;
    while(n>0)
    {
        int lastdigit = n % 10;
        reverse = reverse*10 + lastdigit;
        n = n/10; 
    }
    cout<<reverse; */

//*************Armstrong number*******************
     float sum = 0;
    int originaln = n;
    while(n > 0){
        int lastdigit = n % 10;
        
        sum +=  pow(lastdigit,3);        //a += b is short-hand for a = a + b
                                         //a =+ b is a = (+b), i.e. assigning the unary + of b to a
        n = n/10;
    }
    if(sum == originaln){
        cout<<"armstrong no."<<endl;
    }
    else
    {
        cout<<"not neil armstrongxd"<<endl;
    } 
//************print ascii value of any character*****************
   /*  char c;
    cin>>c;
    cout<<int(c); */

//************print all factors of given no.*********************
    /* for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout<<i<<endl;
        }
        
    } */
//***********factorial of a no. without function***************    
    /* int a = 1;
    for (int i = 1; i <=n ; i++)
    {
           a = a * i;
    }
    cout<<a; */

//***************check vowel or consonant***************
    /* char c;
    cin>>c;
    if (c == 'a' || c == 'e' || c == 'i' ||c == 'o' ||c == 'u')
    {
        cout<<"vowel";
    }
    else
    {
        cout<<"consonant";
    } */
       
//***************Swap first & last digit of a number***************
/*   Input:
     1234
     Output:
     4231           */
         int n;
    cin>>n;

    int digits = log10(n);
    int lastDigit = n%10;
    int swapnumber=0;
    int divider = pow(10,digits);
    swapnumber  = lastDigit*divider;
    swapnumber += n % divider;
    swapnumber -= lastDigit;
    swapnumber += n/divider;
    cout<<swapnumber;
    return 0;
}