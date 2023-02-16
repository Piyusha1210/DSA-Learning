#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h)
{
    int pivot = a[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[h]);
    return i+1;
}
void quickSort(int a[], int l, int h)
{
    if (l < h)
    {
        int pos = partition(a, l, h);
        quickSort(a, l, pos - 1);
        quickSort(a, pos + 1, h);
    }
    return;
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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
    cout << "Quick Sort " << endl;
    quickSort(a, 0, n - 1);
    printArray(a, n);

    return 0;
}