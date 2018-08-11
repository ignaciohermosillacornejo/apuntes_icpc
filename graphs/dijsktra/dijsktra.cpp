#include "../../headers/headers/headers.h"
//g has vectors of pairs of the form (w, index)
int dijsktra(wgraph g, int start, int end)
{
    int n = g.size();
    vi cost(n, 1e9); //~INT_MAX/2
    priority_queue<ii, greater<ii>> q;

    q.emplace(0, start);
    cost[start] = 0;
    while (not q.empty())
    {
        int u = q.top().second, w = q.top().first;
        q.pop();

        for (auto v : g[u])
        {
            if (cost[v.second] > v.first + w)
            {
                cost[v.second] = v.first + w;
                q.emplace(cost[v.second], v.second);
            }
        }
    }

    return cost[end];
}