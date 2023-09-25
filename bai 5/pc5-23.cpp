#include <iostream>
using namespace std;

int main() {
    int rows;

    cout << "Enter the number of rows: ";
    cin >> rows;

    // Pattern A
    cout << "Pattern A:" << endl;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "+";
        }
        cout << endl;
    }

    // Pattern B
    cout << "Pattern B:" << endl;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "+";
        }
        cout << endl;
    }

    return 0;
}
