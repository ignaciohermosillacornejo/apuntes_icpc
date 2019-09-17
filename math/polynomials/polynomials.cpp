#include "../../headers/headers.h"

template <class T>
class Pol
{
private:
    vector<T> cofs;
    int n;

public:
    Pol(vector<T> cofs) : cofs(cofs)
    {
        this->n = cofs.size() - 1;
    }

    Pol<T> operator+(const Pol<T> &o)
    {
        vector<T> n_cofs;
        if (n > o.n)
        {
            n_cofs = cofs;
            rep(i, o.n + 1)
            {
                n_cofs[i] += o.cofs[i];
            }
        }
        else
        {
            n_cofs = o.cofs;
            rep(i, n + 1)
            {
                n_cofs[i] += cofs[i];
            }
        }
        return Pol(n_cofs);
    }

    Pol<T> operator-(const Pol<T> &o)
    {
        vector<T> n_cofs;
        if (n > o.n)
        {
            n_cofs = cofs;
            rep(i, o.n + 1)
            {
                n_cofs[i] -= o.cofs[i];
            }
        }
        else
        {
            n_cofs = o.cofs;
            rep(i, n + 1)
            {
                n_cofs[i] *= -1;
                n_cofs[i] += cofs[i];
            }
        }
        return Pol(n_cofs);
    }

    Pol<T> operator*(const Pol<T> &o) //Use Fast Fourier Transform when we implement it
    {
        vector<T> n_cofs(n + o.n + 1);
        rep(i, n + 1)
        {
            rep(j, o.n + 1)
            {
                n_cofs[i + j] += cofs[i] * o.cofs[j];
            }
        }
        return Pol(n_cofs);
    }

    Pol<T> operator*(const T &o)
    {
        vector<T> n_cofs = cofs;
        for (auto &cof : n_cofs)
        {
            cof *= o;
        }
        return Pol(n_cofs);
    }

    double operator()(double x)
    {
        double ans = 0;
        double temp = 1;
        for (auto cof : cofs)
        {
            ans += (double)cof * temp;
            temp *= x;
        }
        return ans;
    }

    Pol<T> integrate()
    {
        vector<T> n_cofs(n + 2);
        repx(i, 1, n_cofs.size())
        {
            n_cofs[i] = cofs[i - 1] / T(i);
        }
        return Pol<T>(n_cofs);
    }

    double integrate(T a, T b)
    {
        Pol<T> temp = integrate();
        return temp(b) - temp(a);
    }

    friend ostream &operator<<(ostream &str, const Pol &a);
};

ostream &operator<<(ostream &strm, const Pol<double> &a)
{
    bool flag = false;
    rep(i, a.n + 1)
    {
        if (a.cofs[i] == 0)
            continue;

        if (flag)
            if (a.cofs[i] > 0)
                strm << " + ";
            else
                strm << " - ";
        else
            flag = true;
        if (i > 1)
        {
            if (abs(a.cofs[i]) != 1)
                strm << abs(a.cofs[i]);
            strm << "x^" << i;
        }
        else if (i == 1)
        {
            if (abs(a.cofs[i]) != 1)
                strm << abs(a.cofs[i]);
            strm << "x";
        }
        else
        {
            strm << a.cofs[i];
        }
    }
    return strm;
}
