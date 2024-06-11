#include <iostream>
using namespace std;

void sort012(int arr[], int arr_size){
    int lo = 0;
    int hi = arr_size -1;
    int mid = 0;
    //Iterate till all elements are sorted
    while (mid<=hi)
    {
        switch (arr[mid])
        {
        case 0: 
            swap(arr[lo++],arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[hi--]);
            break;
        }
    }
    
}

void print_arr(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i]<<" ";
    }
    
}
int main()
{
int arr[] = {0,1,2,1,2,0,1,0,1,0,2};
int n = sizeof(arr)/sizeof(int);
sort012(arr,n);
print_arr(arr,n);
return 0;
}
