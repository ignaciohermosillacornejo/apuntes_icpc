#include "../../headers/headers.h"

// It requires a struct for a node (e.g. prodsgn)
// A node must have three constructors
//      Arity 0: Constructs the identity of the operation (e.g. 1 for prodsgn)
//      Arity 1: Constructs a leaf node from the input
//      Arity 2: Constructs a node from its children
//
// Building the Segment Tree:
//      Create a vector of nodes (use constructor of arity 1).
//      ST<miStructNode> mySegmentTree(vectorOfNodes);
// Update:
//      mySegmentTree.set_points(index, myStructNode(input));
// Query:
//      mySegmentTree.query(l, r); (It searches on the range [l,r), and returns a node.)

// Logic And Query
struct ANDQ
{
    ll value;
    ANDQ() { value = -1ll; }
    ANDQ(ll x) { value = x; }
    ANDQ(const ANDQ &a,
         const ANDQ &b)
    {
        value = a.value & b.value;
    }
};

// Interval Product (LiveArchive)
struct prodsgn
{
    int sgn;
    prodsgn() { sgn = 1; }
    prodsgn(int x)
    {
        sgn = (x > 0) - (x < 0);
    }
    prodsgn(const prodsgn &a,
            const prodsgn &b)
    {
        sgn = a.sgn * b.sgn;
    }
};

// Maximum Sum (SPOJ)
struct maxsum
{
    int first, second;
    maxsum() { first = second = -1; }
    maxsum(int x)
    {
        first = x;
        second = -1;
    }
    maxsum(const maxsum &a,
           const maxsum &b)
    {
        if (a.first > b.first)
        {
            first = a.first;
            second = max(a.second,
                         b.first);
        }
        else
        {
            first = b.first;
            second = max(a.first,
                         b.second);
        }
    }
    int answer()
    {
        return first + second;
    }
};

// Range Minimum Query
struct rminq
{
    int value;
    rminq() { value = INT_MAX; }
    rminq(int x) { value = x; }
    rminq(const rminq &a,
          const rminq &b)
    {
        value = min(a.value,
                    b.value);
    }
};

template <class node>
class ST
{
    vector<node> t;
    int n;

public:
    ST(vector<node> &arr)
    {
        n = arr.size();
        t.resize(n * 2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i)
            t[i] = node(t[i << 1], t[i << 1 | 1]);
    }

    // 0-indexed
    void set_point(int p, const node &value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = node(t[p], t[p ^ 1]);
    }

    // inclusive exclusive, 0-indexed
    node query(int l, int r)
    {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ansl = node(ansl, t[l++]);
            if (r & 1)
                ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};