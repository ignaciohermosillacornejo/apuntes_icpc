#include "../../../headers/headers.h"

ll mulmod(ull a, ull b, ull c)
{
    ull x = 0, y = a % c;
    while (b)
    {
        if (b & 1)
            x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

ll fastPow(ll x, ll n, ll MOD)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1)
            ret = mulmod(ret, x, MOD);
        x = mulmod(x, x, MOD);
        n >>= 1;
    }
    return ret;
}

bool isPrime(ll n)
{
    vi a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    if (binary_search(a.begin(), a.end(), n))
        return true;

    if ((n & 1) == 0)
        return false;

    int s = 0;
    for (ll m = n - 1; !(m & 1); ++s, m >>= 1)
        ;

    int d = (n - 1) / (1 << s);

    for (int i = 0; i < 7; i++)
    {
        ll fp = fastPow(a[i], d, n);
        bool comp = (fp != 1);
        if (comp)
            for (int j = 0; j < s; j++)
            {
                if (fp == n - 1)
                {
                    comp = false;
                    break;
                }

                fp = mulmod(fp, fp, n);
            }
        if (comp)
            return false;
    }
    return true;
}