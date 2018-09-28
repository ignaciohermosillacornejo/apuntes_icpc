#include "../../headers.h"

class FenwickTree
{
  private:
    vi ft;

  public:
    FenwickTree(int n)
    {
        ft.assign(n + 1, 0);
    }

    int psq(int b)
    {
        int sum = 0;
        for (; b; b -= (b & -b))
            sum += ft[b];
        return sum;
    }

    int rsq(int a, int b)
    {
        return psq(b) - psq(a - 1);
    }

    void add(int k, int v)
    {
        for (; k < ft.size(); k += (k & -k))
            ft[k] += v;
    }

    void range_add(int i, int j, int v)
    {
        add(i, v);
        add(j + 1, -v);
    }
}