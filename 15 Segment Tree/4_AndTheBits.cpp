#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    vector<int> seg;

public:
    SGTree(int n)
    {
        seg.resize(4 * n, -1);
    }

    int buildSGTree(int idx, int low, int high, int a[])
    {
        if (low == high)
        {
            seg[idx] = a[low];
            return seg[idx];
        }
        int mid = (low + high) / 2;
        int left = buildSGTree(2 * idx + 1, low, mid, a);
        int right = buildSGTree(2 * idx + 2, mid + 1, high, a);
        seg[idx] = left & right;
        // cout << seg[idx] << " ";
        return seg[idx];
    }

    int queryProcessing(int idx, int l, int r, int low, int high)
    {
        // NO Overlap
        if (l > high || r < low)
            return 0;
        
        // Full Overlap
        if (low >= l && high <= r)
            return seg[idx];

        // Partial Overlap
        int mid = (low + high) / 2;
        int left = queryProcessing(2 * idx + 1, l, r, low, mid);
        int right = queryProcessing(2 * idx + 2, l, r, mid + 1, high);
        int ans = left & right;
        return seg[idx];
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SGTree sgt(n);
    sgt.buildSGTree(0, 0, n - 1, a);

    int q;
    cin >> n;
    while (q--)
    {

        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int x1 = sgt.queryProcessing(0, l1, r1, 0, n - 1);
        int x2 = sgt.queryProcessing(0, l2, r2, 0, n - 1);
        int ans = x1 ^ x2;
        cout << ans << endl;
    }
    return 0;
}

/*
7
2 5 3 7 1 4 6
3
0 3 1 4
1 2 0 5
1 5 3 6
*/