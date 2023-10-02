#include <iostream>
using namespace std;

int main()
{
    // Define an array of integers.
    int numbers[] = { 10, 20, 30, 40, 50 };

    // Display the values in the array using a range-based for loop.
    for (int val : numbers)
        cout << val << endl;

    return 0;
}
