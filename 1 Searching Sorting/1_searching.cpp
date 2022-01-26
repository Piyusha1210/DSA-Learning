#include <bits/stdc++.h>
using namespace std;

int linearSearch(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int a[], int n, int key)
{
    int l = 0, r = n - 1, mid;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;
    cout << "Linear Search " << linearSearch(a, n, key) << endl;
    cout << "Binary Search " << binarySearch(a, n, key) << endl;
    return 0;
}
