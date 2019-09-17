#include "../../headers/headers.h"

graph Tree;
vi dist;

// Finds a diameter node
int bfs1()
{
    int n = Tree.size();
    queue<int> q;

    q.emplace(0);
    dist[0] = 0;
    int u;
    while (not q.empty())
    {
        u = q.front();
        q.pop();

        for (int v : Tree[u])
        {
            if (dist[v] == -1)
            {
                q.emplace(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    return u;
}

// Fills the distances from one diameter node and finds another diameter node
int bfs2()
{
    int n = Tree.size();
    vi visited(n, 1);
    queue<int> q;
    int start = bfs1();
    q.emplace(start);
    visited[start] = 0;
    int u;
    while (not q.empty())
    {
        u = q.front();
        q.pop();

        for (int v : Tree[u])
        {
            if (visited[v])
            {
                q.emplace(v);
                visited[v] = 0;
                dist[v] = max(dist[v], dist[u] + 1);
            }
        }
    }
    return u;
}

// Finds the diameter
int bfs3()
{
    int n = Tree.size();
    vi visited(n, 1);
    queue<int> q;
    int start = bfs2();
    q.emplace(start);
    visited[start] = 0;
    int u;
    while (not q.empty())
    {
        u = q.front();
        q.pop();

        for (int v : Tree[u])
        {
            if (visited[v])
            {
                q.emplace(v);
                visited[v] = 0;
                dist[v] = max(dist[v], dist[u] + 1);
            }
        }
    }
    return dist[u];
}
