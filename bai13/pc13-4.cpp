#include <iostream>
#include <string>

class PersonalInformation {
private:
    std::string name;
    std::string address;
    int age;
    std::string phoneNumber;

public:
    // Constructor
    PersonalInformation(const std::string& newName, const std::string& newAddress, int newAge, const std::string& newPhoneNumber);

    // Accessor functions
    std::string getName() const;
    std::string getAddress() const;
    int getAge() const;
    std::string getPhoneNumber() const;

    // Mutator functions
    void setName(const std::string& newName);
    void setAddress(const std::string& newAddress);
    void setAge(int newAge);
    void setPhoneNumber(const std::string& newPhoneNumber);
};

// Constructor
PersonalInformation::PersonalInformation(const std::string& newName, const std::string& newAddress, int newAge, const std::string& newPhoneNumber)
    : name(newName), address(newAddress), age(newAge), phoneNumber(newPhoneNumber) {}

// Accessor functions
std::string PersonalInformation::getName() const {
    return name;
}

std::string PersonalInformation::getAddress() const {
    return address;
}

int PersonalInformation::getAge() const {
    return age;
}

std::string PersonalInformation::getPhoneNumber() const {
    return phoneNumber;
}

// Mutator functions
void PersonalInformation::setName(const std::string& newName) {
    name = newName;
}

void PersonalInformation::setAddress(const std::string& newAddress) {
    address = newAddress;
}

void PersonalInformation::setAge(int newAge) {
    age = newAge;
}

void PersonalInformation::setPhoneNumber(const std::string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

int main() {
    // Create instances of PersonalInformation
    PersonalInformation myInfo("Your Name", "Your Address", 25, "Your Phone Number");
    PersonalInformation friend1("Friend 1", "Friend 1 Address", 30, "Friend 1 Phone Number");
    PersonalInformation friend2("Friend 2", "Friend 2 Address", 28, "Friend 2 Phone Number");

    // Display information
    std::cout << "Your Information:\n";
    std::cout << "Name: " << myInfo.getName() << "\nAddress: " << myInfo.getAddress()
              << "\nAge: " << myInfo.getAge() << "\nPhone Number: " << myInfo.getPhoneNumber() << "\n\n";

    std::cout << "Friend 1's Information:\n";
    std::cout << "Name: " << friend1.getName() << "\nAddress: " << friend1.getAddress()
              << "\nAge: " << friend1.getAge() << "\nPhone Number: " << friend1.getPhoneNumber() << "\n\n";

    std::cout << "Friend 2's Information:\n";
    std::cout << "Name: " << friend2.getName() << "\nAddress: " << friend2.getAddress()
              << "\nAge: " << friend2.getAge() << "\nPhone Number: " << friend2.getPhoneNumber() << "\n";

    return 0;
}
