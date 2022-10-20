//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//*Min Steps to One*************************
int countMinStepsToOne(int n)
{
    int count = 0;
    if (n == 1)
    {
        return count;
    }
    if ((n - 1) % 3 == 0)
    {
        n -= 1;
    }
    else if (n % 2 == 0)
    {
        n /= 2;
    }
    else if (n % 3 == 0)
    {
        n /= 3;
    }
    else
    {
        n -= 1;
    }
    count++;
    return count + countMinStepsToOne(n);
}

//*All Permutations of a String
void permutationString(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);
        permutationString(ros, ans + ch);
    }
    return;
}

// Time Complexity:- O(n! * n)
// Space Complexity:- O(n)
//*All Permutations of a array
void permutationArr(int idx, int arr[], int n)
{
    if (idx == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = idx; i < n; i++)
    {
        swap(arr[idx], arr[i]);
        permutationArr(idx + 1, arr, n);
        swap(arr[idx], arr[i]);
    }
}

//*All Substrings of a String
void Substrings(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    string ros = s.substr(1);
    Substrings(ros, ans);
    Substrings(ros, ans + s[0]);
    return;
}
int main()
{
    // cout << countMinStepsToOne(7);
    // permutationString("ABC", "");
    // Substrings("ABC", "");
    int arr[] = {1, 2, 3};
    permutationArr(0, arr, 3);
    return 0;
}