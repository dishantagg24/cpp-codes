#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

//*Printing sum of natural nos.*****************************************
int sumn(int n)
{
    int sum = (n * (n + 1)) / 2;
    return sum;
}

//*Check given 3 nos. are pythagorian triplet****************************
bool pythagorian(int a, int b, int c)
{
    if ((c * c == (a * a + b * b)) || (a * a == (b * b + c * c)) || (b * b == (c * c + a * a)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//*binaryToDecimal*******************************************************
int binaryToDecimal(int n)
{
    int i = 1;
    int ans = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        ans += (lastdigit * i);
        i *= 2;
        n = n / 10;
    }
    return ans;
}

//*octalToDecimal*********************************************************
int octalToDecimal(int n)
{
    int ans = 0;
    int i = 1;
    while (n > 0)
    {
        int lastdigit = n % 10;
        ans += lastdigit * i;
        i *= 8;
        n /= 10;
    }
    return ans;
}

//*hexadecimalToDecimal****************************************************
int hexadecimalToDecimal(string s)
{
    int ans = 0;
    int i = 1;
    int j = s.size();
    for (int k = j - 1; k >= 0; k--)
    {
        if (s[k] >= '0' && s[k] <= '9')
        {
            ans += i * (s[k] - '0');
        }
        else if (s[k] >= 'A' && s[k] <= 'F')
        {
            ans += i * (s[k] - 'A' + 10);
        }
        i *= 16;
    }
    return ans;
}

//*DecimalTobinary**********************************************************
int DecimalTobinary(int n)
{
    int i = 1;
    int ans = 0;
    while (i <= n)
    {
        i = i * 2;
    }
    i = i / 2;
    while (i > 0)
    {
        int lastdigit = n / i;
        n = n - lastdigit * i;
        i = i / 2;
        ans = ans * 10 + lastdigit; 
    }
    return ans;
}

//*DecimalTooctal************************************************************
int DecimalTooctal(int n)
{
    int i = 1;
    int ans = 0;
    while (i <= n) /*Without curly braces, only the first statement following the loop definition is 
                     considered to belong to the loop body. */
        i = i * 8;

    i = i / 8;
    while (i > 0)
    {
        int lastdigit = n / i;
        n = n - lastdigit * i;
        i = i / 8;
        ans = ans * 10 + lastdigit;
    }
    return ans;
}

//*DecimalTohexadecimal******************************************************
string DecimalTohexadecimal(int n){
    int i = 1;
    string ans = "";
    while (i <= n)
    {
        i = i * 16;
    }
    i = i / 16;
    while (i > 0)
    {
        int lastdigit = n/i;
        n = n - lastdigit*i;
        i = i / 16;

        if(lastdigit <= 9)
            ans = ans + to_string(lastdigit);       //to_string converts integer to string
        else
        {
            char c = 'A' + lastdigit - 10;
            ans.push_back(c);
        }
        
    }

    return ans;
}

//*binaryToOctal******************************************************
int binaryToOctal(int n){
    int octalTable[] = {0,1,10,11,100,101,110,111};
    int ans = 0, place = 1;
    while (n>0)
    {
        int last3nos = n%1000;
        for (int i = 0; i < 8; i++)
        {
            if (octalTable[i] == last3nos)
            {
                ans += i*place;
                break;
            }
        }
        place *= 10;
        n/=1000;
    }
    return ans;
}

//*binaryToHexadecimal******************************************************
string binaryToHexadecimal(int n){
    int hexTable[] = {0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111};
    string ans = "";
    
    while (n>0)
    {
        int lastDigit = n%10000;
        for (int i = 0; i < 16; i++)
        {
            if (hexTable[i] == lastDigit)
            {
                if (i<=9)
                {
                    ans += to_string(i);
                }
                else{
                    char c = 'A' - 10 + i;
                    ans.push_back(c);
                }
                break;
            }
        }
        n /= 10000;
    }
    return ans;   
}

//*octalToBinary******************************************************
int octalToBinary(int n){
     int octalTable[] = {0,1,10,11,100,101,110,111};
        int ans=0, place=1;
        while (n>0)
        {
            int lastDigit = n%10;
            ans += octalTable[lastDigit]*place;
            n /= 10;
            place *= 1000;
        }
        return ans;
}

int reverse(int n){
    int ans = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        ans = ans*10 + lastdigit;
        n = n / 10;
    }
    return ans;
}

//*hexadecimalToBinary******************************************************
string hexadecimalToBinary(string hex){
    char bin[65] = "";
    int i = 0;

    /* Extract first digit and find binary of each hex digit */
    for(i=0; hex[i]!='\0'; i++)
    {
        switch(hex[i])
        {
            case '0':
                strcat(bin, "0000");
                break;
            case '1':
                strcat(bin, "0001");
                break;
            case '2':
                strcat(bin, "0010");
                break;
            case '3':
                strcat(bin, "0011");
                break;
            case '4':
                strcat(bin, "0100");
                break;
            case '5':
                strcat(bin, "0101");
                break;
            case '6':
                strcat(bin, "0110");
                break;
            case '7':
                strcat(bin, "0111");
                break;
            case '8':
                strcat(bin, "1000");
                break;
            case '9':
                strcat(bin, "1001");
                break;
            case 'a':
            case 'A':
                strcat(bin, "1010");
                break;
            case 'b':
            case 'B':
                strcat(bin, "1011");
                break;
            case 'c':
            case 'C':
                strcat(bin, "1100");
                break;
            case 'd':
            case 'D':
                strcat(bin, "1101");
                break;
            case 'e':
            case 'E':
                strcat(bin, "1110");
                break;
            case 'f':
            case 'F':
                strcat(bin, "1111");
                break;
            default:
                cout<<"Invalid hexadecimal input.";
        }
    }
    return bin;
}

//*Adding 2 binary nos.*****************************************************
int addBinary(int a, int b){
    int ans = 0;
    int prevCarry = 0;

    while (a > 0 && b > 0)
    {
        if (a % 2 == 0 && b % 2 == 0)
        {
            ans = ans *10 + prevCarry;
            prevCarry = 0;
        }
        else if ((a % 2 == 1 && b % 2 == 0) || (a % 2 == 0 && b % 2 == 1))
        {
            if (prevCarry == 1)
            {
                ans = ans*10 + 0;
                prevCarry = 1;
            }
            else
            {
                ans = ans*10 + 1;
                prevCarry = 0;    
            }   
        }
        else
        {
            ans = ans *10 + prevCarry;
            prevCarry = 1;    
        }
        a = a/10;
        b = b/10;
    }
    while (a > 0)
    {
        if (prevCarry == 1)
        {
            if (a % 2 == 1)
            {
                ans = ans*10 + 0;
                prevCarry = 1;   
            }

            else
            {
                ans = ans*10 + 1;
                prevCarry = 0;
            
            }    
        }
        else
        {
            ans = ans*10 + (a%2);
        }
        a=a/10;
        
    }

    while (b > 0)
    {
        if (prevCarry == 1)
        {
            if (b%2 == 1)
            {
                ans = ans*10 + 0;
                prevCarry = 1;   
            }

            else
            {
                ans = ans*10 + 1;
                prevCarry = 0;
            
            }    
        }
        else
        {
            ans = ans*10 + (b%2);
        }
        b = b/10;    
    }

    if (prevCarry == 1)
    {
        ans = ans*10 + 1; 
    }
    ans = reverse(ans);
    return ans;
}




int main()
{
    //    int a,b;
    //    cin >> a >> b;
    //    int n;
    //    cin >> n;
    //    string s;
    //    cin >> s;
    //    int a1,b1,c1;
    //    cin >> a1 >> b1 >> c1;
    //    cout << sumn(n);
    /* if (pythagorian(a1,b1,c1))
    {
         cout << "the nos. are pythagorian triplet" << endl;
    }
    else
    {
         cout << "the nos. are not pythagorian triplet" << endl;
    } */

    //*   cout << binaryToDecimal(n) << endl;
    //*   cout << octalToDecimal(n) << endl;
    //*   cout << hexadecimalToDecimal(s) << endl;
    //*   cout << DecimalTobinary(n) << endl;
    //*   cout << DecimalTooctal(n) << endl;
    //*   cout << DecimalTohexadecimal(n) << endl;
    //*   cout << binaryToOctal(n) << endl;
    //*   cout << binaryToHexadecimal(n) << endl;
    //*   cout << octalToBinary(n) << endl;
    //*   cout << hexadecimalToBinary(s) << endl;
    //*   cout << addBinary(a,b) << endl;
    return 0;
}