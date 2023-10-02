#include <iostream>
using namespace std;

void displayNumbersGreaterThanN(int arr[], int size, int n) {
    cout << "Numbers greater than " << n << " in the array are: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] > n) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE] = {12, 5, 20, 8, 15, 30, 7, 25, 18, 10};
    int n;

    cout << "Enter a number (n): ";
    cin >> n;

    displayNumbersGreaterThanN(numbers, ARRAY_SIZE, n);

    return 0;
}
