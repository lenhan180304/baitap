#include <iostream>
#include <fstream>
#include <limits> // Include the <limits> header for numeric_limits
using namespace std;

const int NAME_SIZE = 51, ADDR_SIZE = 51, PHONE_SIZE = 14;

struct Info
{
    char name[NAME_SIZE];
    int age;
    char address1[ADDR_SIZE];
    char address2[ADDR_SIZE];
    char phone[PHONE_SIZE];
};

int main()
{
    Info person;
    char again;

    fstream people("people.dat", ios::out | ios::binary);

    do
    {
        cout << "Enter the following data about a person:\n";
        cout << "Name: ";
        cin.getline(person.name, NAME_SIZE);
        cout << "Age: ";
        cin >> person.age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the remaining characters, up to '\n'
        cout << "Address line 1: ";
        cin.getline(person.address1, ADDR_SIZE);
        cout << "Address line 2: ";
        cin.getline(person.address2, ADDR_SIZE);
        cout << "Phone: ";
        cin.getline(person.phone, PHONE_SIZE);

        people.write(reinterpret_cast<char *>(&person), sizeof(person));

        cout << "Do you want to enter another record? ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the remaining characters, up to '\n'

    } while (again == 'Y' || again == 'y');

    people.close();
    return 0;
}
