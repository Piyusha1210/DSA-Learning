#include <bits/stdc++.h>
using namespace std;
/*https://codeforces.com/problemset/problem/380/C*/
class node
{
public:
    int open;
    int close;
    int full;
    node()
    {
        open = 0;
        close = 0;
        full = 0;
    }
};

class SGTree
{
    vector<node> v;

public:
    SGTree(int n)
    {
        v.resize(4 * n);
    }
    node buildSGTree(int idx, int low, int high, string &s)
    {
        if (low == high)
        {
            if (s[low] == '(')
            {
                v[idx].open = 1;
                return v[idx];
            }
            else
            {
                v[idx].close = 1;
                return v[idx];
            }
        }
        int mid = (low + high) / 2;
        node left = buildSGTree(2 * idx + 1, low, mid, s);
        node right = buildSGTree(2 * idx + 2, mid + 1, high, s);
        int add = min(left.open, right.close);
        v[idx].full = left.full + right.full + add;
        v[idx].open = left.open + right.open - add;
        v[idx].close = left.close + right.close - add;
        return v[idx];
    }

    node queryProcessing(int idx, int low, int high, int l, int r)
    {
        // No overlap
        if (r < low || l > high)
        {
            node t;
            return t;
        }

        // Full Overlap
        if (l <= low && r >= high)
        {
            return v[idx];
        }

        // Partial Overlap
        int mid = (low + high) / 2;
        node left = queryProcessing(2 * idx + 1, low, mid, l, r);
        node right = queryProcessing(2 * idx + 2, mid + 1, high, l, r);
        node t;
        int add = min(left.open, right.close);
        left.open -= add;
        right.close -= add;
        t.full = left.full + right.full + add;
        t.open = left.open + right.open;
        t.close = left.close + right.close;
        return t;
    }
};

int main()
{
    string s;
    cin >> s;
    int n = s.size(), m;
    cin >> m;
    SGTree sgt(n);
    sgt.buildSGTree(0, 0, n - 1, s);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << sgt.queryProcessing(0, 0, n - 1, l - 1, r - 1).full * 2 << endl;
    }
    return 0;
}