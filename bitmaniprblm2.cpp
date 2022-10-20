//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
using namespace std;

//* Find a number that is present only once where others nos. are present twice in an array***************
int unique(int arr[],int n){
	int xorsum=0;
	for (int i = 0; i < n; i++)
	{
		xorsum = xorsum^arr[i];
	}
	return xorsum;
}

//* Find two nos. that is present only once where other nos. are present twice in an array*****************
int setBit(int n,int pos){
	return (n & (1<<pos))!=0;
}

void twounique(int arr[],int n){
	int xorsum = 0;
	for (int i = 0; i < n; i++)
	{
		xorsum = xorsum ^ arr[i];
	}
	int tempxor = xorsum;

	int setbit = 0;
	int pos=0;
	while (setbit!=1)
	{
		setbit = xorsum&1;
		pos++;
		xorsum = xorsum>>1;
	}

	int newxorsum = 0;
	for (int i = 0; i < n; i++)
	{
		if (setBit(arr[i],pos-1))
		{
			newxorsum = newxorsum^arr[i];
		}
	}

	cout<<newxorsum<<endl;
	cout<<(newxorsum^tempxor)<<endl;
}

//* Find a no. that is present only once where other nos. are present three times in an array**************
int getBit(int n,int pos){
	return (n & (1<<pos))!=0;
}
int setBit(int n,int pos){
	return (n | (1<<pos));
}

int uniquein3(int arr[],int n){
	int result =0;
	for (int i = 0; i < 64; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (getBit(arr[j],i))
			{
				sum++;
			}	
		}
		if ((sum%3)!=0)
		{
			result = setBit(result,i);
		}
	}
	return result;
}

int main(){
    // int arr[] = {2,1,3,4,3,1,2};
	// cout<<unique(arr,8)<<endl;
    // int arr[]={1,2,3,1,2,3,5,7};
	// twounique(arr,8);
    int arr[]={1,2,3,4,1,2,3,1,2,3};
	cout<<uniquein3(arr,10)<<endl;

    return 0;
}