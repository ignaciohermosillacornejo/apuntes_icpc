#include "../../headers/headers.h"

vector<vector<ll>> DP;
vector<ll> Weights;
vector<ll> Values;

ll Knapsack(int w, int i)
{
    if (w == 0 or i == -1)
        return 0;
    if (DP[w][i] != -1)
        return DP[w][i];
    if (Weights[i] > w)
        return DP[w][i] = Knapsack(w, i - 1);
    return DP[w][i] = max(Values[i] + Knapsack(w - Weights[i], i - 1), Knapsack(w, i - 1));
}