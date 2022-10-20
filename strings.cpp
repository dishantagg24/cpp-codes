//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<algorithm>                 //for sort string function
#include<string>
using namespace std;

int main(){
    //* String is a part of STL (Standard Template Library)     
    //* Simple input output of string in various ways    
    // string str;
    // cin>>str;
    // cout<<str;                  //if we enter full sentence only first word would be print
    // cout<<str[1];               //for printing particular letter

    // string str = "Dishant likes movies";
    // cout<<str;

    // string str(5,'n');          //for printing n character 5 times
    // cout<<str; 

    // string str;
    // getline(cin,str);           //for input/output a full sentence with space  
    // cout<<str;
    
    //* Appending(joining) two strings in two way
    //first method
    // string s1 = "fri";
    // string s2 = "ends";
    // cout<<s1.append(s2);

    //second mehod
    // s1 = s1 + s2;
    // cout<<s1;

    //* For clear string
    // string str = "Dishant";
    // str.clear();

    //* for comparing two strings
    // string s1 = "abc";
    // string s2 = "abc";
    /* if (!s2.compare(s1))
    {
        cout<<"strings are equal"<<endl;
    } */

    //* to check empty string
    // string s1 = "abc";
    // s1.clear();
    /* if (s1.empty())
    {
        cout<<"s1 string is empty"<<endl;
    } */

    // string s2 = "xyz";
    /* if (!s2.empty())
    {
        cout<<"s2 string is not empty"<<endl;
    } */

    //* erase function in string
    // string s1 = "nincompoop";
    // s1.erase(3,4);                  //index of element from which deletion will start,no. of elements to be deleted

    // cout<<s1<<endl;
    
    //* to find substring in string
    // string s1 = "nincompoop";

    // cout<<s1.find("comp")<<endl;    //Display the index of first element of substring
        
    //* to insert any new string in another string
    // string s1 = "nincompoop";
    // s1.insert(2,"lol");             //index where insertion will start,new string which to be insert    

    // cout<<s1<<endl;

    //* to determine length of string
    // string s1 = "nincompoop";
    // cout<<s1.size()<<endl;          //Both(including below line) give same result
    // cout<<s1.length()<<endl;

    /* for (int i = 0; i <s1.size() ; i++)
    {
        cout<<s1[i]<<endl;
    } */
    
    //* substring of string
    // string s1 = "nincompoop";

    // string s = s1.substr(6,4);       //from which index we need substring,no. of elements to be needed 
    // cout<<s<<endl;

    //* convert numeric string to integer
    // string s1 = "788";
    // int x = stoi(s1);
    // cout<<x+2<<endl;

    //* convert integer to string
    // int x = 788;

    // cout<<to_string(x)+"2"<<endl;        //2 will be append not add bcoz we are joining two strings(788 and 2)

    //* sorting of string
    string s1 = "fksdljfjhcvcbvbdfewuirrufbnbvnbmz";
    sort(s1.begin(),s1.end());              //begin()-->points to first element of string
    cout<<s1<<endl;                         //end()-->points to next to last element of string
    return 0;
}