#include "../../headers/headers.h"
bool bellman_ford(wgraph &g, int start)
{
    int n = g.size();
    vector<int> dist(n, 1e9); //~INT_MAX/2
    dist[start] = 0;
    rep(i, n - 1) rep(u, n) for (ii p : g[u])
    {
        int v = p.first, w = p.second;
        dist[v] = min(dist[v], dist[u] + w);
    }

    bool hayCicloNegativo = false;
    rep(u, n) for (ii p : g[u])
    {
        int v = p.first, w = p.second;
        if (dist[v] > dist[u] + w)
            hayCicloNegativo = true;
    }

    return hayCicloNegativo;
}
