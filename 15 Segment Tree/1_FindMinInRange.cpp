#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    vector<int> seg;
public:
    SGTree(int n)
    {
        seg.resize(4 * n);
    }

    int buildSegmentTree(int idx, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return seg[idx];
        }
        int mid = (low + high) / 2;
        int left = buildSegmentTree(2 * idx + 1, low, mid, arr);
        int right = buildSegmentTree(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = min(left, right);
        return seg[idx];
    }

    int queryProcessing(int idx, int l, int r, int low, int high)
    {
        // Full Overlap
        if (l <= low && r >= high)
            return seg[idx];

        // No Overlap
        if (l > high || r < low)
            return INT_MAX;

        // Partial Overlap
        int mid = (low + high) / 2;
        int left = queryProcessing(2 * idx + 1, l, r, low, mid);
        int right = queryProcessing(2 * idx + 2, l, r, mid + 1, high);
        return min(left, right);
    }

    void updateSegmentTree(int idx, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            updateSegmentTree(2 * idx + 1, low, mid, i, val);
        else
            updateSegmentTree(2 * idx + 2, mid + 1, high, i, val);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
        return;
    }
};

int main()
{
    int n;
    cin >> n;
    SGTree sgt2(n);
    SGTree sgt1(n);
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sgt1.buildSegmentTree(0, 0, n - 1, arr);
    cout << "Enter query - ";
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sgt1.queryProcessing(0, l, r, 0, n - 1) << endl;
    }
    cout << "Update Value - ";
    int idx, v;
    cin >> idx >> v;
    sgt1.updateSegmentTree(0, 0, n - 1, idx, v);
    cout << "Enter query - ";
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sgt1.queryProcessing(0, l, r, 0, n - 1) << endl;
    }
    return 0;
}

/*
7
4 2 8 9 3 5 1
3
0 3
2 4
1 6
1 5
3
0 4
1 5
3 6
*/