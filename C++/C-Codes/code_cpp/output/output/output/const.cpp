#include <iostream>
using namespace std;

int main()
{
const int a = 7;
int aa = 3;
const int i = 2;
const int* ptr = &i;
int* const ptr2 = &aa;
const int* const ptr3 = &a;
const_cast<int&>(a)=8;



return 0;
}
