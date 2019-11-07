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
        int left = 0, right = maxl - 1, mid;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (vals[i] > L[mid])
                left = mid;
            else
                right = mid;
        }
        mid = (left + right) / 2;
        if (mid == maxl - 1)
        {
            L[maxl] = vals[i];
            maxl++;
        }
        else
            L[mid] = vals[i];
    }
    return maxl;
}