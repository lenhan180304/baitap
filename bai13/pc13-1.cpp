#include <iostream>
#include <string>

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y);
    void printDate1() const;  // Format: 12/25/2014
    void printDate2() const;  // Format: December 25, 2014
    void printDate3() const;  // Format: 25 December 2014
};

Date::Date(int m, int d, int y) {
    // Input validation
    if (m < 1 || m > 12 || d < 1 || d > 31 || y < 1) {
        std::cerr << "Error: Invalid date input.\n";
        exit(EXIT_FAILURE);
    }

    month = m;
    day = d;
    year = y;
}

void Date::printDate1() const {
    std::cout << month << '/' << day << '/' << year << std::endl;
}

void Date::printDate2() const {
    static const std::string monthNames[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    std::cout << monthNames[month - 1] << ' ' << day << ", " << year << std::endl;
}

void Date::printDate3() const {
    static const std::string monthNames[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    std::cout << day << ' ' << monthNames[month - 1] << ' ' << year << std::endl;
}

int main() {
    int month, day, year;

    // Get input for the date
    std::cout << "Enter month (1-12): ";
    std::cin >> month;

    std::cout << "Enter day (1-31): ";
    std::cin >> day;

    std::cout << "Enter year: ";
    std::cin >> year;

    // Create a Date object
    Date myDate(month, day, year);

    // Print the date in different formats
    myDate.printDate1();
    myDate.printDate2();
    myDate.printDate3();

    return 0;
}
