#include "../headers/headers.h"
int val;
vi vals;
bool discreteP(int x) { return vals[x] > val; }

int lowerBound(int start, int end, int val) //Searches for the least value x such that discreteP(x) is true
{
    int left = start, right = end;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (discreteP(mid))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int upperBound(int start, int end, int val) //Searches for the greatest value x such that discreteP(x) is false
{
    int left = start, right = end;
    while (left < right)
    {
        int mid = left + (right - left + 1) / 2;
        if (discreteP(mid))
            right = mid - 1;
        else
            left = mid;
    }
    return left;
}

double approx;
bool continuousP(double x) { return x > approx; }

double bin(double start, double end)
{
    double left = start, right = end;
    int reps = 80; //Safe numbers check if viable for problem
    double mid;
    rep(_, reps)
    {
        mid = (left + right) / 2;
        if (continuousP(mid))
            right = mid;
        else
            left = mid;
    }
    return mid;
}