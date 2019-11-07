#include "../../headers/headers.h"

const int MAXLEN = 1e6;

class rollingHashing
{
    static const ull base = 127;
    static const vector<ull> primes;
    static vector<vector<ull>> POW;

    static ull add(ull x, ull y, int a) { return (x + y) % primes[a]; }
    static ull mul(ull x, ull y, int a) { return (x * y) % primes[a]; }

    static void init(int a)
    {
        if (POW.size() <= a + 1)
        {
            POW.eb(MAXLEN, 1);
        }
        repx(i, 1, MAXLEN) POW[a][i] = mul(POW[a][i], base, a);
    }

    static void init()
    {
        rep(i, primes.size()) init(i);
    }

    vector<vector<ull>> h;
    int len;
    rollingHashing(string &s)
    {
        len = s.size();
        h.assign(primes.size(), vector<ull>(len, 0));
        rep(a, primes.size())
        {
            h[a][0] = s[0] - 'a'; //Assuming alphabetic alphabet
            repx(i, 1, len) h[a][i] = add(s[i] - 'a', mul(h[a][i - 1], base, a), a);
        }
    }

    ull hash(int i, int j, int a) //Inclusive-Exclusive [i,i)?
    {
        if (i == 0)
            return h[a][j - 1];
        return add(h[a][j - 1], primes[a] - mul(h[a][i - 1], POW[a][j - i], a), a);
    }

    ull hash(int i, int j)//Supports at most two primes
    {
        return hash(i, j, 1) << 32 | hash(i, j, 0);//Using that 1e18<__LONG_LONG_MAX__
    }

    ull hash() { return hash(0, len); }//Also supports at most two primes
};

const vector<ull> rollingHashing ::primes({(ull)1e9 + 7, (ull)1e9 + 9}); //Add more if needed
