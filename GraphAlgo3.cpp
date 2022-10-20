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

//* Root vertex:- A vertex from which all other vertices in the graph can be reached
// Each vertex in a strongly connected component is a root vertex.
// A directed graph is said to be strongly connected if every vertex is reachable from every other vertex.

//*Applications of strongly connected components
// Used to compute the Dulmage–Mendelsohn decomposition,which is a classification of the edges of a bipartite graph.
// Used in social networks to find a group of people who are strongly connected and make recommendations based on common interests.

//*Kosaraju's Algorithm for Strongly Connected Components (used for directed graph)
// Time Complexity:- O(V+E)
// Space Complexity:- O(V+E)+O(V)+O(V)
// Steps:-
// 1.Sort all nodes in order of their finishing time i.e. topological sort
// 2.Transpose the graph i.e. reverse all the edges
// 3.Do dfs according to finishing time

void dfs(int Node, stack<int> &st, vector<bool> &isVisited, vector<vector<int>> &edges)
{
    isVisited[Node] = true;
    for (auto it : edges[Node])
    {
        if (!isVisited[it])
        {
            dfs(it, st, isVisited, edges);
        }
    }
    st.push(Node);
}

void revDfs(int Node, vector<bool> &isVisited, vector<int> transpose[])
{
    cout << Node << " ";
    isVisited[Node] = true;
    for (auto it : transpose[Node])
    {
        if (!isVisited[it])
        {
            revDfs(it, isVisited, transpose);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        stack<int> st;
        vector<bool> isVisited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!isVisited[i])
            {
                dfs(i, st, isVisited, edges);
            }
        }
        vector<int> transpose[n];
        for (int i = 0; i < n; i++)
        {
            isVisited[i] = false;
            for (auto it : edges[i])
            {
                transpose[it].push_back(i);
            }
        }
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!isVisited[node])
            {
                revDfs(node, isVisited, transpose);
                cout << endl;
            }
        }
    }
    return 0;
}