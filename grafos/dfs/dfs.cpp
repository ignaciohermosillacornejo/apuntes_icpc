#include "../../declaraciones/declaraciones.h"

//Recursive (create visited filled with 1s)
void dfs_r(graph &g, vi &visited, int u)
{
    cout << u << '\n';
    visited[u] = 0;

    for (int v : g[u])
        if (visited[v])
            dfs_r(g, visited, v);
}

//Iterative
void dfs_i(graph &g, int start)
{
    int n = g.size();
    vi visited(n, 1);
    stack<int> s;

    s.emplace(start);
    visited[start] = 0;

    while (not s.empty())
    {
        int u = s.top();
        s.pop();

        cout << u << '\n';

        for (int v : g[u])
            if (visited[v])
            {
                s.emplace(v);
                visited[v] = 0;
            }
    }
}

