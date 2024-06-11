#include <iostream>

using namespace std;

int main()
{
// char *ptr ;
// int i;
// char arr[20];
// char Str[] = "abcdefg";
// ptr = Str;
// ptr += 5;
// cout << ptr << endl;
// for (i = 0; i<10; i++)
// {
//     *(arr + i) = 65 +i;
// }
// *(arr+i) = '\0';
// cout << arr;
int n[5];
int *p;
p = n;
*p = 10;
p = &n[2];
*p = 20;
p--;
*p= 30;
p = n +3;
*p = 40;
p = n;
*(p+4)=50;
for (int i = 0; i < 5 ;i++)
{
    cout<<n[i]<<endl;
}

return 0;
}
