#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int SIZE = 30;

    char firstName[SIZE];
    char middleName[SIZE];
    char lastName[SIZE];
    char arrangedName[SIZE * 3 + 3]; // The size of three names plus two spaces and a comma

    // Get the user's first name
    cout << "Enter your first name: ";
    cin.getline(firstName, SIZE);

    // Get the user's middle name
    cout << "Enter your middle name: ";
    cin.getline(middleName, SIZE);

    // Get the user's last name
    cout << "Enter your last name: ";
    cin.getline(lastName, SIZE);

    // Arrange the names in the specified format
    strcpy(arrangedName, lastName);
    strcat(arrangedName, ", ");
    strcat(arrangedName, firstName);
    strcat(arrangedName, " ");
    strcat(arrangedName, middleName);

    // Display the arranged name
    cout << "Arranged Name: " << arrangedName << endl;

    return 0;
}
