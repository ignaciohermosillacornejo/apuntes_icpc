#include "../../headers/headers.h"
struct edge
{
    int u, v;
    ll w;
    edge(int u, int v, ll w) : u(u), v(v), w(w) {}

    bool operator<(const edge &o) const
    {
        return w < o.w;
    }
};

class Kruskal
{
  private:
    ll sum;
    vi p, rank;

  public:
  //Amount of Nodes n, and unordered vector of Edges E
    Kruskal(int n, vector<edge> E)
    {
        sum = 0;
        p.resize(n);
        rank.assign(n, 0);
        rep(i, n) p[i] = i;
        sort(E.begin(), E.end());
        for (auto &e : E)
            UnionSet(e.u, e.v, e.w);
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void UnionSet(int i, int j, ll w)
    {
        if (not isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
                p[y] = x;
            else
                p[x] = y;

            if (rank[x] == rank[y])
                rank[y]++;

            sum += w;
        }
    }
    ll mst_val()
    {
        return sum;
    }
};