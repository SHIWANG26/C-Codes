#include <iostream>
using namespace std;
int main()
{
    cout << "Enter a number please!" << endl;
    int n;
    bool is_prime = true;
    cin >> n;
    if (n == 0 || n == 1)
    {
        is_prime = false;
    }

    for (int i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            is_prime = false;
            break;
        }
    }
    if (is_prime)
    {
        cout << n << " is a prime number." << endl;
    }
    else
    {
        cout << n << " is not a prime number.";
    }

    return 0;
}