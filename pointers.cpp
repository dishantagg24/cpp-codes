#include<iostream>
using namespace std;

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void increment(int* d){
    (*d)++;
}
int main(){
//* Pointers*************************************************************************    
 /* int a = 20;
    int* ptr;
    ptr = &a;
    int** q;                 //pointer to pointer
    q = &ptr;
    cout<<ptr<<endl;         //address of a
    cout<<*ptr<<endl;        //value of a
    cout<<a<<endl;           //value of a
    cout<<&a<<endl;          //address of a
    cout<<&ptr<<endl;        //address of ptr
    cout<<**q<<endl;         //value of a
    **q = 12;                //modifying the value of a without the help of a
    cout<<**q<<endl;         //modified value of a
    cout<<*q<<endl;          //value of ptr i.e. address of a
    cout<<q<<endl;           //address of ptr                                         */

//* Pointer Arithmetic****************************************************************
    /* int a = 20;
    int* ptr = &a;
    cout<<ptr<<endl;
    ptr++;
    cout<<ptr<<endl;    //gap of 4 bytes bcoz of int datatype

    char b = 'd';
    char* aptr = &b;
    cout<<aptr<<endl;
    aptr++;
    cout<<aptr<<endl;    //gap of 1 byte bcoz of char datatype */
     
//* Pointers and Arrays****************************************************************
    /* int arr[]={10,20,30};
    cout<<*arr<<endl;

    int* ptr = arr;
    for (int i = 0; i < 3; i++)         //Printing elements of array with the help of pointer
    {
    //?    cout<<*ptr<<endl;
    //?    ptr++;
        cout<<*(arr+i)<<endl;           //Printing elements of array without ptr 
    } */
//* Calling by reference****************************************************************
    int a=2, b=4;
    swap(&a,&b);
    cout<<a<<" "<<b<<endl;

    int c = 2;
    increment(&c);
    cout<<c<<endl;    
    return 0;
}