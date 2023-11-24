#include <iostream>
#include <string>
#include <vector>

int main() {
    const int SIZE = 10;
    std::vector<std::string> phoneBook = {
        "Alejandra Cruz, 555-1223",
        "Joe Looney, 555-0097",
        "Geri Palmer, 555-8787",
        "Li Chen, 555-1212",
        "Holly Gaddis, 555-8878",
        "Sam Wiggins, 555-0998",
        "Bob Kain, 555-8712",
        "Tim Haynes, 555-7676",
        "Warren Gaddis, 555-9037",
        "Jean James, 555-4939",
        "Ron Palmer, 555-2783"
    };

    // Get user input for name search
    std::string searchName;
    std::cout << "Enter a name or partial name to search for: ";
    std::getline(std::cin, searchName);

    // Display matching entries
    std::cout << "Matching entries:" << std::endl;
    for (const std::string& entry : phoneBook) {
        if (entry.find(searchName) != std::string::npos) {
            std::cout << entry << std::endl;
        }
    }

    return 0;
}
