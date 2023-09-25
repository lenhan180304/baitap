#include <iostream>
using namespace std;

int main()
{
    int books;
    int months;
    double perMonth;
    
    cout << "How many books do you paln to read? ";
    cin >> books;
    cout << "How many mouths will it take you to read them? ";
    cin >> months;
    perMonth = static_cast<double>(books) / months;
    cout << "That is " << perMonth << " books per month.\n";
    return 0;
}