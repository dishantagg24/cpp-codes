//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 2;
const int INF = 1e9;
vector<int> dist(N);
vector<vector<int>> edges;
int n, m;

//*Bellman Ford Algorithm(works for negative weight edges)
// Time Complexity:- O(V-1)*O(E)
// Space Complexity:- O(V)
// There is no shortest path in negative cycle(the cycle in which sum of all weights of edges is -ve)
// This algorithm is also used to check whether the given graph contains a negative cycle or not(if we do relaxation one more time after bellman ford algo and our distance array decreases then there will negative cycle present in the graph else not).
void bellmanFord(int source)
{
    for (int i = 1; i < N; i++)
    {
        dist[i] = INF;
    }
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    for (int i = 0; i < n; i++)
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

//*Floyd Warshall Algorithm (Dp based algorithm and used in Adjacency matrix)
// Time Complexity O(n^3) n->matrix.size()
// The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem.
// The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.
// Between a pair of vertices we introduce a new vertex from the given matrix and find the shortest distance
void floydMarshall(vector<vector<int>> matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = INT_MAX;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INT_MAX)
                matrix[i][j] = -1;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    bellmanFord(0);
    return 0;
}