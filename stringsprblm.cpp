//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string s;
	cin>>s;

//* Convert into upper case
/* 	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]>='a' && s[i]<='z')
		{
		s[i] = s[i] - 32;
		}
	}
	cout<<s; */
    
//* Convert into lower case
/*     for (int i = 0; i < s.size(); i++)
    {
        if (s[i]>='A' && s[i]<='Z')
        {
		s[i] = s[i] + 32;
        }
    }
	cout<<s;
 */
//* Transform with the help built in func.
/* 	transform(s.begin(), s.end(), s.begin(), ::toupper);	//(insert full string, start with begin, change in upper case)
	cout<<s<<endl;
	transform(s.begin(), s.end(), s.begin(), ::tolower);	//(insert full string, start with begin, change in lower case)
	cout<<s<<endl;
 */
//* Form the biggest number from the numeric string
//* Unofficial method

/* 	string s1;
	cin>>s1;
	
	sort(s1.begin(), s1.end());
	reverse(s1.begin(), s1.end());
	cout<<s1<<endl;
 */
//* Official method
/* 	string s1;
	cin>>s1;
	
	sort(s1.begin(), s1.end(), greater<int>());
	cout<<s1<<endl;
 */

//* Maximum frequency of a letter in a string 
	string s;
	cin>>s;
	int count[26];
	for (int i = 0; i < 26; i++)
	{
		count[i] = 0;
	}
	
	for (int i = 0; i < s.length(); i++)
	{
		count[s[i]-'a']++;
	}
	char ans = 'a';
	int maxf=0;
	for (int i = 0; i < 26; i++)
	{
		if (count[i]>maxf)
		{
			maxf = count[i];
			ans = i + 'a';
		}
	}
	cout<<maxf<<" "<<ans;

	return 0;
}