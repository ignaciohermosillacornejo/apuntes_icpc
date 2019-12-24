#include "../../headers/headers.h"

vector<vector<ii>> DP; //Pair value, op result
int n;                 //Size of DP (i.e. i,j<n)
ii op(ii a, ii b)
{
    return {a.first + b.first + a.second * b.second, (a.second + b.second) % 100}; //Second part MUST be associative, first part is cost function
}

ii MCM(int i, int j)
{
    if (DP[i][j].first != -1)
        return DP[i][j];
    int ans = 1e9; //INF
    int res;
    repx(k, i + 1, j)
    {
        ii temp = op(MCM(i, k), MCM(k, j));
        ans = min(ans, temp.first);
        res = temp.second;
    }
    return DP[i][j] = {ans, res};
}

void fill()
{
    DP.assign(n, vector<ii>(n, {-1, 0}));
    rep(i, n - 1) { DP[i][i + 1].first = 1; } // Pair op identity, cost (cost must be from input)
}