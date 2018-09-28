#include "../../headers.h"
//Numerical Integration of f in interval [a,b]

double simpsons_rule(function<double(double)> f, double a, double b)
{
    double c = (a + b) / 2;
    double h3 = abs(b - a) / 6;
    return h3 * (f(a) + 4 * f(c) + f(b));
}

double simpsons_rule(function<double(double)> f, double a, double b, int n)
{
    //n sets the precision for the result
    double ans = 0;
    double step = 0, h = (b - a) / n;
    rep(i, n)
    {
        ans += simpsons_rule(f, step, step + h);
        step += h;
    }
    return ans;
}