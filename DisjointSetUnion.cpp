//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int find(int x, int P[])
{
    if (P[x] == x)
    {
        return x;
    }
    return find(P[x], P);
}
//*Path Compression for better time complexity
int find2(int x, int P[])
{
    if (P[x] != x)
    {
        P[x] = find2(P[x], P);
    }
    return P[x];
}

void Union(int a, int b, int P[])
{
    int x = find(a, P);
    int y = find(b, P);
    if (x == y)
    {
        return;
    }
    P[x] = y;
}

//*Union by Rank for better time complexity O(alpha(n)), aplha(n):- inverse Ackermann function
void Union2(int a, int b, int P[], int rank[])
{
    int x = find(a, P);
    int y = find(b, P);
    if (x == y)
    {
        return;
    }
    if (rank[x] < rank[y])
    {
        P[x] = y;
    }
    else if (rank[x] > rank[y])
    {
        P[y] = x;
    }
    else
    {
        P[y] = x;
        rank[x]++;
    }
}

int main()
{
    int n;
    cin >> n;
    int P[n];
    int rank[n];
    for (int i = 0; i < n; i++)
    {
        P[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        rank[i] = 0;
    }

    return 0;
}