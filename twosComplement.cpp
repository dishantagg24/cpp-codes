//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<string>
using namespace std;

/* Function for ones complement of the binary number */
string onesComplement(string binary){
    for (int i = 0; i < binary.length(); i++)
    {
        if (binary[i] == '0')
        {
            binary[i] = '1';
        }
        else if(binary[i] == '1') 
        {
            binary[i] = '0';
        }
        else{
            cout<<"invalid binary no.";
            return "";
        }
    }
    return binary;
}
int main(){
    string binary;
    cout<<"enter binary no"<<" ";
    /* Input 8-bit binary string */
    cin>>binary;

    string ones = onesComplement(binary);
    int size = ones.length();

    if (size == 0)
    {
        return -1;
    }
    cout<<"Original binary = "<<binary<<endl;
    cout<<"Ones complement = "<<ones<<endl;

    /*
     * Add 1 to the ones complement
     */

    char twos[size+1];
    int carry = 1;

    for (int i = size-1; i >= 0; i--)
    {
        if (ones[i] == '0' && carry == 1)
        {
            twos[i] = '1';
            carry = 0;
        }
        else if (ones[i] == '1' && carry == 1)
        {
            twos[i] = '0';
            carry = 1;
        }
        else
        {
            twos[i] = ones[i];
        }        
    }

    twos[size] = '\0';
    cout<<"Twos complement = "<<twos<<endl;

    return 0;
}