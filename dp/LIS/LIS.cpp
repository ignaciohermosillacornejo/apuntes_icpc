#include "../../headers/headers.h"

vi L;
vi vals;

int maxl = 1;

//Bottom up approach O(nlogn)
int lis(int n)
{
    L.assign(n, -1);
    L[0] = vals[0];
    repx(i, 1, n)
    {
        auto it = lower_bound(L.begin(), L.begin() + maxl, vals[i]);
        if (it == L.begin() + maxl)
        {
            L[maxl] = vals[i];
            maxl++;
        }
        else
            *it = vals[i];
    }
    return maxl;
}