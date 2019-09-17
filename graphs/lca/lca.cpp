#include "../../headers/headers.h"
class LcaTree
{
    int n;
    vi parent;
    vi level;
    vi root;
    graph P;

public:
    LcaTree(int n)
    {
        this->n = n;
        parent.assign(n, -1);
        level.assign(n, -1);
        P.assign(n, vi(lg(n) + 1, -1));
        root.assign(n, -1);
    }
    void addLeaf(int index, int par)
    {
        parent[index] = par;
        level[index] = level[par] + 1;
        P[index][0] = par;
        root[index] = root[par];
        for (int j = 1; (1 << j) < n; ++j)
        {
            if (P[index][j - 1] != -1)
                P[index][j] = P[P[index][j - 1]][j - 1];
        }
    }
    void addRoot(int index)
    {
        parent[index] = index;
        level[index] = 0;
        root[index] = index;
    }
    int lca(int u, int v)
    {
        if (root[u] != root[v] || root[u] == -1)
            return -1;
        if (level[u] < level[v])
            swap(u, v);
        int dist = level[u] - level[v];
        while (dist != 0)
        {
            int raise = lg(dist);
            u = P[u][raise];
            dist -= (1 << raise);
        }
        if (u == v)
            return u;
        for (int j = lg(n); j >= 0; --j)
        {
            if (P[u][j] != -1 && P[u][j] != P[v][j])
            {
                u = P[u][j];
                v = P[v][j];
            }
        }
        return parent[u];
    }
};