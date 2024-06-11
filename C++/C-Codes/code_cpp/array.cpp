#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    cout << "Enter the limit of array\n";
    int n;
    cin >> n;
    cout << "Enter the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // print doubles of given array
    cout << "The doubles is printed as follows: \n";
    for (int i = 0; i < n; i++)
    {
        cout << 2 * arr[i] << " ";
    }
    return 0;
}
