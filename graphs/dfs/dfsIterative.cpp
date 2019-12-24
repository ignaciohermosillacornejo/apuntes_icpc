#include "../../headers/headers.h"
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

        for (int v : g[u])
        {
            if (visited[v])
            {
                s.emplace(v);
                visited[v] = 0;
            }
        }
    }
}
