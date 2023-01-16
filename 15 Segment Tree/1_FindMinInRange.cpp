#include <bits/stdc++.h>
using namespace std;

int buildSegmentTree(int idx, int low, int high, int arr[], int seg[])
{
    if (low == high)
    {
        seg[idx] = arr[low];
        return seg[idx];
    }
    int mid = (low + high) / 2;
    int left = buildSegmentTree(2 * idx + 1, low, mid, arr, seg);
    int right = buildSegmentTree(2 * idx + 2, mid + 1, high, arr, seg);
    seg[idx] = min(left, right);
    return seg[idx];
}

int queryProcessing(int l, int r)
{

}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int seg[4 * n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    buildSegmentTree(0, 0, n - 1, arr, seg);

    return 0;
}