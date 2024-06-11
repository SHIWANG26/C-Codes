#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of columns: ";
    cin >> n;
    
    
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            // Print asterisk
            if (j == i || j == n - 1 - i) {
                cout << "*";
            } else {
                // Print a space otherwise
                cout << " ";
            }
        }
        // Move to the next line after each row
        cout << endl;
    }
    
    return 0;
}