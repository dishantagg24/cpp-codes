//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Find the no. of connected components in a graph and its size
int get_comp(int idx, vector<int> &isVisited, vector<vector<int>> &adj)
{

    if (isVisited[idx])
    {
        return 0;
    }
    isVisited[idx] = 1;
    int ans = 1;
    for (auto it : adj[idx])
    {
        if (!isVisited[it])
        {
            ans += get_comp(it, isVisited, adj);
            isVisited[it] = 1;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> isVisited(n, 0);
    vector<int> components;
    for (int i = 0; i < n; i++)
    {
        if (!isVisited[i])
        {
            components.push_back(get_comp(i, isVisited, adj));
        }
    }
    for (auto it : components)
    {
        cout << it << " ";
    }
    return 0;
}

//*Bipartite Graph
// Its vertices can be divided into two disjoint and independent sets U and V such that every edge connects a vertex in U to one in V.
// The graph does not contain any odd length cycles
// The graph is 2 colorable
// eg:-
//*The below graph is not bipartite graph
// 3 3 (no. of edges & no. of vertices)
// 0 1
// 1 2
// 2 0
//*The below graph is bipartite graph
// 4 4 (no. of edges & no. of vertices)
// 0 1
// 1 2
// 2 3
// 3 0

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// void dfs(int Node, vector<bool> &isVisited, vector<vector<int>> &adj, vector<int> &color, int x, bool &bypartite)
// {
//     if (color[Node] != -1 && color[Node] != x)
//     {
//         bypartite = false;
//         return;
//     }
//     color[Node] = x;
//     if (isVisited[Node])
//     {
//         return;
//     }
//     isVisited[Node] = true;
//     for (auto it : adj[Node])
//     {
//         dfs(it, isVisited, adj, color, x ^ 1, bypartite);
//     }
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n);
//     for (int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
//     vector<int> color(n, -1);
//     vector<bool> isVisited(n, false);
//     bool bypartite = true;
//     for (int i = 0; i < n; i++)
//     {
//         if (!isVisited[i])
//         {
//             dfs(i, isVisited, adj, color, 0, bypartite);
//         }
//     }
//     if (bypartite)
//     {
//         cout << "Yes";
//     }
//     else
//     {
//         cout << "No";
//     }
//     return 0;
// }