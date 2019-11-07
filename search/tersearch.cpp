#include "../headers/headers.h"

double f(double x)
{
    return -x * x;
}

bool compare(double x, double y) { return f(x) < f(y); }

double maxTer(double start, double end)//Searches maximum of f in range [start, end]
{
    double left = start, right = end;
    double mid1, mid2;
    int reps = 80;
    rep(_, reps)
    {
        mid1 = left + (right - left) / 3, mid2 = right - (right - left) / 3;
        if (compare(mid1, mid2))
            left = mid1;
        else
            right = mid2;
    }
    return (mid1 + mid2) / 2; // * Can return -0!
    // Tends to the right
}

double minTer(double start, double end)//Searches minimum of f in range [start,end]
{
    double left = start, right = end;
    double mid1, mid2;
    int reps = 80;
    rep(_, reps)
    {
        mid1 = left + (right - left) / 3, mid2 = right - (right - left) / 3;
        if (not compare(mid1, mid2))
            left = mid1;
        else
            right = mid2;
    }
    return (mid1 + mid2) / 2;
    // Tends to the left
}
