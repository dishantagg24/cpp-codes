//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

//*Q1.Select one character (smallest one in K characters) among the first K characters of string S, remove it from string S and append it to string X.Do this till the string S exist.Find the string X.

// int main(){
//     string s1;
//     cin>>s1;
//     int k;
//     cin>>k;
//     string s2="";
//     int l;
//     while (s1.length()>0)
//     {
//         char minch='z';
//         if (s1.length()<k)
//         {
//             k = s1.length();
//         }
//         for (int i = 0; i < k; i++)
//         {
//             minch = min(minch,s1[i]);
//             if (minch == s1[i])
//             {
//                 l=i;
//             }        
//         }
//         s2.append(s1,l,1);
//         s1.erase(l,1);
//     }
//     cout<<s2;
//     return 0;
// }

//*Q2.Given two binary strings A and B of equal length.You have a type of opertion in which you can swap any two elements of string B. Your task is to find the minimum number of operations required to convert string B into string A. If it is not possible, print -1.
// int main(){
//     string s;
//     cin>>s;
 
//     string s2;
//     cin>>s2;
//     int count=0;
//     int count_zero1=0;
//     int count_one1=0;
//     int count_zero2=0;
//     int count_one2=0;
    
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == '1')
//         {
//             count_one1++;
//         }else if (s[i] == '0')
//         {
//             count_zero1++;
//         }else{
//             cout<<"invalid input";
//         }
//     }
//     for (int i = 0; i < s2.length(); i++)
//     {
//         if (s2[i] == '1')
//         {
//             count_one2++;
//         }else if (s2[i] == '0')
//         {
//             count_zero2++;
//         }else{
//             cout<<"invalid input";
//         }
//     }
    
//     if ((count_zero1 != count_zero2) || (count_one1 != count_one2))
//     {
//         cout<<"-1";
//         return 0;
//     }
        
//     while (s!=s2)
//     {
//         for (int i = 0; i < s.length()-1; i++)
//         {
//             if (s[i] != s2[i] && s[i+1] != s2[i+1])
//             {
//                 swap(s2[i],s2[i+1]);
//                 count++;
//             }
//         }
//     }
//     cout<<count;
    
//     return 0;
// }

//*Q3.If any string contains all the vowels in alphabetical order then print Good. If it contains the vowels in reverse alphabetical order , then print Worst. All the other strings that do not fall in any of the categories then print Bad.The string is a word of lower case English alphabets only. If there are no vowels in the string, then print Good.
int main()
{
    int t;
    cin>>t;

    while(t>0)
    {
        string s;
        cin>>s;

        string a="";

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                a+=s[i];
            }
        }

        string s1=a;

        string s2;

        sort(s1.begin(),s1.end());

        s2=s1;

        reverse(s2.begin(),s2.end());

        if(a==s1)
        {
            cout<<"Good"<<endl;
        }
        else if(a==s2)
        {
            cout<<"Worst"<<endl;
        }
        else
        {
            cout<<"Bad"<<endl;
        }
        t--;
    }

    return 0;
}