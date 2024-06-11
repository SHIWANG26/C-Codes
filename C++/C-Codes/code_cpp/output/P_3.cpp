#include <iostream>
using namespace std;

static void car(int arr[] ) {
    arr[0] = arr[0] + 1;

}

int main()
{
int arr[] = {1,2,3 ,4,5};
car(arr);
for(int i = 0; i < 5; i++) 
cout<<arr[i];
return 0;
}
