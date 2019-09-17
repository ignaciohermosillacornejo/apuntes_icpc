#include "../../../headers/headers.h"

// O(sqrt(n)/log(sqrt(n))+log(n))
vi trialDivision(int n, vi &primes)
{
    vi factors;
    for (auto p : primes)
    {
        if (p * p > n)
            break;
        while (n % p == 0)
        {
            primes.pb(p);
            if ((n /= p) == 1)
                return factors;
        }
    }
    if (n > 1)
        factors.pb(n);

    return factors;
}