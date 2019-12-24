#include "../../headers/headers.h"

// O(n)
umap<ll, int> factorialFactorization(int n, vi &primes)
{
    umap<ll, int> p2e;
    for (auto p : primes)
    {
        if (p > n)
            break;
        int e = 0;
        ll tmp = n;
        while ((tmp /= p) > 0)
            e += tmp;
        if (e > 0)
            p2e[p] = e;
    }
    return p2e;
}