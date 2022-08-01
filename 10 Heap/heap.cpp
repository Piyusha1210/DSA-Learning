#include <bits/stdc++.h>
using namespace std;

class Heap
{
private:
    int a[100];
    int size = 0;

public:
    void insert(int n)
    {
        size = size + 1;
        int idx = size;
        a[idx] = n;

        while (idx > 1)
        {
            if (a[idx] > a[idx / 2])
            {
                swap(a[idx], a[idx / 2]);
                idx = idx / 2;
            }
            else
                return;
        }
    }

    void deleteRoot()
    {
        a[1] = a[size];
        size--;
        int idx = 1;
        while (idx < size)
        {
            if (idx * 2 <= size && a[idx] < a[idx * 2])
            {
                swap(a[idx], a[idx * 2]);
                idx *= 2;
            }
            else if (idx * 2 + 1 <= size && a[idx] < a[idx * 2 + 1])
            {
                swap(a[idx], a[idx * 2 + 1]);
                idx *= 2;
                idx += 1;
            }
            else
                return;
        }
    }

    void printHeap()
    {
        for (int i = 1; i <= size; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};

void heapify(int *arr, int size, int i)
{
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;

    if (left <= size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= size && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
        return;
    }
    return;
}

void heapSort(int *arr, int size)
{
    for (int i = size; i > 1; i--)
    {
        swap(arr[i], arr[1]);
        heapify(arr, i-1, 1);
    }
    return;
}

int main()
{
    Heap h;
    h.insert(50);
    h.insert(52);
    h.insert(53);
    h.printHeap();
    h.insert(56);
    h.insert(40);
    h.printHeap();
    h.deleteRoot();
    h.printHeap();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2 + 1; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 1; i <= n; i++)
        cout<<arr[i]<<" ";;
    cout<<endl;

    heapSort(arr, 5);
    for (int i = 1; i <= n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}