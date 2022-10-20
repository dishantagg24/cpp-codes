//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*N meetings in one room***********************************
class meeting
{
public:
    int st, en, pos;
    meeting(int start, int end, int position)
    {
        st = start;
        en = end;
        pos = position;
    }
};

bool compare(meeting *m1, meeting *m2)
{
    if (m1->en < m2->en)
    {
        return true;
    }
    else if (m1->en > m2->en)
    {
        return false;
    }
    else if (m1->pos < m2->pos)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    meeting *meet[n];
    for (int i = 0; i < n; i++)
    {
        meet[i] = new meeting(arr[i], arr2[i], i + 1);
    }
    sort(meet, meet + n, compare);
    int count = 0;
    int end_time = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (end_time < meet[i]->st)
        {
            count++;
            end_time = meet[i]->en;
        }
    }
    cout << count << endl;
    return 0;
}