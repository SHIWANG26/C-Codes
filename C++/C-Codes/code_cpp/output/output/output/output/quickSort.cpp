#include <iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l -1;
    for (int j = l; j < r; j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            swap(arr, i, j);
        }

    }
    swap(arr, i+1, r);
        return i+1;
}

void quickSort(int arr[], int l , int r){
    if (l<r)
    {
        int piv = partition(arr, l , r);
        quickSort(arr, l, piv -1);
        quickSort(arr, piv +1, r);
    }
    
}
int main()
{
    int arr[] = {2,4,6,67,8,1,9};
    int r = sizeof(arr)/sizeof(arr[0]) -1;
    quickSort(arr,0,r);
    for (int i = 0; i < r; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<< endl;
return 0;
}
