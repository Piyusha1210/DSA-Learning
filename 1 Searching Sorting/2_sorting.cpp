#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

void insertionSort(int a[], int n)
{
}

void bubbleSort(int a[], int n)
{
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
    cout << "Selection Sort " << endl;
    selectionSort(a, n);
    cout << "Insertion Sort " << endl;
    insertionSort(a, n);
    cout << "Bubble Sort " << endl;
    bubbleSort(a, n);
    return 0;
}