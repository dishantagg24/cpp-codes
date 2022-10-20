//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<vector>
using namespace std;

int main(){
//* Initiliasation of vectors*********************************

   //First Method     
    vector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    //Second Method
    vector<int>::iterator it;       //"it" works as a pointer
    for ( it = v.begin(); it != v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    //Third Method
    for ( auto element:v)           //printing all elements of vector v and auto determines their data types
    {
        cout<<element<<" ";
    }
    cout<<endl;
    return 0;
}