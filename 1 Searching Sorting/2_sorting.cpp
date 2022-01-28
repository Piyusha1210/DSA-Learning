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

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
            }
        }
    }
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int t = a[i];
        while (t < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        j++;
        a[j] = t;
    }
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
    // cout << "Selection Sort " << endl;
    // selectionSort(a, n);
    // printArray(a,n);

    // cout << "Bubble Sort " << endl;
    // bubbleSort(a, n);
    // printArray(a, n);

    // cout << "Insertion Sort " << endl;
    // insertionSort(a, n);
    // printArray(a, n);

    return 0;
}