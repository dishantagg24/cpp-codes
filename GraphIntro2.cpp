//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*The max. no. of edges in undirected graph if V vertex is given:- (V*(V-1))/2
//*The max. no. of edges in directed graph if V vertex is given:- (V*(V-1))

//*If we know the solution lies somewhere deep in a tree or far from the source vertex in the graph, use DFS.If we know the solution is not that far from the source vertex, use BFS.

//*If our tree is broad,use DFS as BFS will take too much memory.Similarly, if our tree is very deep, choose BFS over DFS.

const int N = 1e5 + 2;
vector<int> adj[N];

//*Topological Sort(only possible in DAG[Directed Acyclic Graph])
// Topological sorting of a graph is a linear ordering of its vertices so that for each directed edge (u, v) in the ordering, vertex u comes before v.
// first print those vertices who have lesser indegree and then the more indegree ones.

//*Applications
// Used in instruction scheduling.
// Used in data serialisation.
// Used to determine the order of compilation tasks to perform in makefiles.
// Used to resolve symbol dependencies in linkers.

void dfs(int Node, vector<bool> &isVisited, vector<int> adj[], stack<int> &st)
{
    isVisited[Node] = true;
    for (auto it : adj[Node])
    {
        if (!isVisited[it])
        {
            isVisited[it] = true;
            dfs(it, isVisited, adj, st);
        }
    }
    st.push(Node);
}

int main()
{
    int n, m;
    cin >> n >> m;
    int indegree[n];
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    //*using bfs (Kahn's Algorithm)
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int Node = q.front();
        q.pop();
        cout << Node << " ";
        for (auto it : adj[Node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    //*using dfs
    stack<int> st;
    vector<bool> isVisited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!isVisited[i])
        {
            dfs(i, isVisited, adj, st);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

//*To determine whether there is a cycle present in undirected graph or not
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// bool Cycle(int src, vector<bool> &visited, vector<vector<int>> &adj, int parent)
// {
//     visited[src] = 1;
//     for (auto it : adj[src])
//     {
//         if (it != parent)
//         {
//             if (visited[it] == 1)
//             {
//                 return true;
//             }
//             if (!visited[it] && Cycle(it, visited, adj, src))
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n);
//     for (int i = 0; i < m; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
//     vector<bool> visited(n, 0);
//     bool cycle = false;
//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i] && Cycle(i, visited, adj, -1))
//         {
//             cycle = true;
//         }
//     }
//     if (cycle)
//     {
//         cout << "There is a cycle in graph"
//              << "\n";
//     }
//     else
//     {
//         cout << "There is no cycle in graph"
//              << "\n";
//     }

//     return 0;
// }

//*To determine whether there is a cycle present in directed graph or not
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// bool Cycle(int src, vector<bool> &visited, vector<vector<int>> &adj, vector<int> stack)
// {
//     stack[src] = 1;
//     if (!visited[src])
//     {
//         visited[src] = 1;
//         for (auto it : adj[src])
//         {
//             if (stack[it] == 1)
//             {
//                 return true;
//             }
//             if (!visited[it] && Cycle(it, visited, adj, stack))
//             {
//                 return true;
//             }
//         }
//     }
//     stack[src] = 0;
//     return false;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n);
//     for (int i = 0; i < m; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
//     vector<bool> visited(n, 0);
//     vector<int> stack(n, 0);
//     bool cycle = false;
//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i] && Cycle(i, visited, adj, stack))
//         {
//             cycle = true;
//         }
//     }
//     if (cycle)
//     {
//         cout << "There is a cycle in graph"
//              << "\n";
//     }
//     else
//     {
//         cout << "There is no cycle in graph"
//              << "\n";
//     }

//     return 0;
// }

//*Applications
// Used in distributed message - based algorithms.
// Used to process large - scale graphs using a distributed processing system on a cluster.
// Used to detect deadlocks in concurrent systems.
// Used in cryptographic applications to determine keys of a message that can map that message to the same encrypted value.