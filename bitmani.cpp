//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
using namespace std;

//*Bitwise operator first convert number to binary form then perform operation and then again convert binary to number(not sure but i thought so)  
//*Basic questions of bit manipulation

int getBit(int n,int pos){                  //for getting the bit of a particular position in a number     
    return ((n & (1<<pos))!=0);
}

int setBit(int n,int pos){                  //for setting 1 at a particular position in a number 
    return (n | (1<<pos));
}

int clearBit(int n,int pos){                //for clear the bit at a particular position in a number
    int mask = ~(1<<pos);
    return (n & mask);
}

int toggleBit(int n,int pos){               //for toggle (0-->1 || 1-->0) the bit at a particular position in a number
    return (n^(1<<pos));
}

int updateBit(int n,int pos, int value){    //for change the bit at a particular position in a number
    int mask = ~(1<<pos);                 
    n = n & mask;                           //first clear the bit of that position
    return (n | (value<<pos));              //then set the bit (0 or 1) at that position
    
}

//? If we replace 1 to value in setBit function then will it work same as updateBit function?
//TODO For above query check the two functions for this input(4,2,0).  

void swap(int a,int b){                     //swap using bit manipulation
    a = a^b;
    b = b^a;
    a = a^b;
    cout<<a<<" "<<b;
}
int main(){
    int n = 0b0100;                         //*Convert binary no. directly into a decimal integer
	cout<<n<<endl;

    cout<<getBit(5,2)<<endl;
    cout<<setBit(5,1)<<endl;
    cout<<clearBit(5,2)<<endl;
    cout<<toggleBit(5,2)<<endl;
    cout<<updateBit(5,1,1)<<endl;

    int a,b;
    cin>>a>>b;
    swap(a,b);

    return 0;
}