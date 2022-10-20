//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Cycle Detection in Undirected Graph using DSU(Disjoint Set Union)
const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> Rank(N);

int find_set(int x)
{
    if (x != parent[x])
    {
        parent[x] = find_set(parent[x]);
    }
    return parent[x];
    return -1;
}

void union_set(int a, int b)
{
    int x = find_set(a);
    int y = find_set(b);
    if (x == y)
    {
        return;
    }
    if (Rank[x] < Rank[y])
    {
        parent[x] = y;
    }
    else if (Rank[x] > Rank[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[y] = x;
        Rank[x]++;
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
        Rank[i] = 0;
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    bool cycle = false;
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int x = find_set(u);
        int y = find_set(v);
        if (x == y)
        {
            cycle = true;
            break;
        }
        else
        {
            union_set(u, v);
        }
    }

    if (cycle)
    {
        cout << "yes there is a cycle";
    }
    else
    {
        cout << "No there is not any cycle";
    }

    //*Minimum Cost Spanning Tree(Kruskal's Algorithm)
    vector<vector<int>> edges1;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges1.push_back({w, u, v});
    }
    sort(edges1.begin(), edges1.end());
    int cost = 0;
    for (auto it : edges1)
    {
        int w = it[0];
        int u = it[1];
        int v = it[2];
        int x = find_set(u);
        int y = find_set(v);
        if (x == y)
        {
            continue;
        }
        else
        {
            cost += w;
            union_set(u, v);
        }
    }
    cout << cost << " ";

    return 0;
}