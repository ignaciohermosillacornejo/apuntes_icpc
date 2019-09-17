#include "../../headers/headers.h"

struct RSQ // Range sum query
{
    static ll const neutro = 0;
    static ll op(ll x, ll y)
    {
        return x + y;
    }
    static ll
    lazy_op(int i, int j, ll x)
    {
        return (j - i + 1) * x;
    }
};

struct RMinQ // Range minimun query
{
    static ll const neutro = 1e18;
    static ll op(ll x, ll y)
    {
        return min(x, y);
    }
    static ll
    lazy_op(int i, int j, ll x)
    {
        return x;
    }
};

template <class t>
class SegTreeLazy
{
    vector<ll> arr, st, lazy;
    int n;

    void build(int u, int i, int j)
    {
        if (i == j)
        {
            st[u] = arr[i];
            return;
        }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m);
        build(r, m + 1, j);
        st[u] = t::op(st[l], st[r]);
    }

    void propagate(int u, int i, int j, ll x)
    {
        // nota, las operaciones pueden ser un and, or, ..., etc.
        st[u] += t::lazy_op(i, j, x); // incrementar el valor (+)
        // st[u] = t::lazy_op(i, j, x); // setear el valor
        if (i != j)
        {
            // incrementar el valor
            lazy[u * 2 + 1] += x;
            lazy[u * 2 + 2] += x;
            // setear el valor
            //lazy[u * 2 + 1] = x;
            //lazy[u * 2 + 2] = x;
        }
        lazy[u] = 0;
    }

    ll query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i)
            return t::neutro;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u])
            propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b)
            return st[u];
        ll x = query(a, b, l, i, m);
        ll y = query(a, b, r, m + 1, j);
        return t::op(x, y);
    }

    void update(int a, int b, ll value,
                int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u])
            propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b)
            propagate(u, i, j, value);
        else if (j < a or b < i)
            return;
        else
        {
            update(a, b, value, l, i, m);
            update(a, b, value, r, m + 1, j);
            st[u] = t::op(st[l], st[r]);
        }
    }

  public:
    SegTreeLazy(vector<ll> &v)
    {
        arr = v;
        n = v.size();
        st.resize(n * 4 + 5);
        lazy.assign(n * 4 + 5, 0);
        build(0, 0, n - 1);
    }

    ll query(int a, int b)
    {
        return query(a, b, 0, 0, n - 1);
    }

    void update(int a, int b, ll value)
    {
        update(a, b, value, 0, 0, n - 1);
    }
};
