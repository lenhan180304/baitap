#include <iostream>
using namespace std;

int main() {
    int num;
    int sum = 0;

    // Get a positive integer value from the user
    do {
        cout << "Enter a positive integer: ";
        cin >> num;

        if (num <= 0) {
            cout << "Please enter a positive integer." << endl;
        }
    } while (num <= 0);

    // Calculate the sum of numbers from 1 to num
    for (int i = 1; i <= num; i++) {
        sum += i;
    }

    // Display the result
    cout << "The sum of numbers from 1 to " << num << " is: " << sum << endl;

    return 0;
}
