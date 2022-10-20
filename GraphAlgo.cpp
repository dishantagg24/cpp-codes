//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 2;
const int INF = 1e9;
vector<vector<int>> g[N];
vector<int> dist(N);
vector<bool> vis(N, false);
int cost = 0;
int n, m;

//*Prims Algorithm (kind of greedy algo used for finding minimum spanning tree in a weighted undirected graph)
// If implemented with adjacency list, its time complexity is O(VlogV + ElogV)
//*Spanning Tree:- Connected, undirected graph which contains no cycle i.e. if there are total V vertices then no of edges would be V-1.
void primsMST(int source)
{
    for (int i = 1; i < N; i++)
    {
        dist[i] = INF;
    }
    dist[source] = 0;
    set<vector<int>> s;
    s.insert({0, source}); //{wt,vertex}
    while (!s.empty())
    {
        auto x = *s.begin();
        s.erase(x);
        int u = x[1]; // vertex
        int w = x[0]; // weight
        vis[u] = true;
        cout << w << " ";
        cost += w;
        for (auto it : g[u])
        {
            if (vis[it[0]])
            {
                continue;
            }
            if (dist[it[0]] > it[1])
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
            }
        }
    }
}

//*Applications
// Used to construct trees for broadcasting in computer networks.
// Used in graph-based cluster analysis.
// Used in image segmentation.
// Used in regionalisation of socio-geographic areas, where regions are grouped into contiguous regions.

//*Dijkstra's Algorithm (Only work for positive weight edges)
// Time Complexity:- O(V^2), However, if implanted with min-priority queue or somthing like set, the time complexity can come down to O (V + E logV)
// Fun Fact:- In pronounciation 'j' is silent,Pronounced as dike-struh
void dijkstra(int source)
{
    for (int i = 1; i < N; i++)
    {
        dist[i] = INF;
    }
    dist[source] = 0;
    set<vector<int>> s;
    s.insert({0, source}); //{wt,vertex}
    while (!s.empty())
    {
        auto x = *s.begin();
        s.erase(x);
        for (auto it : g[x[1]])
        {
            if (dist[it[0]] > (it[1] + dist[x[1]]))
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1] + dist[x[1]];
                s.insert({dist[it[0]], it[0]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] < INF)
        {
            cout << dist[i] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
}

//*Applications
// Used to find directions to travel from one location to another in mapping software like Google maps or Apple maps.
// Used in networking to solve the min - delay path problem.
// Used in abstract machines to determine the choices to reach a certain goal state via transitioning among different states(e.g., can be used to determine the minimum possible number of moves to win a game).

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    primsMST(0);
    cout << cost << endl;
    // dijkstra(1);
    return 0;
}