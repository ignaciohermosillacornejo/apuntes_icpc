#include "../../headers/headers/headers.h"
//Recursive (create visited filled with 1s)
void dfs_r(graph &g, vi &visited, int u)
{
    cout << u << '\n';
    visited[u] = 0;

    for (int v : g[u])
        if (visited[v])
            dfs_r(g, visited, v);
}


