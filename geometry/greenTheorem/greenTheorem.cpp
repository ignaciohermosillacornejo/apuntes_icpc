#include "../../headers/headers.h"
// Line integrals for calculating areas with green's theorem 
struct Point { double x, y; };

double arc_integral(double x, double r, double a, double b)
{
    return x * r * (sin(b) - sin(a)) + r * r * 0.5 * (0.5 * (sin(2 * b) - sin(2 * a)) + b - a);
}

double segment_integral(Point &a, Point &b)
{
    return 0.5 * (a.x + b.x) * (b.y - a.y);
}