#include "../../headers/headers/headers.h"

// O(n)
umap<int, int> factorialFactorization(int n, vi &primes)
{
    umap<int, int> p2e;
    for (auto p : primes)
    {
        if (p > n)
            break;
        int e = 0;
        int tmp = n;
        while ((tmp /= p) > 0)
            e += tmp;
        if (e > 0)
            p2e[p] = e;
    }
    return p2e;
}