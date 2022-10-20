//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Every tree is a graph, but not every graph is a tree.In tree there is a root node but in graph there is nothing like that.
//*A tree can be thought of as a connected acyclic graph with N nodes and N - 1 edges.Any two vertices are connected by exactly one path.

//*Types of graphs:-
// 1.Directed Graph:- This graph contains all the directed edges.If a to b edge is given directed then we can not travel from b to a.
// 2.Undirected Graph:- This graph does not contains directed edges.We can move either from a to b or from b to a.
// 3.Dense Graph:- Every Node is connected with other nodes.
// 4.Sparse Graph:- Node is only connected to limited nodes not connected to all nodes.
// Eg:- A city can be connected to 3-4 cities but not connected to all the 29 states in India.(excluding air transportation)
// 5.Cyclic Graph:- The graph which contains cycle.
// 6.Acyclic Graph:- The graph which does not contains cycle.
// 7.Unweighted Graph:- All the edges are unweighted or of the same weight. By default every graph is unweighted.
// 8.Weighted Graph:- Different edges have different weight.

//*Graph is represented by two methods
// 1. Adjacency Matrix
// 2. Adjacency List

//*Adjacency Matrix:- It is a 2D array where a[i][j] = 1 if there is an edge from i to j else a[i][j] = 0.It is symmetrical about diagonals.O(V^2), V :- no. of vertices
//*Adjacency List:- It is an array of list where each a[i] is a list of nodes Xi that are reachable from i.O(V+E), V :- no. of vertices,E :- no of edges

const int N = 1e5 + 2;
bool vis[N];
vector<int> adj[N]; // declares an array consisting of N vectors

void dfs(int Node)
{
    vis[Node] = 1;
    cout << Node << " ";

    for (auto it : adj[Node])
    {
        if (!vis[it])
        {
            dfs(it);
        }
    }
}
void dfs1(int Node)
{
    vis[Node] = 1;

    for (auto it : adj[Node])
    {
        if (!vis[it])
        {
            dfs(it);
        }
    }
    cout << Node << " ";
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
    }

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjm(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }
    cout << "Adjacency matrix of the above graph is given by: "
         << "\n";
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }

    if (adjm[3][7] == 1)
    {
        cout << "there is an edge between 3 and 7" << endl;
    }
    else
    {
        cout << "no edge";
    }

    //* for undirected graph
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //* for directed graph
    // for (int i = 0; i < m; i++)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     adj[x].push_back(y);
    // }

    cout << "adjacency list of the above graph is given by: ";

    for (int i = 1; i < n + 1; i++)
    {
        cout << i << "->";
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    //*BFS Representation of Graph
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << endl;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    //*Applications
    // Used to determine the shortest paths and minimum spanning trees.
    // Used by search engine crawlers to build indexes of web pages.
    // Used to search on social networks.
    // Used to find available neighbour nodes in peer - to - peer networks such as BitTorrent.

    //*DFS Representation of Graph
    // preorder
    dfs(1);
    // postorder
    dfs1(1);

    //*Applications
    // Used to find a path between two vertices.
    // Used to detect cycles in a graph.
    // Used in topological sorting.
    // Used to solve puzzles having only one solution(e.g., mazes)
    return 0;
}