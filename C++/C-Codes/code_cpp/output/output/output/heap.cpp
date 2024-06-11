#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}
void deleteRoot(int arr[], int &n)
{
    int last_element = arr[n - 1];
    arr[0] = last_element;
    n = n - 1;
    heapify(arr, n, 0);
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {10, 2, 33, 100, 20, 33, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    deleteRoot(arr, n);
    printArr(arr, n);
    return 0;
}
