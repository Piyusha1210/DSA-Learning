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

    int buildSegmentTree(int idx, int low, int high, int height, int arr[])
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return seg[idx];
        }
        int mid = (low + high) / 2;
        int left = buildSegmentTree(2 * idx + 1, low, mid, height + 1, arr);
        int right = buildSegmentTree(2 * idx + 2, mid + 1, high, height + 1, arr);

        if (height % 2 == 0)
            seg[idx] = left | right;
        else
            seg[idx] = left ^ right;

        return seg[idx];
    }

    int updateSegmentTree(int idx, int low, int high, int i, int val, int height)
    {
        if (low == high)
        {
            seg[idx] = val;
            return seg[idx];
        }
        int mid = (low + high) / 2;
        int left = seg[2 * idx + 1];
        int right = seg[2 * idx + 2];
        if (i <= mid)
            left = updateSegmentTree(2 * idx + 1, low, mid, i, val, height + 1);
        else
            right = updateSegmentTree(2 * idx + 2, mid + 1, high, i, val, height + 1);

        if (height % 2 == 0)
            seg[idx] = left | right;
        else
            seg[idx] = left ^ right;
        return seg[idx];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int height = 0;
    if (n % 2 == 0)
        height = 1;
    n = pow(2, n);
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SGTree sgt1(n);
    sgt1.buildSegmentTree(0, 0, n - 1, height, arr);
    while (m--)
    {
        int p, b;
        cin >> p >> b;
        cout << sgt1.updateSegmentTree(0, 0, n - 1, p - 1, b, height) << endl;
    }
    return 0;
}
/*
2 4
1 6 3 5
1 4
3 4
1 2
1 2
*/