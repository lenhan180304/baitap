#include <iostream>

bool is_leap_year(int year) {
    if (year % 100 == 0) {
        return year % 400 == 0;
    } else {
        return year % 4 == 0;
    }
}

int get_days_in_month(int month, int year) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && is_leap_year(year)) {
        return 29;
    } else {
        return days_in_month[month - 1];
    }
}

int main() {
    int month, year;
    std::cout << "Enter a month (1-12): ";
    std::cin >> month;
    std::cout << "Enter a year: ";
    std::cin >> year;

    int days = get_days_in_month(month, year);
    std::cout << days << " days" << std::endl;

    return 0;
}
