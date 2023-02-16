#include <iostream>
using namespace std;
void merge(int a[], int l, int mid, int h)
{
    int szLeftArray = mid - l + 1;
    int szRightArray = h - mid;
    int leftArray[szLeftArray], rightArray[szRightArray];

    for (int i = 0; i < szLeftArray; i++)
        leftArray[i] = a[l + i];
    for (int i = 0; i < szRightArray; i++)
        rightArray[i] = a[mid + 1 + i];

    int i = 0; // Pointer of Left Array
    int j = 0; // Pointer of Right Array
    int k = l; // Pointer of Main Array
    while (i < szLeftArray && j < szRightArray)
    {
        if (leftArray[i] < rightArray[j])
        {
            a[k] = leftArray[i];
            i++;
            k++;
        }
        else
        {
            a[k] = rightArray[j];
            j++;
            k++;
        }
    }
    while (i < szLeftArray)
    {
        a[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < szRightArray)
    {
        a[k] = rightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);

        merge(a, l, mid, h);
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
    cout << "Merge Sort " << endl;
    mergeSort(a, 0, n - 1);
    printArray(a, n);
    return 0;
}
