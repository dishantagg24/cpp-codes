//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
using namespace std;

//*check if a number is power of 2 with the help of bit operator
bool ispower(int n){
	return (n && !(n & n-1));
}

//*count the no. of ones in binary repres. of a no. with the help of bit operator
int numberofones(int n){
    int i =0;
	while (n > 0)
	{
		n = (n&n-1);
		i++;
	}
	return i;
}

//*generate all possible subsets of a set with the help of bit operator or bit manipulation
void subsets(int arr[], int n){
    for (int i = 0; i < (1<<n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ( i & (1<<j))
			{
				cout<<arr[j]<<" ";
			}
			
		}
		cout<<endl;
	}
}

int main(){
	cout<<ispower(16)<<endl;
    cout<<numberofones(19)<<endl;
    
    int arr[4] = {1,2,3,4};
    subsets(arr,4);
	return 0;
}