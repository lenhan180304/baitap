#include <iostream>
#include <string>

class Employee {
private:
    std::string name;
    int idNumber;
    std::string department;
    std::string position;

public:
    // Constructors
    Employee(std::string empName, int empID, std::string empDept, std::string empPosition);
    Employee(std::string empName, int empID);

    // Default constructor
    Employee();

    // Mutator functions
    void setName(std::string empName);
    void setIdNumber(int empID);
    void setDepartment(std::string empDept);
    void setPosition(std::string empPosition);

    // Accessor functions
    std::string getName() const;
    int getIdNumber() const;
    std::string getDepartment() const;
    std::string getPosition() const;
};

// Constructor with all parameters
Employee::Employee(std::string empName, int empID, std::string empDept, std::string empPosition)
    : name(empName), idNumber(empID), department(empDept), position(empPosition) {}

// Constructor with name and ID only
Employee::Employee(std::string empName, int empID) : name(empName), idNumber(empID), department(""), position("") {}

// Default constructor
Employee::Employee() : name(""), idNumber(0), department(""), position("") {}

// Mutator functions
void Employee::setName(std::string empName) {
    name = empName;
}

void Employee::setIdNumber(int empID) {
    idNumber = empID;
}

void Employee::setDepartment(std::string empDept) {
    department = empDept;
}

void Employee::setPosition(std::string empPosition) {
    position = empPosition;
}

// Accessor functions
std::string Employee::getName() const {
    return name;
}

int Employee::getIdNumber() const {
    return idNumber;
}

std::string Employee::getDepartment() const {
    return department;
}

std::string Employee::getPosition() const {
    return position;
}

int main() {
    // Create three Employee objects
    Employee employee1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee employee2("Mark Jones", 39119, "IT", "Programmer");
    Employee employee3("Joy Rogers", 81774, "Manufacturing", "Engineer");

    // Display data for each employee
    std::cout << "Employee 1:\n";
    std::cout << "Name: " << employee1.getName() << "\nID Number: " << employee1.getIdNumber()
              << "\nDepartment: " << employee1.getDepartment() << "\nPosition: " << employee1.getPosition() << "\n\n";

    std::cout << "Employee 2:\n";
    std::cout << "Name: " << employee2.getName() << "\nID Number: " << employee2.getIdNumber()
              << "\nDepartment: " << employee2.getDepartment() << "\nPosition: " << employee2.getPosition() << "\n\n";

    std::cout << "Employee 3:\n";
    std::cout << "Name: " << employee3.getName() << "\nID Number: " << employee3.getIdNumber()
              << "\nDepartment: " << employee3.getDepartment() << "\nPosition: " << employee3.getPosition() << "\n";

    return 0;
}
